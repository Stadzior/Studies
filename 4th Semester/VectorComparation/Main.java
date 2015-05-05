package com.company;
import jdk.nashorn.internal.runtime.RecompilableScriptFunctionData;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
class DifferentVectorSizeException extends Exception
{
    DifferentVectorSizeException()
    {
    }
}
public class Main {

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Uwaga! Podawaj wektory w formacie: 'x0 x1 x2 xn'");
        System.out.println("Podaj pierwszy wektor:");
        try {
            String[] FirstVector = input.nextLine().split(" ");
            System.out.println("Podaj drugi wektor:");
            String[] SecondVector = input.nextLine().split(" ");
            try {
                if (FirstVector.length == SecondVector.length) {
                    int[] ResultVector = new int[FirstVector.length];
                    File resultFile = new File("resultFile.txt");
                    for (int i = 0; i < ResultVector.length; i++) {
                        ResultVector[i] = Integer.parseInt(FirstVector[i]) + Integer.parseInt(SecondVector[i]);
                        FileWriter writer = new FileWriter(resultFile.getName());
                        for (int j = 0; j < ResultVector.length; j++) {
                            writer.append(" "+Integer.toString(ResultVector[j]));
                        }
                        writer.close();
                    }
                } else {
                    throw new DifferentVectorSizeException();
                }
            } catch (DifferentVectorSizeException e) {
                System.out.println("Wektory różnej długości!");
                System.out.println("Długość pierwszego: " + FirstVector.length);
                System.out.println("Długość drugiego: " + SecondVector.length);
            }
            catch(IOException e) {
                System.out.println("Coś nie tak z zapisem!");
            }
        }
        catch (NumberFormatException e)
        {
            System.out.println("Nieprawidłowe dane wejściowe.");
        }
        input.close();
    }
}
