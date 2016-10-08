import java.security.NoSuchAlgorithmException;
import java.security.spec.InvalidKeySpecException;

/**
 * Created by Kamil on 2016-02-07.
 */
public class Authentication {
    public static boolean validateUser(String email,String openPassword)
    {
        boolean isValid = false;
        try {
            isValid = PasswordHash.validatePassword(openPassword, DbManager.getHashedPassword(email));
        } catch (NoSuchAlgorithmException | InvalidKeySpecException e) {
            e.printStackTrace();
        }
        return isValid;
    }
}
