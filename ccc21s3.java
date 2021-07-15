import java.util.*;
import java.io.*;

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
		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			int P = Integer.parseInt(st.nextToken());
			int W = Integer.parseInt(st.nextToken());
			int D = Integer.parseInt(st.nextToken());
			friends[i] = new Friend(P, W, D);
		}
		Arrays.sort(friends);


		int lo = 0;
		int hi = (int)1e9;
		while (lo + 1 < hi) {
			int mid = (lo + hi) / 2;
			long leftSum = totalCost(mid-1, friends);
			long rightSum = totalCost(mid, friends);
			if (leftSum > rightSum) {
				lo = mid;
			}
			else {
				hi = mid;
			}
		}

		System.out.println(totalCost(lo, friends));
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

class Friend implements Comparable<Friend> {
	int P;
	int W;
	int D;

	public Friend(int P, int W, int D) {
		this.P = P;
		this.W = W;
		this.D = D;
	}

	@Override
	public int compareTo(Friend other) {
		if (this.P > other.P) return 1;
		if (this.P < other.P) return -1;
		return 0;
	}
}