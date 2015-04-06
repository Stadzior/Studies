

public class Main {

    public static String substring(String inputString,int beginIndex,int endIndex) {
        String resultSubString=inputString.substring(beginIndex,endIndex+1);
        System.out.println(resultSubString);
        return resultSubString;
    }
    public static void main(String[] args) {
        try {
            substring(args[0], Integer.parseInt(args[1]), Integer.parseInt(args[2]));
        }
        catch(NumberFormatException e){
            System.out.println("Podano nieprawidłowe parametry!");
        }
        catch (StringIndexOutOfBoundsException e) {
            System.out.println("Podane indeksy wykraczają poza podany ciąg znaków!");
        }
    }
}
