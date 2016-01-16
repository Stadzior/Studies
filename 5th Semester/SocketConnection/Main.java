import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.InetAddress;
import java.net.Socket;
import java.net.URL;

public class Main {

    public static void main(String[] args) {
        try {
            URL Url = new URL(args[0]);
            String HostName = Url.getHost() +Url.getPath();
            InetAddress HostAddress = InetAddress.getByName(HostName);
            Integer Port = Url.getPort() == -1 ? Url.getDefaultPort() : Url.getPort();
            Socket httpSocket = new Socket(HostAddress,Port);
            double timeElapsed = System.currentTimeMillis();
            PrintWriter pw = new PrintWriter(httpSocket.getOutputStream());
            pw.print("GET / HTTP/1.0\r\n");
            pw.print("Host: www."+HostName+"\r\n");
            pw.print("\r\n");
            pw.flush();
            timeElapsed = System.currentTimeMillis() - timeElapsed;
            StringBuilder out = new StringBuilder();
            BufferedReader br = new BufferedReader(new InputStreamReader(httpSocket.getInputStream()));
            String line;
            if((line = br.readLine()) != null && (line.contains("200"))) {
                Integer SizeOfReply = 0;
                while ((line = br.readLine()) != null && line.length() > 0) {

                    if(line.contains("Content-Length")) {
                        SizeOfReply = Integer.parseInt(line.substring(line.indexOf(":")+1).trim());
                    }
                }
                while((line = br.readLine()) != null) {
                    out.append(line + "\n");
                }
                System.out.println(out);
                System.out.println("-----------------------------");
                String RemoteAddress = httpSocket.getRemoteSocketAddress().toString();
                Integer LocalTCPPort = httpSocket.getLocalPort();
                System.out.println("Remote address: " + RemoteAddress);
                System.out.println("Local TCP port: " + LocalTCPPort);
                System.out.println("Size of Reply: " + SizeOfReply);
                System.out.println("Time elapsed: " + timeElapsed);
            }
            else {
                throw new Exception("Returned code different from 200.");
            }
        }
        catch (Exception e){
            System.out.println(e.getMessage());
        }
    }
}