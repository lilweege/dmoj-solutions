import java.util.*;
import java.io.*;

public class ccc21s5 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		final int maxA = (int)1e9;
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());

		int[] segTree1 = new int[4 * N + 1]; // gcds
		int[] segTree2 = new int[4 * N + 1]; // sequence
		boolean[] isNode = new boolean[4 * N + 1];
		Arrays.fill(segTree1, 1);

		Rule[] rules = new Rule[M];
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int X = Integer.parseInt(st.nextToken());
			int Y = Integer.parseInt(st.nextToken());
			int Z = Integer.parseInt(st.nextToken());
			rules[i] = new Rule(X, Y, Z);
			update(segTree1, X, Y, Z, N);
		}

		build(segTree1, segTree2, isNode, N);

		for (Rule rule : rules) {
			int gcd = query(segTree2, rule.X, rule.Y, N);
			if (gcd != rule.Z || gcd > maxA) {
				System.out.println("Impossible");
				return;
			}
		}

		print(segTree2, isNode, N);
	}


	// segment tree 1
	public static void update(int[] t, int x, int y, int z, int n) {
		update(t, x-1, y-1, z, 0, n-1, 1);
	}
	public static void update(int[] t, int x, int y, int z, int l, int r, int i) {
		if (l >= x && r <= y) {
			t[i] = LCM(t[i], z);
		}
		else if (x <= r && y >= l) {
			int m = (l + r) / 2;
			update(t, x, y, z, l  , m, i*2  );
			update(t, x, y, z, m+1, r, i*2+1);
		}
	}


	// segment tree 2
	public static void build(final int[] t1, int[] t2, boolean[] s, int n) {
		build(t1, t2, s, 0, n-1, 1, 1);
	}
	public static void build(final int[] t1, int[] t2, boolean[] s, int l, int r, int i, int v) {
		v = LCM(v, t1[i]);
		if (l == r) {
			t2[i] = v;
			s[i] = true;
		}
		else {
			int m = (l + r) / 2;
			build(t1, t2, s, l  , m, i*2  , v);
			build(t1, t2, s, m+1, r, i*2+1, v);
			t2[i] = GCD(t2[i*2], t2[i*2+1]);
		}
	}


	public static int query(int[] t, int x, int y, int n) {
		return query(t, x-1, y-1, 0, n-1, 1);
	}
	public static int query(int[] t, int x, int y, int l, int r, int i) {
		if (l >= x && r <= y) {
			return t[i];
		}
		else if (x <= r && y >= l) {
			int m = (l + r) / 2;
			return GCD(
				query(t, x, y, l  , m, i*2  ),
				query(t, x, y, m+1, r, i*2+1));
		}
		return 0;
	}


	public static void print(int[] t, boolean[] s, int n) {
		print(t, s, n, 1);
		System.out.println();
	}
	public static void print(int[] t, boolean[] s, int n, int i) {
		if (i > n * 4)
			return;
		print(t, s, n, i * 2);
		if (s[i])
			System.out.print(t[i] + " ");
		print(t, s, n, i * 2 + 1);
	}


	public static int LCM(int a, int b) {
		return (a * b) / GCD(a, b);
	}

	public static int GCD(int a, int b) {
		if (b == 0) {
			return a;
		}
		else {
			return GCD(b, a % b);
		}
	}
}

class Rule {
	int X;
	int Y;
	int Z;

	public Rule(int X, int Y, int Z) {
		this.X = X;
		this.Y = Y;
		this.Z = Z;
	}
}