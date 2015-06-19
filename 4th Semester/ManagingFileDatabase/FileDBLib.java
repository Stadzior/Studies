package com.company;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.util.ArrayList;
import java.util.Dictionary;
import java.util.HashMap;
import java.util.Map;
import java.util.regex.Pattern;

public class FileDBLib {
    private static ArrayList<ArrayList<String>> ResultGrid = new ArrayList<ArrayList<String>>();
    private static Path tablePath;
    private static String[] TableColumns;
    private static StringBuilder databasePath = new StringBuilder();
    private static BufferedReader reader;
    private static BufferedWriter writer;
    private static String[] splittedCommand;


    private static String ResultsToString()
    {
        StringBuilder ResultString = new StringBuilder();
        for (int i = 0; i < ResultGrid.size(); i++) {
            ResultString.append("\n");
            for (int j = 0; j < ResultGrid.get(i).size(); j++) {
                ResultString.append(ResultGrid.get(i).get(j) + " ");
            }
        }
        return ResultString.toString();
    }

    private static void ReadAllTable(String tableName) throws IOException {
        if (reader != null) {
            reader.close();
        }
        tablePath = Paths.get(databasePath + "/" + tableName + ".txt");
        reader = Files.newBufferedReader(tablePath);
        String line = reader.readLine();
        ArrayList<String> splittedLine = new ArrayList<String>();
        while (line != null) {
            for (String field : line.split(" ")) {
                splittedLine.add(field);
            }
            ResultGrid.add(new ArrayList<String>(splittedLine));
            line = reader.readLine();
            splittedLine.clear();
        }
        reader.close();
    }

    private static void InitTableColumns(String tableName) throws IOException
    {
        if (reader != null) {
            reader.close();
        }
        tablePath = Paths.get(databasePath + "/" + tableName + ".txt");
        reader = Files.newBufferedReader(tablePath);
        TableColumns = reader.readLine().split(" ");
        reader.close();
    }

    private static void AppendToTable(String tableName, String outputData) throws ElementDoesntExistException,IOException {
        if (writer != null) {
            writer.close();
        }
        tablePath = Paths.get(databasePath + "/" + tableName + ".txt");
        if(Files.exists(tablePath)) {
            writer = Files.newBufferedWriter(tablePath, StandardOpenOption.APPEND);
            writer.write(outputData);
            writer.close();
        }else
        {
            throw new ElementDoesntExistException("Table",tableName);
        }
    }

    private static void ReplaceTable(String tableName,String outputData) throws ElementDoesntExistException,IOException {
        if (writer != null) {
            writer.close();
        }
        tablePath = Paths.get(databasePath + "/" + tableName + ".txt");
        if(Files.exists(tablePath)) {
            writer = Files.newBufferedWriter(tablePath);
            writer.write(outputData);
            writer.close();
        }else
        {
            throw new ElementDoesntExistException("Table",tableName);
        }
    }

    private static void Use(String inputCommand) throws ElementDoesntExistException {
        if (Files.exists(Paths.get(inputCommand))) {
            databasePath.setLength(0);
            databasePath.append(inputCommand);
        } else {
            throw new ElementDoesntExistException("Database", inputCommand);
        }
    }

    private static void CreateTable(String inputCommand) throws IOException,ElementDoesntExistException {
        splittedCommand = inputCommand.split(" ");
        String[] splittedColumns = splittedCommand[1].split(",");
        tablePath = Paths.get(databasePath + "/" + splittedCommand[0] + ".txt");
        if (!Files.exists(tablePath)) {
            Files.createFile(tablePath);
            for(String column : splittedColumns) {
                AppendToTable(splittedCommand[0],column+" ");
            }
        }
    }

    private static void DropTable(String tableName) throws ElementDoesntExistException,IOException {
        tablePath = Paths.get(databasePath + "/" + tableName + ".txt");
        if (Files.exists(tablePath)){
            Files.delete(tablePath);
        } else {
            throw new ElementDoesntExistException("Table", tableName);
        }
    }

