import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ_15482 {

    static String str1;
    static String str2;
    static int[][] D;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        str1 = br.readLine();
        str2 = br.readLine();

        dp();
        System.out.println(D[str1.length()][str2.length()]);

    }

    private static void dp() {
        D = new int[str1.length() + 1][str2.length() + 1];
        for (int idx = 1; idx <= str1.length(); idx++) {
            for (int jdx = 1; jdx <= str2.length(); jdx++) {
                if (str1.charAt(idx - 1) == str2.charAt(jdx - 1)) {
                    D[idx][jdx] = D[idx - 1][jdx - 1] + 1;
                } else {
                    D[idx][jdx] = Math.max(D[idx - 1][jdx], D[idx][jdx - 1]);
                }
            }
        }
    }

}
