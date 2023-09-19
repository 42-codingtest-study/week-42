import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_1722 {

    static int[][] dp;
    static int n, m;
    static int max = 0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());

        dp(br);

        System.out.println(max*max);
    }

    private static void dp(BufferedReader br) throws IOException {
        dp = new int[n + 1][m + 1];

        for (int idx = 0; idx < n; idx++) {
            String input = br.readLine();
            for (int jdx = 0; jdx < m; jdx++) {
                dp[idx][jdx] = input.charAt(jdx) - '0';
                if (dp[idx][jdx] == 1 && idx > 0 & jdx > 0) {
                    dp[idx][jdx] = Math.min(dp[idx - 1][jdx], Math.min(dp[idx][jdx - 1], dp[idx - 1][jdx - 1])) + 1;
                }
                if (max < dp[idx][jdx]) {
                    max = dp[idx][jdx];
                }
            }
        }
    }

}
