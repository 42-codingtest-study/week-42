import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_13398 {

    static int[] arr;
    static int[] l;
    static int[] r;
    static int max;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        arr = new int[N + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int idx = 1; idx <= N; idx++) {
            arr[idx] = Integer.parseInt(st.nextToken());
        }

        dp(N);
        dpRemoveOneNum(N);
        System.out.println(max);

    }

    private static void dpRemoveOneNum(int N) {
        for (int idx = 2; idx <= N - 1; idx++) {
            max = Math.max(max, l[idx - 1] + r[idx + 1]);
        }
    }

    private static void dp(int N) {
        l = new int[N + 1];
        r = new int[N + 1];

        l[1] = arr[1];
        r[N] = arr[N];
        max = l[1];
        for (int idx = 2; idx <= N; idx++) {
            l[idx] = Math.max(arr[idx], l[idx - 1] + arr[idx]);
            max = Math.max(max, l[idx]);
        }

        for (int ndx = N - 1; ndx >= 1; ndx--) {
            r[ndx] = Math.max(arr[ndx], r[ndx + 1] + arr[ndx]);
        }
    }
}
