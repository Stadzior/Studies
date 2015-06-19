package com.company;

/**
 * Created by Kamil on 2015-06-07.
 */
public class InvalidSyntaxException extends Exception
{
    public InvalidSyntaxException(String outputMsg)
    {
        System.out.println(outputMsg);
    }
}
