import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * 2차원 구간 합 풀이 법
 */
public class Doit_004 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        /**
         * 1. 배열에 값 저장
         */
        int[][] arr = new int[N + 1][N + 1];
        for (int idx = 1; idx <= N; idx++) {
            st = new StringTokenizer(br.readLine());
            for (int jdx = 1; jdx <= N; jdx++) {
                arr[idx][jdx] = Integer.parseInt(st.nextToken());
            }
        }

        /**
         * 2. 합 공식을 활용한 합 배열 생성
         */
        int[][] sum = new int[N + 1][N + 1];
        for (int idx = 1; idx <= N; idx++) {
            for (int jdx = 1; jdx <= N; jdx++) {
                sum[idx][jdx] = sum[idx][jdx - 1] + sum[idx - 1][jdx] - sum[idx - 1][jdx - 1] + arr[idx][jdx];
            }
        }

        /**
         * 3. 구간 합 공식을 활용한 값 도출
         */
        for (int idx = 1; idx <= M; idx++) {
            st = new StringTokenizer(br.readLine());
            int x1 = Integer.parseInt(st.nextToken());
            int y1 = Integer.parseInt(st.nextToken());
            int x2 = Integer.parseInt(st.nextToken());
            int y2 = Integer.parseInt(st.nextToken());

//            System.out.println(sum[y2][x2] - sum[y1 - 1][x2] - sum[y2][x1 - 1] + sum[y1 - 1][x1 - 1]);
            System.out.println(sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1]);
        }
    }

}
