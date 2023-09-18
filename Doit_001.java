import java.io.*;

/**
 * 고려해야할 것
 * - 최대 시간복잡도: N, 단순한 덧셈 계산
 * - 입력을 숫자(int, long)로 받을 경우에 최대 길이가 100이므로 범위를 넘어가게 된다. 그러므로 문자열로 받은 후에 각 자리의 숫자를 더하는 형식으로 계산 
 */

public class BOJ11720 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	public static void main(String[] args) throws IOException {
		int N = Integer.parseInt(br.readLine());

		/**
		 * 문자열을 String이 아닌 char[]로 받아서 계산
		 */
		char[] inputNum = br.readLine().toCharArray();
		int sum = 0;

		for (char c : inputNum) {
			sum += c - '0';
		}

		bw.write(sum + "\n");
		bw.flush();
		bw.close();
	}
}
