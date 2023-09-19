import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 1차원 구간 합 풀이 법
 */
public class Doit_003 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int[] sum;

        /**
         * 1. 합 배열 공식
         */
        sum = new int[N + 1];
        st = new StringTokenizer(br.readLine());
        for (int idx = 1; idx <= N; idx++) {
            sum[idx] = sum[idx - 1] + Integer.parseInt(st.nextToken());
        }

        /**
         * 2. 구간 합 공식을 통한 값 도출
         */
        for (int idx = 1; idx <= M; idx++) {
            st = new StringTokenizer(br.readLine());
            int from = Integer.parseInt(st.nextToken());
            int to = Integer.parseInt(st.nextToken());
            System.out.println(sum[to] - sum[from - 1]);
        }
    }

}
