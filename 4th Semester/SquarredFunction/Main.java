import java.util.Vector;

class DeltaLessThanZeroException extends Exception
        {
        public DeltaLessThanZeroException()
        {
        }
        }
class FirstParameterEqualsZeroException extends Exception
{
    public FirstParameterEqualsZeroException()
    {
    }
}
public class Main {
        public static void main (String[]args){
        double[] parametersArray = new double[3];
        try {
        for (int i = 0; i < 3; i++) {
            parametersArray[i] = Double.parseDouble(args[i]);
        }
            if (parametersArray[0] == 0) {
                throw new FirstParameterEqualsZeroException();
            }
            double delta = parametersArray[1] * parametersArray[1] - 4 * parametersArray[0] * parametersArray[2];
            Vector resultVector = new Vector(0);
            if (delta < 0) {
                throw new DeltaLessThanZeroException();
            } else {
                if (delta == 0) {
                    resultVector.addElement(-parametersArray[1] / (2 * parametersArray[0]));
                } else {
                    resultVector.addElement((-parametersArray[1] - Math.sqrt(delta)) / (2 * parametersArray[0]));
                    resultVector.addElement((-parametersArray[1] + Math.sqrt(delta)) / (2 * parametersArray[0]));
                }
            }
            System.out.println(resultVector);
        }
        catch(NumberFormatException e) {
            System.out.println("Nieprawidlowe parametry!");
        }
        catch(FirstParameterEqualsZeroException e) {
            System.out.println("To nie jest funkcja kwadratowa!");
        }
        catch(DeltaLessThanZeroException e) {
            System.out.println("Delta mniejsza od zera, nie ma wynikow!");
        }
        catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Podano za mało parametrów!");
        }
    }
}
