import java.util.*;
import java.io.*;

public class ccc21j2 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int N = Integer.parseInt(br.readLine());
		String winnerName = "";
		int highestBid = -1;

		for (int i = 0; i < N; i++) {
			String name = br.readLine();
			int bid = Integer.parseInt(br.readLine());
			
			if (highestBid < bid) {
				highestBid = bid;
				winnerName = name;
			}
		}

		System.out.println(winnerName);
	}
}