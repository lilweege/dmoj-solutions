import java.util.*;
import java.io.*;

// partial solution (10/15)
public class ccc21s2 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int M = Integer.parseInt(br.readLine());
		int N = Integer.parseInt(br.readLine());
		int K = Integer.parseInt(br.readLine());

		boolean[][] canvas = new boolean[M][N];
		int numGoldCells = 0;

		for (int k = 0; k < K; k++) {
			String line = br.readLine();
			char direction = line.charAt(0);
			int x = Integer.parseInt(line.substring(2)) - 1;

			if (direction == 'C') {
				for (int i = 0; i < M; i++) {
					canvas[i][x] = !canvas[i][x];
					if (canvas[i][x]) {
						numGoldCells++;
					}
					else {
						numGoldCells--;
					}
				}
			}
			else {
				for (int j = 0; j < N; j++) {
					canvas[x][j] = !canvas[x][j];
					if (canvas[x][j]) {
						numGoldCells++;
					}
					else {
						numGoldCells--;
					}
				}
			}
		}

		System.out.println(numGoldCells);
	}
}