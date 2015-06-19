package com.company;

/**
 * Created by Kamil on 2015-06-13.
 */
public class ElementDoesntExistException extends Exception {
    public ElementDoesntExistException(String elementType,String elementName)
    {
        System.out.println(elementType+" "+elementName+" doesn't exist in current context.");
    }
}
