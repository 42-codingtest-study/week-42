import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Doit_002 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int count = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int max = 0;
        int sum = 0;
        double res = 0;

        for (int idx = 0; idx < count; idx++) {
            int score = Integer.parseInt(st.nextToken());
            if (score > max)
                max = score;
            sum += score;
        }
        res = sum / (double)max * 100 / count;
        System.out.println(res);
    }

}