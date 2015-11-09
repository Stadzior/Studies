import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;
import java.sql.Time;

public class Main {

    public static void main(String[] args) {
        try {
            String Url = args[0];
            String HostName = Url.substring(Url.indexOf(":")+3,Url.length());
            InetAddress HostAddress = InetAddress.getByName(HostName);
            Socket httpSocket = new Socket(HostAddress, 80);
            double timeElapsed = System.currentTimeMillis();
            PrintWriter pw = new PrintWriter(httpSocket.getOutputStream());
            pw.print("GET / HTTP/1.0\r\n");
            pw.print("Host: www."+HostName+"\r\n");
            pw.print("\r\n");
            pw.flush();
            timeElapsed = System.currentTimeMillis() - timeElapsed;
            String RemoteAddress = httpSocket.getRemoteSocketAddress().toString();
            Integer LocalTCPPort = httpSocket.getLocalPort();
            Integer SizeOfReply = httpSocket.getReceiveBufferSize();
            System.out.println("Remote address: "+RemoteAddress);
            System.out.println("Local TCP port: "+LocalTCPPort);
            System.out.println("Size of reply: "+SizeOfReply);
            System.out.println("Time elapsed: "+timeElapsed);
        }
        catch (Exception e){
            System.out.println(e.getMessage());
        }
    }
}