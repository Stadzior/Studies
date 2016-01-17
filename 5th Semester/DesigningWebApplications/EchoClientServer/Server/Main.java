
import java.net.*;
import java.io.*;
import java.util.ArrayList;
import java.util.concurrent.TimeUnit;
import java.util.concurrent.locks.ReentrantLock;

class serverThread extends Thread {
    Socket clientSocket;
    String clientName;
    public serverThread(String Name,Socket acceptedSocket){
        clientSocket = acceptedSocket;
        clientName = Name;
    }
    public void run() {
        try {
            System.out.println(clientName+" connected.");
            clientSocket.setSoTimeout(60000);
            PrintWriter out = new PrintWriter(clientSocket.getOutputStream(), true);
            BufferedReader in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
            String inputLine;
            while ((inputLine = in.readLine()) != null) {
                System.out.println(clientName+" "+inputLine);
                out.println("Reply: " + inputLine);
            }
            System.out.println(clientName+" disconnected.");
        } catch (SocketTimeoutException e)
        {
            System.out.println("Disconnected due to server timeout.");
        }
         catch (IOException e) {
            e.printStackTrace();
        }
    }
}

public class Main {
    public static void main(String[] args) throws IOException {

        int portNumber;
        if (args.length<1) {
            portNumber = 666; //Free port for 99% sure.
        }
        else {
            portNumber = Integer.parseInt(args[0]);
        }
        try {
            ServerSocket serverSocket = new ServerSocket(portNumber);
            int clientCount = 0;
            while (true) {
                    new serverThread("Client No."+clientCount,serverSocket.accept()).start();
                    clientCount++;
            }
        }
        catch (IOException e) {
            System.out.println("Exception caught when trying to listen on port "
                    + portNumber + " or listening for a connection");
            System.out.println(e.getMessage());
        }
    }
}
