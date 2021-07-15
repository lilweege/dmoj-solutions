import java.util.*;
import java.io.*;

// partial solution (4/15)
public class ccc21s3 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		int N = Integer.parseInt(br.readLine());
		if (N == 1) {
			System.out.println(0);
			return;
		}

		Friend[] friends = new Friend[N];
		int maxP = 0;
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			int P = Integer.parseInt(st.nextToken());
			int W = Integer.parseInt(st.nextToken());
			int D = Integer.parseInt(st.nextToken());
			friends[i] = new Friend(P, W, D);
			maxP = Math.max(maxP, P);
		}

		long best = Long.MAX_VALUE;
		for (int c = 0; c <= maxP; c++) {
			best = Math.min(best, totalCost(c, friends));
		}
		System.out.println(best);
	}

	static long totalCost(int c, Friend[] friends) {
		long cost = 0;
		for (Friend friend : friends) {
			long dist = Math.abs(friend.P - c);
			if (dist > friend.D) {
				cost += (dist - friend.D) * friend.W;
			}
		}
		return cost;
	}
}

class Friend {
	int P;
	int W;
	int D;

	public Friend(int P, int W, int D) {
		this.P = P;
		this.W = W;
		this.D = D;
	}
}