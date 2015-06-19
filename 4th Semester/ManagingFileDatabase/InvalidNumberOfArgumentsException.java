package com.company;

/**
 * Created by Kamil on 2015-06-16.
 */
public class InvalidNumberOfArgumentsException extends Exception {
    public InvalidNumberOfArgumentsException(String outputMsg) {
        System.out.println(outputMsg);
    }
}
