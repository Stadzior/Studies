import org.jsoup.Jsoup;
import org.jsoup.nodes.Document;
import org.jsoup.nodes.Element;

import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        try {
            for (String arg : args) {
                String Url = arg;
                String HostName = Url.substring(Url.indexOf(":") + 3, Url.length());
                Document doc = Jsoup.connect(Url).get();
                doc.setBaseUri(Url);
                ArrayList<String> links = new ArrayList<String>();
                ArrayList<String> mails = new ArrayList<String>();
                ArrayList<String> images = new ArrayList<String>();

                for (Element link : doc.select("a[href]")) {
                    String AbsLink = link.absUrl("href");
                    if (AbsLink.contains("mailto")) {
                        mails.add(AbsLink);
                    } else {
                        links.add(AbsLink);
                    }
                }

                for (Element image : doc.select("img")) {
                    String AbsImage = image.absUrl("src");
                    images.add(AbsImage);
                }

                System.out.println("--------------------------------------\n" + HostName);
                System.out.println("\nLinks:");
                for (String link : links) {
                    System.out.println(link);
                }
                System.out.println("\nMails:");
                for (String mail : mails) {
                    System.out.println(mail);
                }
                System.out.println("\nImages:");
                for (String image : images) {
                    System.out.println(image);
                }

                String head = Jsoup.connect(Url).get().head().toString();

                File file = new File("head.txt");
                if (!file.exists()) {
                    file.createNewFile();
                }
                FileWriter writer;
                if (args[0].equals(arg))
                {
                    writer = new FileWriter(file);
                } else {
                    writer = new FileWriter(file,true);
                }
                writer.write(head);
                writer.flush();
                writer.close();
            }
        }
        catch (Exception e){
            System.out.println(e.getMessage());
        }
    }
}