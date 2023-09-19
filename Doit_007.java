import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * 배열의 크기는 최대 1.5만이므로 nlogn 이 가능하다.
 * sort() 를 통해 정렬한 후 투포인터를 사용해보자.
 */
public class Doit_007 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[N + 1];
        for (int idx = 1; idx <= N; idx++) {
            arr[idx] = Integer.parseInt(st.nextToken());
        }

        /**
         * 무작위로 들어온 배열을 정렬한다. 투포인터를 사용하기 위해서는 정렬되어야 한다.
         */
        Arrays.sort(arr);

        /**
         * 두 숫자의 합이 M이 되는 경우의 수를 구하는 문제로,
         * start, end 를 양 끝에 셋팅한다.
         * M보다 작으면 start 를 올려 sum 을 올린다.
         * M보다 크면 end 를 내려 sum 을 내린다.
         * 두 숫자 재료를 사용해여 하므로 start와 end는 서로 달라야 한다.
         */
        int start = 1;
        int end = N;
        int sum = 0;
        int count = 0;
        while (start < end) {
            sum = arr[start] + arr[end];
            if (sum < M) start++;
            else if (sum > M) end--;
            else {
                count++;
                start++;
                end--;
            }
        }
        System.out.println(count);
    }

}
