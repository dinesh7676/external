import javax.crypto.Cipher;
import javax.crypto.spec.SecretKeySpec;

public class Rijndael {
    public static void main(String[] args) throws Exception {
        String key = "1234567890123456";
        String msg = "Hello World";

        SecretKeySpec secretKey = new SecretKeySpec(key.getBytes(), "AES");

        Cipher cipher = Cipher.getInstance("AES");

        cipher.init(Cipher.ENCRYPT_MODE, secretKey);
        byte[] encrypted = cipher.doFinal(msg.getBytes());

        System.out.println("Encrypted: " +
            java.util.Base64.getEncoder().encodeToString(encrypted));

        cipher.init(Cipher.DECRYPT_MODE, secretKey);
        byte[] decrypted = cipher.doFinal(encrypted);

        System.out.println("Decrypted: " + new String(decrypted));
    }
}
