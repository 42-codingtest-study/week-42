import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;

/**
 * 시간제한 2.4초 == 약 2.4억 연산
 * 최대 L 구간의 최소값을 구하는 문제이다.
 * 시작할 때 1개의 값만 담는다.
 * 그러나 끝은 L 구간으로 끝난다.
 * 숫자와 구간의 개수는 최대 500만이다.
 * 매번 구간별로 최소값을 구하려면 O(N^2) 의 시간복잡도가 발생한다.
 * 자료구로를 덱을 활용해 최소값을 다소 쉽게 관리한다.
 * 슬라이딩 윈도우를 통해 시간 복잡도를 O(N^2)에서 O(N)으로 줄인다.
 */

/**
 * 덱에 들어간 노드 중 구간을 벗어난 노드를 찾기 위해 값과 인덱스를 함께 저장한다.
 */
public class BOJ_010 {
    static class Node {
        public int index;
        public int value;

        Node(int index, int value) {
            this.index = index;
            this.value = value;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(st.nextToken());
        int l = Integer.parseInt(st.nextToken());

        Deque<Node> deque = new LinkedList<>();

        /**
         * 슬라이딩 윈도우
         */
        st = new StringTokenizer(br.readLine());
        for (int idx = 1; idx <= n; idx++) {
            int value = Integer.parseInt(st.nextToken());

            /**
             * 덱을 활용해 맨 왼쪽에 최소값을 유지하는 스킬
             */
            while (!deque.isEmpty() && deque.getLast().value > value) {
                deque.removeLast();
            }
            deque.addLast(new Node(idx, value));
            if (!deque.isEmpty() && (idx - deque.getFirst().index) >= l) {
                deque.removeFirst();
            }

            bw.write(deque.getFirst().value + " ");
        }
        bw.flush();
        bw.close();
    }

}