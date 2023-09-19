import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Doit_001 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int length = Integer.parseInt(br.readLine());
        String numbers = br.readLine();
        int sum = 0;

        for (int idx = 0; idx < length; idx++) {
            sum += numbers.charAt(idx) - '0';
        }
        System.out.println(sum);
    }
}