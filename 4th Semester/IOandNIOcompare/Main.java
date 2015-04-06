import java.io.FileWriter;
import java.io.FileReader;
import java.io.IOException;
import java.io.File;
import java.io.FileNotFoundException;
import java.nio.file.Paths;
import java.nio.file.Files;

public class Main {
    public static final int TEXTLENGTH=1000;
    public static String ioProcedures(File resultFile,String inputString) throws IOException {
        StringBuilder resultString = new StringBuilder(TEXTLENGTH);
        FileWriter writer = new FileWriter(resultFile.getName());
        for (int i = 0; i <TEXTLENGTH ; i++) {
            writer.append(inputString.charAt(i));
        }
        writer.close();
        FileReader reader = new FileReader(resultFile.getName());
        for (int i = 0; i < TEXTLENGTH; i++) {
            resultString.append((char) reader.read());
        }
        return resultString.toString();
    }
    public static String nioProcedures(File resultFile,String inputString) throws IOException {
        StringBuilder resultString = new StringBuilder(TEXTLENGTH);
        Files.write(Paths.get(resultFile.getName()),inputString.getBytes());
        resultString.append(Files.readAllLines(Paths.get(resultFile.getName())));
        return resultString.toString();
    }
    public static void main(String[] args) {
        File resultFile = new File("resultFile.txt");
        double start = System.currentTimeMillis(),ioTime=0,nioTime=0;
        StringBuilder randomString = new StringBuilder(TEXTLENGTH);
        for (int i = 0; i < TEXTLENGTH; i++) {
            randomString.append((char) (Math.random() * 127 + 34));
        }
        try {
            for (int i = 0; i <100 ; i++) {
                ioProcedures(resultFile, randomString.toString());
                ioTime+= System.currentTimeMillis() - start;
                start = System.currentTimeMillis();
                nioProcedures(resultFile, randomString.toString());
                nioTime+= System.currentTimeMillis() - start;

            }
            System.out.println("java.io average time: " + ioTime/100 + "\njava.nio average time: " + nioTime/100);
        }
        catch (FileNotFoundException e) {
            System.out.println("Nie znaleziono pliku.");
        }
        catch (IOException e){
            System.out.println("Zapis lub odczyt nie powiódł się.");
        }
    }
}
