import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 1차원 구간 합 + 나머지 특성
 */
public class Doit_005 {

    static int N, M;
    static long result;
    static long[] sum;
    static long[] count;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        /**
         * 합 배열 공식
         */
        sum = new long[N];
        st = new StringTokenizer(br.readLine());
        int cur = Integer.parseInt(st.nextToken());
        sum[0] = cur;
        for (int idx = 1; idx < N; idx++) {
            cur = Integer.parseInt(st.nextToken());
            sum[idx] = sum[idx - 1] + cur;
        }

        /**
         * 나머지 특성을 활용
         *
         * 주의할 점: (int)(sum[idx] % M);
         * (int)sum[idx] % M; 로 적을 경우 long 배열을 int 로 캐스팅 하면서 오버플로우가 발생한다.
         */
        result = 0;
        count = new long[M];
        for (int idx = 0; idx < N; idx++) {
            int reminder = (int)(sum[idx] % M);
            if (reminder == 0) {
                result++;
            }
            count[reminder]++;
        }

        for (int idx = 0; idx < M; idx++) {
            if (count[idx] > 1) {
                result += (count[idx] * (count[idx] - 1) / 2);
            }
        }

        System.out.println(result);

    }

}
