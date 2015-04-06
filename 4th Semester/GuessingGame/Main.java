package com.company;

import java.io.IOException;
import java.util.NoSuchElementException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        int NumberToGuess = (int) (Math.random() * 100 + 1), InputtedNumber = 0;
        Scanner input = new Scanner(System.in);
        do {
            try {
                InputtedNumber = Integer.parseInt(input.nextLine());
                if(InputtedNumber>NumberToGuess)
                {
                    System.out.println("Szukana liczba jest mniejsza.");
                }
                else
                {
                    if(InputtedNumber<NumberToGuess)
                    {
                        System.out.println("Szukana liczba jest większa.");
                    }
                }
            }
            catch(NoSuchElementException e)
            {
                System.out.println("Nie wpisano nic sensownego.");
                InputtedNumber=-1;
            }
            catch(NumberFormatException e)
            {
                System.out.println("Nie wpisano liczby całkowitej.");
                InputtedNumber=-1;
            }
        } while (InputtedNumber != NumberToGuess);
        System.out.println("Znalazłeś liczbę "+NumberToGuess+"!");
    }
}
