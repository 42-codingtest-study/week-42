import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
/**
 * Q) 배열 저장을 왜 0 ~ N-1 에서 1 ~ N 로 바꾸니까 틀리지?
 */

/**
 * N개의 수가 좋은수가 되는지 모두 확인해야 한다. N개 중 하나의 수가 좋은수인지 확인하기 위해서 N^2 를 사용하면 총 N^3 시간복잡도가 걸린다. 두 수가 좋은수인지 확인하는 과정을 투포인터를 활용한다면 총
 * N^2로 풀이가 가능해진다.
 * <p>
 * i번째 수가 서로 다른 두 수에 의해 좋은수가 되는지에서 자기 자신이 더해지는 것은 안된다. (i == i + 0) N개의 수에는 음수도 가능하다.
 */
public class Doit_008 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        long[] arr = new long[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int idx = 0; idx < N; idx++) {
            arr[idx] = Long.parseLong(st.nextToken());
        }

        /**
         * 투포인터를 사용하기 위해서는 정렬되어야 한다.
         * N 의 최대 개수가 2000 개 이므로 sort() 가 가능하다.
         */
        Arrays.sort(arr);

        /**
         * 투포인터 사용
         * 원하는 값을 더해가며 찾는 방식으로 start, end 를 양 끝에 위치한다
         * 원하는 값이 나오더라도 투 포인터가 가리키는 값이 원하는 값과 같은 경우는 제외시켜야 한다.
         */
        int count = 0;
        long sum = 0;
        for (int cur = 0; cur < N; cur++) {
            long target = arr[cur];
            int start = 0;
            int end = N - 1;

            while (start < end) {
                sum = arr[start] + arr[end];
                if (sum == target) {
                    if (start != cur && end != cur) {
                        count++;
                        break;
                    } else if (start == cur) {
                        start++;
                    } else if (end == cur){
                        end--;
                    }
                } else if (sum < target) {
                    start++;
                } else {
                    end--;
                }
            }
        }
        System.out.println(count);
    }

}
