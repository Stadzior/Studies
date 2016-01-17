package com.company;
import java.util.ArrayList;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.ReentrantLock;

class deadlockThread extends Thread {
    private String threadName;
    private ArrayList<ReentrantLock> Locks;

    public deadlockThread(ArrayList<ReentrantLock> ListOfLocks){
        threadName = this.getName();
        Locks = ListOfLocks;
    }
    public void run() {
        try {
            if(Locks.get(0).tryLock(10, TimeUnit.SECONDS)) {
                System.out.println(threadName + ": Holding "+Locks.get(0).toString());
                try {
                    Thread.sleep(10);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                System.out.println(threadName + ": Waiting for "+Locks.get(1).toString());
                    if (Locks.get(1).tryLock(10, TimeUnit.SECONDS)) {
                        System.out.println(threadName + ": Holding both locks...");
                        if(Locks.get(1).isLocked()) {
                            Locks.get(1).unlock();
                            System.out.println(threadName + ": Released "+Locks.get(1).toString());
                        }
                    }
                if(Locks.get(0).isLocked()) {
                    Locks.get(0).unlock();
                    System.out.println(threadName + ": Released "+Locks.get(0).toString());
                }
                }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class livelockThread extends Thread {
    private String threadName;
    private ArrayList<ReentrantLock> Locks;

    public livelockThread(ArrayList<ReentrantLock> ListOfLocks){
        threadName = this.getName();
        Locks = ListOfLocks;
    }

    private void acquire(ReentrantLock LockToAcquire, ReentrantLock LockToRelease,Integer indentLevel){
        if(LockToAcquire.tryLock()){
            System.out.println(threadName+": Holding "+ LockToAcquire.toString());
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            if(indentLevel<10) {
                acquire(LockToRelease, LockToAcquire, indentLevel + 1);
            }

        }
        else
        {
            System.out.println(threadName+": Can't acquire "+LockToAcquire.toString());
            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            if(LockToRelease.isLocked() && LockToRelease.isHeldByCurrentThread()) {
                System.out.println(threadName+": Realising "+ LockToRelease.toString());
                LockToRelease.unlock();
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            if(indentLevel<10) {
                acquire(LockToAcquire, LockToRelease,indentLevel+1);
            }
            else
            {
                if(LockToAcquire.isLocked() && LockToAcquire.isHeldByCurrentThread()){
                    LockToAcquire.unlock();
                }
                if(LockToRelease.isLocked() && LockToRelease.isHeldByCurrentThread()){
                    LockToRelease.unlock();
                }
            }
        }
    }

    public void run() {
        acquire(Locks.get(0), Locks.get(1),0);
    }
}

class readerThread extends Thread {
    private String threadName = "Reader-"+getName();
    private ReentrantLock lock;
    public readerThread(ReentrantLock Lock){
        lock = Lock;
    }

    private void acquire(int indentLevel){
        try {
            if(lock.tryLock(1,TimeUnit.SECONDS)){
                System.out.println(threadName + ": Holding resource.");
                Thread.sleep(10);
                if(lock.isLocked() && lock.isHeldByCurrentThread()) {
                    lock.unlock();
                    Thread.sleep(10);
                    if(indentLevel<30) {
                        acquire(indentLevel + 1);
                    }
                }
            }
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }

    public void run() {
        acquire(0);
    }
}

class writerThread extends Thread {
    private String threadName = "Writer-"+getName();
    private ReentrantLock lock;
    public writerThread(ReentrantLock Lock){
        lock = Lock;
    }
    private void acquire(Integer indentLevel){
            if(lock.tryLock()){
                System.out.println(threadName + ": Holding resource.");
                if(lock.isLocked() && lock.isHeldByCurrentThread()) {
                    lock.unlock();
                }
            }
            else{
                try {
                    Thread.sleep(100);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
                if(indentLevel<10) {
                    acquire(indentLevel + 1);
                }
            }
    }

    public void run() {
        acquire(0);
    }
}

public class Main {

    public static ArrayList<ReentrantLock> ListOfLocks = new ArrayList<ReentrantLock>();
    public static ArrayList<ReentrantLock> ReversedListOfLocks = new ArrayList<ReentrantLock>();

    private static void simulateDeadlock(){
        ReentrantLock Lock1 = new ReentrantLock();
        ReentrantLock Lock2 = new ReentrantLock();
        ListOfLocks.add(0,Lock1);
        ListOfLocks.add(1,Lock2);
        ReversedListOfLocks.add(0,Lock2);
        ReversedListOfLocks.add(1,Lock1);
        deadlockThread Thread1 = new deadlockThread(ListOfLocks);
        deadlockThread Thread2 = new deadlockThread(ReversedListOfLocks);
        Thread1.start();
        Thread2.start();
    }

    private static void simulateLivelock(){
        ReentrantLock Lock1 = new ReentrantLock();
        ReentrantLock Lock2 = new ReentrantLock();
        ListOfLocks.add(0,Lock1);
        ListOfLocks.add(1,Lock2);
        ReversedListOfLocks.add(0,Lock2);
        ReversedListOfLocks.add(1,Lock1);
        livelockThread Thread1 = new livelockThread(ListOfLocks);
        livelockThread Thread2 = new livelockThread(ReversedListOfLocks);
        Thread1.start();
        Thread2.start();
    }
    private static void simulateStarvation(){
        ReentrantLock Lock = new ReentrantLock();
        writerThread writer = new writerThread(Lock);

        for (int i = 0; i < 30; i++) {
            readerThread reader = new readerThread(Lock);
            reader.start();
        }
        writer.start();



    }

    public static void main(String[] args) {

        switch (Integer.parseInt(args[0])){
            case 1:
                simulateDeadlock();
                break;
            case 2:
                simulateLivelock();
                break;
            case 3:
                simulateStarvation();
                break;

        }
    }
}

