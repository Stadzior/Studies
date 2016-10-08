import org.sql2o.Connection;
import org.sql2o.Sql2o;
import org.sql2o.data.Table;

import java.security.NoSuchAlgorithmException;
import java.security.spec.InvalidKeySpecException;
import java.util.ArrayList;

public class DbManager {

    private static Sql2o conn = new Sql2o("jdbc:mysql://localhost:3307/carpoolingsystem","root","");

    public static synchronized boolean canReserveSeats(Integer IdTrip, int AmountOfSeatsToReserve){
        ArrayList<String> Params = new ArrayList<String>();
        Params.add(IdTrip.toString());
        int SeatsLeft = (Integer)getValueFromStoredProcedure("getSeatsLeft",Params);
        return AmountOfSeatsToReserve <= SeatsLeft;
    }
    public static synchronized boolean anySeatLeft(Integer IdTrip){
        ArrayList<String> Params = new ArrayList<String>();
        Params.add(IdTrip.toString());
        int SeatsLeft = (Integer)getValueFromStoredProcedure("getSeatsLeft",Params);
        return 0 < SeatsLeft;
    }

    public static synchronized boolean userExists(String Email){
        ArrayList<String> Params = new ArrayList<String>();
        int  emailOccurence = (Integer)conn.open().
                createQuery("select count(*) from users where Email = '" + Email + "';").
                executeAndFetchFirst(Integer.class);
        return emailOccurence>0;
    }

    public static synchronized boolean tripExists(Integer IdTrip){
        ArrayList<String> Params = new ArrayList<String>();
        int  tripOccurence = (Integer)conn.open().
                createQuery("select count(*) from trips where IdTrip = " + IdTrip.toString() + ";").
                executeAndFetchFirst(Integer.class);
        return tripOccurence>0;
    }

    public static synchronized boolean reservationExists(Integer IdReservation){
        ArrayList<String> Params = new ArrayList<String>();
        int  reservationOccurence = (Integer)conn.open().
                createQuery("select count(*) from reservations where IdReservation = " + IdReservation.toString() + ";").
                executeAndFetchFirst(Integer.class);
        return reservationOccurence>0;
    }

    public static synchronized Table getTableFromStoredProcedure(String ProcedureName, ArrayList<String> Parameters)
    {
        StringBuilder sql = new StringBuilder("CALL `carpoolingsystem`.`"+ProcedureName+"`(");
        for(String param : Parameters) {
            sql.append(param).append(",");
        }
        sql.deleteCharAt(sql.length()-1);
        sql.append(");");
        try(Connection connection = conn.open()) {
            return connection.createQuery(sql.toString()).executeAndFetchTable();
        }
    }
    public static synchronized Table getTableFromStoredProcedure(String ProcedureName)
    {
        String sql = "CALL `carpoolingsystem`.`"+ProcedureName+"`();";
        try(Connection connection = conn.open()) {
            return connection.createQuery(sql).executeAndFetchTable();
        }
    }
    public static synchronized Object getValueFromStoredProcedure(String ProcedureName,ArrayList<String> Parameters)
    {
        StringBuilder sql = new StringBuilder("CALL `carpoolingsystem`.`"+ProcedureName+"`(");
        for(String param : Parameters) {
            sql.append(param).append(",");
        }
        sql.append(");");
        try(Connection connection = conn.open()) {
            return connection.createQuery(sql.toString()).executeAndFetchFirst(Integer.class);
        }
    }
    public static synchronized Object getValueFromStoredProcedure(String ProcedureName)
    {
        String sql = "CALL `carpoolingsystem`.`"+ProcedureName+"`();";
        try(Connection connection = conn.open()) {
            return connection.createQuery(sql).executeAndFetchFirst(Integer.class);
        }
    }

    public static void executeStoredProcedure(String ProcedureName,ArrayList<String> Parameters)
    {
        StringBuilder sql = new StringBuilder("CALL `carpoolingsystem`.`"+ProcedureName+"`(");
        for(String param : Parameters) {
            sql.append(param).append(",");
        }
        sql.append(");");
        try(Connection connection = conn.open()) {
            connection.createQuery(sql.toString()).executeUpdate();
        }
    }

    public static void executeStoredProcedure(String ProcedureName)
    {
        String sql = "CALL `carpoolingsystem`.`"+ProcedureName+"`();";
        try(Connection connection = conn.open()) {
            connection.createQuery(sql).executeUpdate();
        }
    }

    public static synchronized boolean addUser(String Username, String Email, String openPassword) {
        if(!userExists(Email)){
            ArrayList<String> Params = new ArrayList<String>();
            Params.add(Username);
            Params.add(Email);
            try {
                Params.add(PasswordHash.createHash(openPassword));
            } catch (NoSuchAlgorithmException | InvalidKeySpecException e) {
                e.printStackTrace();
            }
            executeStoredProcedure("insertUser",Params);
            return true;
        }
        return false;
    }

    public static synchronized boolean addReservation(Integer IdUser,Integer IdTrip,Integer AmountOfSeatsToReserve){
        if (canReserveSeats(IdTrip, AmountOfSeatsToReserve)){
            ArrayList<String> Params = new ArrayList<String>();
            Params.add(IdUser.toString());
            Params.add(IdTrip.toString());
            Params.add(AmountOfSeatsToReserve.toString());
            executeStoredProcedure("insertReservation",Params);
            return true;
        }
        else
        {
            return false;
        }
    }
    public static boolean cancelReservation(Integer IdReservation){
        if (reservationExists(IdReservation)){
        int IdTrip = (Integer)conn.open().
                createQuery("select distinct IdTrip from reservations where IdReservation = " + IdReservation.toString()).
                executeAndFetchFirst(Integer.class);
            ArrayList<String> Params = new ArrayList<String>();
            Params.add(IdReservation.toString());
            executeStoredProcedure("deleteReservation",Params);
            return true;
        }
        else
        {
            return false;
        }
    }

    public static int addTrip(Integer IdUser,
                                               Double Price,
                                               String CityFrom,
                                               String CityTo,
                                               String Date,
                                               Integer AmountOfSeats){
            ArrayList<String> Params = new ArrayList<String>();
            Params.add(Price.toString());
            Params.add(CityFrom);
            Params.add(CityTo);
            Params.add(Date);
            Params.add(AmountOfSeats.toString());
            executeStoredProcedure("insertTrip", Params);
            Params.add(IdUser.toString());
            return (Integer)getValueFromStoredProcedure("getIdTrip",Params);
    }
    public static boolean cancelTrip(Integer IdTrip){
        if(tripExists(IdTrip)) {
            ArrayList<String> Params = new ArrayList<String>();
            Params.add(IdTrip.toString());
            executeStoredProcedure("deleteTrip", Params);
            return true;
        }
        else
        {
            return false;
        }
    }

    public static String getHashedPassword(String Email){
        return conn.open().
                createQuery("select distinct Password from users where Email = '" + Email + "'").
                executeAndFetchFirst(String.class);
    }

    public static Table getSearchResults(String CityFrom,String CityTo,String Date){
        ArrayList<String> Params = new ArrayList<String>();
        Params.add(CityFrom == null? "\"\"":CityFrom);
        Params.add(CityTo == null? "\"\"":CityTo);
        Params.add(Date == null? "\"\"":Date);
        return getTableFromStoredProcedure("getSearchResults", Params);
    }
    public static Table getMyTrips(String OwnerName){
        ArrayList<String> Params = new ArrayList<String>();
        Params.add(OwnerName == null? "\"Sebix\"":OwnerName);
        return getTableFromStoredProcedure("getMyTrips", Params);
    }
}
