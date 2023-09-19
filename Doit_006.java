import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * 투 포인터를 활용해 시간복잡도 NlogN 을 N 으로 줄이기
 */
public class Doit_006 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());

        int[] arr = new int[N + 1];

        for (int idx = 1; idx <= N; idx++) {
            arr[idx] = idx;
        }

        /**
         * 투 포인터 사용
         * 연속되는 수를 찾으므로 start, end 를 처음으로 셋팅
         * end가 옮길때는 옮기고 더하기
         * start가 올라갈때는 빼고 옮기기
         */
        int start = 1;
        int end = 1;
        int sum = arr[1];
        int count = 1;
        while (start < N) {
            if (sum < N) sum += arr[++end];
            else if (sum > N) sum -= arr[start++];
            else {
                count++;
                sum += arr[++end];
            }
        }

        System.out.println(count);
    }

}
