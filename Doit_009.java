import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * S와 P 가 모두 최대 100만 P가 적당한 가운데 숫자라면 50만개의 약 50만번 숫자를 하나씩 확인해야 한다.
 * 시간제한 2초, 2억 연산내 가능해야 한다.
 *
 * 슬라이딩 윈도우를 사용하면 매번 연산하지 않아도 된다. O(N)
 *
 * 요구되는 조건을 기록한 배열과
 * 확인한 ch의 개수를 체크하는 배열을 비교하여 경우의 수를 카운팅한다.
 *
 * <주의사항>
 * 개별 ch 카운팅되는 시점은 개수가 맞아 떨어졌을 때 한 번이다.
 * 카운팅 되는 시점은 requiredArr 와 값이 같을 때 단, 한 번이다.
 * 때문에 requiredArr 보다 많은 ch 를 사용하더라도 그만큼 기록되어져야 한다.
 *
 */
public class Doit_009 {

    static int[] requiredArr;
    static int[] myArr;
    static int requiredCount;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int S = Integer.parseInt(st.nextToken());
        int P = Integer.parseInt(st.nextToken());
        /**
         * 요구사항을 담는 배열을 초기화
         */
        requiredArr = new int[4];
        myArr = new int[4];
        requiredCount = 0;
        int result = 0;

        char[] inputValues = br.readLine().toCharArray();

        st = new StringTokenizer(br.readLine());
        for (int idx = 0; idx < 4; idx++) {
            requiredArr[idx] = Integer.parseInt(st.nextToken());
            if (requiredArr[idx] == 0) {
                requiredCount++;
            }
        }

        /**
         * 초기 슬라이딩 윈도우 셋팅
         * P 만큼 연산
         */
        for (int idx = 0; idx < P; idx++) {
            add(inputValues[idx]);
        }
        /**
         * 초기 값의 만족 유무 처리
         */
        if (requiredCount == 4) {
            result++;
        }
        /**
         * 슬라이딩 윈도우
         */
        for (int end = P; end < S; end++) {
            int start = end - P;

            add(inputValues[end]);
            remove(inputValues[start]);
            if (requiredCount == 4) {
                result++;
            }
        }
        System.out.println(result);

    }

    private static void remove(char c) {
        switch (c) {
            case 'A':
                if (myArr[0] == requiredArr[0]) {
                    requiredCount--;
                }
                myArr[0]--;
                break;
            case 'C':
                if (myArr[1] == requiredArr[1]) {
                    requiredCount--;
                }
                myArr[1]--;
                break;
            case 'G':
                if (myArr[2] == requiredArr[2]) {
                    requiredCount--;
                }
                myArr[2]--;
                break;
            case 'T':
                if (myArr[3] == requiredArr[3]) {
                    requiredCount--;
                }
                myArr[3]--;
                break;
        }
    }

    private static void add(char c) {
        switch (c) {
            case 'A':
                myArr[0]++;
                if (myArr[0] == requiredArr[0]) {
                    requiredCount++;
                }
                break;
            case 'C':
                myArr[1]++;
                if (myArr[1] == requiredArr[1]) {
                    requiredCount++;
                }
                break;
            case 'G':
                myArr[2]++;
                if (myArr[2] == requiredArr[2]) {
                    requiredCount++;
                }
                break;
            case 'T':
                myArr[3]++;
                if (myArr[3] == requiredArr[3]) {
                    requiredCount++;
                }
                break;
        }

    }

}
