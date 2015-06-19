package com.company;

/**
 * Created by Kamil on 2015-06-15.
 */
public class DatabaseNotOpenedException extends Exception {

    public DatabaseNotOpenedException() {
        System.out.println("There is no currently opened database.");
    }
}
