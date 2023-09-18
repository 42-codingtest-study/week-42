import java.io.*;
import java.util.Arrays;

public class BOJ1546 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

	public static void main(String[] args) throws IOException {
		int N = Integer.parseInt(br.readLine());
		int M = Integer.MIN_VALUE;
		int sum = 0;

		int[] inputScores = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

		/**
		 * (a/M + b/M + c/M) * 100 == (a + b + c) / M * 100
		 * 새로운 값을 구할 필요가 없다.
		 */
		for (int score : inputScores) {
			if (M < score) M = score;
			sum += score;
		}

		double newAvg = (double) sum / M * 100 / N;
		bw.write(newAvg + "\n");
		bw.flush();
		bw.close();
	}
}
