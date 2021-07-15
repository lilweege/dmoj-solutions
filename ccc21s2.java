import java.util.*;
import java.io.*;

public class ccc21s2 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int M = Integer.parseInt(br.readLine());
		int N = Integer.parseInt(br.readLine());
		int K = Integer.parseInt(br.readLine());

		boolean[] rowParity = new boolean[M];
		boolean[] colParity = new boolean[N];

		for (int k = 0; k < K; k++) {
			String line = br.readLine();
			char direction = line.charAt(0);
			int x = Integer.parseInt(line.substring(2)) - 1;

			if (direction == 'C') {
				colParity[x] = !colParity[x];
			}
			else {
				rowParity[x] = !rowParity[x];
			}
		}

		int numGoldCells = 0;
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (rowParity[i] ^ colParity[j]) {
					numGoldCells++;
				}
			}
		}

		System.out.println(numGoldCells);
	}
}