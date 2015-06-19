package com.company;

import jdk.nashorn.internal.runtime.regexp.joni.Syntax;

import javax.xml.crypto.Data;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.nio.file.NoSuchFileException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	// write your code here
        Scanner input = new Scanner(System.in);
        String[] inputCommand = new String[2];
        String inputtedText;
        int cmdTitleEnd;
        boolean SyntaxIsValid;
        System.out.println("Witaj w obsłudze bazy plikowej!");
        System.out.println("Wpisuj komendy use,select,input,update,delete,where w jednej linii!");
        do {
            SyntaxIsValid = true;
            try {
                inputtedText = input.nextLine();
                if (inputtedText.contains(" ")) {
                    cmdTitleEnd = inputtedText.indexOf(" ");
                    inputCommand[1] = inputtedText.substring(cmdTitleEnd + 1, inputtedText.length());
                } else {
                    cmdTitleEnd = inputtedText.length();
                    inputCommand[1] = " ";
                }
                inputCommand[0] = inputtedText.substring(0, cmdTitleEnd);

                FileDBLib.SyntaxMatcher(inputCommand);
            } catch (InvalidSyntaxException e) {
                SyntaxIsValid = false;
            }
            if ((!(inputCommand[0].contentEquals("exit"))) && (!(inputCommand[0].contentEquals("Exit"))) && (SyntaxIsValid)) {
                try {
                    FileDBLib.CommandExecutor(inputCommand);
                } catch (NoSuchFileException e) {
                    System.out.println("This table doesn't exist in current context.");
                } catch (IOException e) {
                    System.out.println("There were some problems with read/write operation on database file.");
                } catch (ElementDoesntExistException e) {
                } catch (DatabaseNotOpenedException e){
                } catch (InvalidNumberOfArgumentsException e){
                }
            }
        }while(!(inputCommand[0].contentEquals("exit"))&&!(inputCommand[0].contentEquals("Exit")));

    }
}
