package com.company;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

class CountingThread implements Runnable {
    private Thread myThread;
    private String Filename;

    public  CountingThread (String filename)
    {
        Filename = filename;
    }
    public void run() {
        Main.countLines(Filename);
        }
public void start(){
    if (myThread == null)
    {
        myThread = new Thread (this);
        myThread.start();
    }
}
}

public class Main {
    public static int countLines(String filename){
        try{
        BufferedReader reader = new BufferedReader(new FileReader(filename));
        int linesCount = 0;
        while (reader.readLine() != null) linesCount++;
        reader.close();
            return linesCount;
    } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return 0;
    }

    public static void main(String[] args) {

            long tic = System.currentTimeMillis();

            for (String filename : args){
                new CountingThread(filename).start();
            }

            long toc = System.currentTimeMillis();

            long elapsedMilis = toc - tic;

        System.out.println("Multithread approach (ms):");
        System.out.println(elapsedMilis);

        tic = System.currentTimeMillis();

        for(String filename : args) {
            countLines(filename);
        }

        toc = System.currentTimeMillis();

        elapsedMilis = toc - tic;

        System.out.println("Sequential approach (ms):");
        System.out.println(elapsedMilis);
        }
}
