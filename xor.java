public class XORExample {
    public static void main(String[] args) {
        String str = "Hello world!";

        for (int i = 0; i < str.length(); i++) {
            System.out.print((char)(str.charAt(i) ^ 0));
        }
    }
}