    private static void Select(String inputCommand) throws ElementDoesntExistException, DatabaseNotOpenedException, IOException {
        if (!("".contentEquals(databasePath))) {
            splittedCommand = inputCommand.split(" ");
            ReadAllTable(splittedCommand[2]);
            if (inputCommand.contains("where")) {
                String Expresion = inputCommand.substring(inputCommand.indexOf("where") + "where".length() + 1, inputCommand.length());
                int fullResultSize = ResultGrid.size(),actualIndex=1;
                for (int i = 1; i < fullResultSize; i++) {
                    if (!Where(Expresion,actualIndex)) {
                        ResultGrid.remove(actualIndex);
                    }
                    else {
                        actualIndex++;
                    }
                }
            }
            if (!(splittedCommand[0].contentEquals("*"))) {
                String[] splittedColumns = splittedCommand[0].split(",");
                int i, j, fullResultSize, actualIndex = 0;
                fullResultSize = ResultGrid.get(0).size();
                for (i = 0; i < fullResultSize; i++) {
                    j = 0;
                    for (; j < splittedColumns.length; j++) {
                        actualIndex = i - (fullResultSize - ResultGrid.get(0).size());
                        if (splittedColumns[j].contentEquals(ResultGrid.get(0).get(actualIndex))) {
                            break;
                        }
                    }
                    if (j > splittedColumns.length - 1) {
                        for (ArrayList<String> line : ResultGrid) {
                            line.remove(actualIndex);
                        }
                    }
                }
                if(ResultGrid.get(0).size()<1)
                {
                    throw new ElementDoesntExistException("One or more columns","");
                }
            }
            System.out.println(ResultsToString());
        } else {
            throw new DatabaseNotOpenedException();
        }
    }

    private static void Insert(String inputCommand) throws ElementDoesntExistException,DatabaseNotOpenedException,InvalidNumberOfArgumentsException, IOException {
        if (!("".contentEquals(databasePath))) {
            splittedCommand = inputCommand.split(" ");
            InitTableColumns(splittedCommand[1]);
            StringBuilder ResultStrBuilder = new StringBuilder();
            ResultStrBuilder.append("\n");
            String[] splittedValues;
            if (splittedCommand[2].contentEquals("values")) {
                splittedValues = splittedCommand[3].substring(1, splittedCommand[3].length() - 1).split(",");
                if (splittedValues.length != TableColumns.length) {
                    throw new InvalidNumberOfArgumentsException("To many or to little values to insert.");
                }
                for (String value : splittedValues) {
                    ResultStrBuilder.append(value + " ");
                }
            } else {
                splittedValues = splittedCommand[4].substring(1, splittedCommand[4].length() - 1).split(",");
                ArrayList<String> ValuesToInsert=new ArrayList<String>();
                for (int i = 0; i < TableColumns.length; i++) {
                    ValuesToInsert.add("NULL");
                }
                String[] splittedColumns = splittedCommand[2].substring(1, splittedCommand[2].length() - 1).split(",");
                if ((splittedColumns.length < 0) || (splittedColumns.length > TableColumns.length)) {
                    throw new InvalidNumberOfArgumentsException("To many or not at all columns listed.");
                } else {
                    if (splittedColumns.length != splittedValues.length) {
                        throw new InvalidNumberOfArgumentsException("Number of columns and values must be the same!");
                    }
                    int i,j;
                    for (i = 0; i < splittedColumns.length; i++) {
                        for (j = 0; j < TableColumns.length; j++) {
                            if (splittedColumns[i].contentEquals(TableColumns[j])) {
                                break;
                            }
                        }
                        if (j >  TableColumns.length - 1) {
                            throw new ElementDoesntExistException("Column",splittedColumns[i]);
                        }
                        ValuesToInsert.set(j,splittedValues[i]);
                    }
                    for(String value : ValuesToInsert)
                    {
                        ResultStrBuilder.append(value + " ");
                    }
                }
            }
            AppendToTable(splittedCommand[1],ResultStrBuilder.toString());
        } else {
            throw new DatabaseNotOpenedException();
        }
    }

    private static void Update(String inputCommand) throws ElementDoesntExistException,DatabaseNotOpenedException, IOException {
        if (!("".contentEquals(databasePath))) {
            splittedCommand = inputCommand.split(" ");
            ReadAllTable(splittedCommand[0]);
            String[] splittedSetters = splittedCommand[2].split(",");
            ArrayList<String> Columns = new ArrayList<String>();
            ArrayList<String> Values = new ArrayList<String>();
            for (String item : splittedSetters) {
                Columns.add(item.substring(0, item.indexOf('=')));
                Values.add(item.substring(item.indexOf('=') + 2, item.length() - 1));
            }
            if (inputCommand.contains("where")) {
                String Expresion = inputCommand.substring(inputCommand.indexOf("where") + "where".length() + 1, inputCommand.length());
                int fullResultSize = ResultGrid.size(),actualIndex=1;
                for (int i = 1; i < fullResultSize; i++) {
                    if (Where(Expresion,actualIndex)) {
                        ResultGrid.remove(actualIndex);
                    }
                    else {
                        actualIndex++;
                    }
                }
            }
            int fullResultSize = ResultGrid.get(0).size(), actualIndex = 0;
            for (int i = 0; i < Columns.size(); i++) {
                for (int j = 0; j < fullResultSize; j++) {
                    actualIndex = j - (fullResultSize - ResultGrid.get(0).size());
                    if (Columns.get(i).contentEquals(ResultGrid.get(0).get(actualIndex))) {
                        for (int k=1;k<ResultGrid.size();k++) {
                            ResultGrid.get(k).set(actualIndex, Values.get(i));
                        }
                        break;
                    }
                }
            }
            ReplaceTable(splittedCommand[0],ResultsToString());
        } else
        {
            throw new DatabaseNotOpenedException();
        }
    }

