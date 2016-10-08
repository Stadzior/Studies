import com.google.gson.Gson;
import org.apache.commons.lang3.tuple.Pair;
import org.sql2o.data.Table;

import java.security.NoSuchAlgorithmException;
import java.security.spec.InvalidKeySpecException;
import java.util.List;
import java.util.Map;

import static j2html.TagCreator.article;
import static j2html.TagCreator.b;
import static spark.Spark.*;
public class main {
    public static boolean validateUser(String Email,String openPassword){
        Boolean valid = false;
        if(DbManager.userExists(Email)){
            try {
                valid = PasswordHash.validatePassword(openPassword,DbManager.getHashedPassword(Email));
            } catch (NoSuchAlgorithmException | InvalidKeySpecException e) {
                e.printStackTrace();
            }
        }
        return valid;
    }
    public static void main(String[] args) throws InvalidKeySpecException, NoSuchAlgorithmException {
        staticFileLocation("public\\clientapp");
        init();
//        DbManager.addUser("TestowyZiutek","TotalnieTestowy@test.pl","Ziutosuaf");
//        DbManager.addTrip(8,19.50,"Kielce","Łódź","08-02-2016 15:00",3);
//        DbManager.addReservation(7,4,2);
//        DbManager.cancelTrip(4);
//        DbManager.addReservation(4,3,1);
//        DbManager.cancelReservation(7);

//      Table Heheszki = DbManager.getSearchedTrips("Łódź","Kielce","25-12-2015");
//        for(Row row : Heheszki.rows() ){
//            System.out.println(row.getInteger("IdTrip"));
//        }


//        before("/login", (Request request, Response response) -> {
//            Boolean authenticated = false;
//            String auth = request.headers("Authorization");
//            if (auth != null && auth.startsWith("Basic")) {
//                String b64Credentials = auth.substring("Basic".length()).trim();
//                String credentials = new String(Base64.getDecoder().decode(b64Credentials));
//                System.out.println(credentials);
//                if (credentials.equals("admin:hehe")) authenticated = true;
//            }
//            if (!authenticated) {
//                response.header("WWW-Authenticate", "Basic realm=\"Restricted\"");
//                response.status(401);
//            }
//        })
        post("/joinTrip", (req, res) -> {
            //DbManager.addReservation(Integer.parseInt(req.queryParams("UserName")),Integer.parseInt(req.queryParams("IdTrip")),Integer.parseInt(req.queryParams("AmountOfSeats")));
            return true;
        });
        post("/cancelTrip", (req, res) -> {
           //DbManager.cancelReservation(Integer.parseInt(req.queryParams("IdReservation") == null?"0":req.queryParams("IdReservation")));
            return true;
        });
        post("/", (req, res) -> {
            System.out.println("I'm in!"+req.queryParams("email")+req.queryParams("password"));
            return article().with(
                    b("WooooooHOOOOOOOO")).render();
        });
        get(("/search"),(req,res) -> {
            List<Map<String, Object>> test = DbManager.getSearchResults(req.params().get("CityFrom"), req.params().get("CityTo"),req.params().get("StartDate")).asList();
            StringBuilder tripHeaders = new StringBuilder();
            for(Map<String,Object> Row : test){
                for(int i=0;i<Row.size();i++){
                    tripHeaders.append(Row.get(Row.keySet().toArray()[i]).toString()).append("  ");
                }
                tripHeaders.append(";");
            }
            tripHeaders.deleteCharAt(tripHeaders.length()-1);
            return tripHeaders;
        });
        get(("/myTrips"),(req,res) -> {
            List<Map<String, Object>> trips = DbManager.getMyTrips(req.params().get("OwnerName")).asList();
            StringBuilder tripHeaders = new StringBuilder();
            for(Map<String,Object> Row : trips){
                for(int i=0;i<Row.size();i++){
                    tripHeaders.append(Row.get(Row.keySet().toArray()[i]).toString()).append("  ");
                }
                tripHeaders.append(";");
            }
            tripHeaders.deleteCharAt(tripHeaders.length()-1);
            return tripHeaders;
        });
        get(("/joinedTrips"),(req,res) -> {
            List<Map<String, Object>> test = DbManager.getSearchResults(req.params().get("CityFrom"), req.params().get("CityTo"), req.params().get("StartDate")).asList();
            StringBuilder tripHeaders = new StringBuilder();
            for(Map<String,Object> Row : test){
                for(int i=0;i<Row.size();i++){
                    tripHeaders.append(Row.get(Row.keySet().toArray()[i]).toString()).append("  ");
                }
                tripHeaders.append(";");
            }
            tripHeaders.deleteCharAt(tripHeaders.length()-1);
            return tripHeaders;
        });
    }
}
