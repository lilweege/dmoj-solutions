import java.util.*;
import java.io.*;

// partial solution (7/15)
public class ccc21s5 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		final int maxA = (int)1e9;
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());

		Rule[] rules = new Rule[M];
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int X = Integer.parseInt(st.nextToken());
			int Y = Integer.parseInt(st.nextToken());
			int Z = Integer.parseInt(st.nextToken());
			rules[i] = new Rule(X, Y, Z);
		}

		int[] A = new int[N+1];
		Arrays.fill(A, 1);

		for (int i = 1; i <= N; i++) {
			for (Rule rule : rules) {
				if (rule.X <= i && i <= rule.Y) {
					A[i] = LCM(A[i], rule.Z);
				}
			}

			if (A[i] > maxA) {
				System.out.println("Impossible");
				return;
			}
		}

		for (Rule rule : rules) {
			int gcd = A[rule.X];
			for (int i = rule.X; i <= rule.Y; i++) {
				gcd = GCD(gcd, A[i]);
			}
			
			if (gcd != rule.Z) {
				System.out.println("Impossible");
				return;
			}
		}

		for (int i = 1; i <= N; i++) {
			System.out.print(A[i] + " ");
		}
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