    private static void Delete(String inputCommand) throws ElementDoesntExistException,DatabaseNotOpenedException, IOException {
        if (!("".contentEquals(databasePath))) {
            splittedCommand = inputCommand.split(" ");
            ReadAllTable(splittedCommand[2]);
            int fullResultSize=ResultGrid.size();
            if (!(inputCommand.contains("where"))||(splittedCommand[0].contentEquals("*"))) {
                for (int i = 1; i < fullResultSize; i++) {
                    ResultGrid.remove(1);
                }
            }
            else {
                String Expresion = inputCommand.substring(inputCommand.indexOf("where") + "where".length() + 1, inputCommand.length());
                fullResultSize = ResultGrid.size();
                int actualIndex=1;
                for (int i = 1; i < fullResultSize; i++) {
                    if (!Where(Expresion,actualIndex)) {
                        ResultGrid.remove(actualIndex);
                    }
                    else {
                        actualIndex++;
                    }
                }
            }
            ReplaceTable(splittedCommand[2],ResultsToString());
        } else {
            throw new DatabaseNotOpenedException();
        }
    }

    private static boolean Where(String inputCommand,int index){
        String[] splittedExpresion = inputCommand.split("(and|or)");
        ArrayList<ArrayList<String>> expElements= new ArrayList<ArrayList<String>>();
        int indexOfMark;
        ArrayList<String> Marks = new ArrayList<String>();
        for (String item : splittedExpresion) {
            item = item.trim();
            if (item.contains("!")) {
                indexOfMark = item.indexOf('!');
                Marks.add(item.substring(indexOfMark, indexOfMark + 1));

            } else {
                indexOfMark = item.indexOf('=');
                Marks.add(item.substring(indexOfMark));
            }
            ArrayList<String> field = new ArrayList<String>();
            field.add(item.substring(0, indexOfMark).trim());
            field.add(item.substring(item.indexOf('=') + 2, item.length() - 1).trim());
            expElements.add(new ArrayList<String>(field));
        }
        boolean result=false;
        if(expElements.size()<2) {
            for (int i = 0; i < ResultGrid.get(0).size(); i++) {
                if((expElements.get(0).get(0).contentEquals(ResultGrid.get(0).get(i)))&&(expElements.get(0).get(1).contentEquals(ResultGrid.get(index).get(i)))) {
                    result=true;
                }
            }
        }
        else
        {
            boolean[] minorResults= new boolean[Marks.size()],relativeExp = new boolean[Marks.size()];
            for(ArrayList<String> exp : expElements) {
                for (int i = 0; i < ResultGrid.get(0).size(); i++) {
                    minorResults[i]=false;
                    if (Marks.get(expElements.indexOf(exp)) == "=") {
                        relativeExp[expElements.indexOf(exp)] = (exp.get(1).contentEquals(ResultGrid.get(index).get(i)));
                    } else {
                        if (Marks.get(expElements.indexOf(exp)) == "!=") {
                            relativeExp[expElements.indexOf(exp)] = !(exp.get(1).contentEquals(ResultGrid.get(index).get(i)));
                        } else {
                            relativeExp[expElements.indexOf(exp)] = false;
                        }
                    }
                    if ((exp.get(0).contentEquals(ResultGrid.get(0).get(i))) && relativeExp[expElements.indexOf(exp)]) {
                        minorResults[i] = true;
                    }
                }
            }
            if (inputCommand.contains("and")) {
                result=minorResults[0]&&minorResults[1];
            } else {
                if (inputCommand.contains("or")) {
                    result=minorResults[0]||minorResults[1];
                }
            }
        }
        return result;
    }
    private static String regex;
    public static void SyntaxMatcher(String[] inputCommand) throws InvalidSyntaxException
    {
        if((inputCommand[0].contentEquals("use"))||(inputCommand[0].contentEquals("Use"))) {
            regex="^[a-zA-Z0-9_]*$";
        }
        else {
            if ((inputCommand[0].contentEquals("create_table")) || (inputCommand[0].contentEquals("Create_Table"))) {
                regex = "[a-zA-Z0-9_]* [a-zA-Z0-9_,]*$";
            } else {
                if ((inputCommand[0].contentEquals("drop_table")) || (inputCommand[0].contentEquals("Drop_Table"))) {
                    regex = "[a-zA-Z0-9_]*$";
                } else {
                    if ((inputCommand[0].contentEquals("select")) || (inputCommand[0].contentEquals("Select"))) {
                        regex = "^[a-zA-Z0-9_,*]* from [a-zA-Z0-9_]*( where [a-zA-Z0-9_]*(!=|=)'[a-zA-Z0-9_]*'( (and|or) [a-zA-Z0-9_]*(!=|=)'[a-zA-Z0-9_]*')*)?$";
                    } else {
                        if ((inputCommand[0].contentEquals("insert")) || (inputCommand[0].contentEquals("Insert"))) {
                            regex = "^into [a-zA-Z0-9_]*( [(][a-zA-Z0-9_]*(,[a-zA-Z0-9_]*)*[)])? values [(][a-zA-Z0-9_]*(,[a-zA-Z0-9_]*)*[)]$";
                        } else {
                            if ((inputCommand[0].contentEquals("update")) || (inputCommand[0].contentEquals("Update"))) {
                                regex = "^[a-zA-Z0-9_]* set [a-zA-Z0-9_]*='[a-zA-Z0-9_]*'(,[a-zA-Z0-9_]*='[a-zA-Z0-9_]*')*( where [a-zA-Z0-9_]*(!=|=)'[a-zA-Z0-9_]*'( (and|or) [a-zA-Z0-9_]*(!=|=)'[a-zA-Z0-9_]*')*)?$";
                            } else {
                                if ((inputCommand[0].contentEquals("delete")) || (inputCommand[0].contentEquals("Delete"))) {
                                    regex = "^([*] )?from [a-zA-Z0-9_]*( where [a-zA-Z0-9_]*(!=|=)'[a-zA-Z0-9_]*'( (and|or) [a-zA-Z0-9_]*(!=|=)'[a-zA-Z0-9_]*')*)?$";
                                } else {
                                    if (!((inputCommand[0].contentEquals("exit")) || (inputCommand[0].contentEquals("Exit")))) {
                                        throw new InvalidSyntaxException("Syntax is incorrect! Try use,select,insert,delete,update or exit");
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if((!((inputCommand[0].contentEquals("exit"))||(inputCommand[0].contentEquals("Exit"))))&&(!Pattern.matches(regex, inputCommand[1]))) {
                throw new InvalidSyntaxException(String.format("Syntax is incorrect! The syntax of the %s is invalid!", inputCommand[0]));
        }
    }
    public static void CommandExecutor(String[] inputCommand) throws ElementDoesntExistException,DatabaseNotOpenedException,InvalidNumberOfArgumentsException,IOException {
        if ((inputCommand[0].contentEquals("use")) || (inputCommand[0].contentEquals("Use"))) {
            Use(inputCommand[1]);
        } else {
            if ((inputCommand[0].contentEquals("create_table")) || (inputCommand[0].contentEquals("Create_Table"))) {
                CreateTable(inputCommand[1]);
            } else {
                if ((inputCommand[0].contentEquals("drop_table")) || (inputCommand[0].contentEquals("Drop_Table"))) {
                    DropTable(inputCommand[1]);
                } else {
                    if ((inputCommand[0].contentEquals("select")) || (inputCommand[0].contentEquals("Select"))) {
                        Select(inputCommand[1]);
                    } else {
                        if ((inputCommand[0].contentEquals("insert")) || (inputCommand[0].contentEquals("Insert"))) {
                            Insert(inputCommand[1]);
                        } else {
                            if ((inputCommand[0].contentEquals("update")) || (inputCommand[0].contentEquals("Update"))) {
                                Update(inputCommand[1]);
                            } else {
                                if ((inputCommand[0].contentEquals("delete")) || (inputCommand[0].contentEquals("Delete"))) {
                                    Delete(inputCommand[1]);
                                }
                            }
                        }
                    }
                    ResultGrid.clear();
                    if ("".contentEquals(databasePath)) {
                        throw new DatabaseNotOpenedException();
                    }
                }
            }
        }
    }
}