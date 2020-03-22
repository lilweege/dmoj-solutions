import java.util.*;
import java.io.*;
public class s4 {
	public static int[] parent, rank;
	public static int n, m, d;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] nmd = br.readLine().split(" ");
		n = Integer.parseInt(nmd[0]);
		m = Integer.parseInt(nmd[1]);
		d = Integer.parseInt(nmd[2]);

		parent = new int[n+1];
		for (int i = 0; i <= n; i++) {
			parent[i] = i;
		}
		rank = new int[n+1];


		Edge[] edges = new Edge[m];
		for (int i = 0; i < m; i++) {
			String[] abc = br.readLine().split(" ");
			edges[i] = new Edge(Integer.parseInt(abc[0]), Integer.parseInt(abc[1]), Integer.parseInt(abc[2]), i+1 < n);
		}
		Arrays.sort(edges);

		int cnt = 0, mi = 0, days = 0;
		for (Edge e : edges) {
			if (merge(e.a, e.b)) {
				cnt++;
				mi = e.c;
				days += e.o ? 0 : 1;
				if (cnt == n - 1) {
					if (e.o) {
						System.out.println(days);
						return;
					}
					break;
				}
			}
		}

		for (int i = 0; i <= n; i++) {
			parent[i] = i;
		}
		for (Edge e : edges) {
			if (find(e.a) != find(e.b)) {
				if (e.c < mi || (e.o && e.c == mi)) {
					merge(e.a, e.b);
				}
				else if (e.o && e.c <= d) {
					days--;
					break;
				}
			}
		}
		System.out.println(days);
	}

	public static int find(int n) {
		if (parent[n] != n) {
			parent[n] = find(parent[n]);
		}
		return parent[n];
	}

	public static boolean merge(int a, int b) {
		int xroot = find(a);
		int yroot = find(b);
		if (xroot == yroot) {
			return false;
		}
		if (rank[xroot] > rank[yroot]) {
			parent[yroot] = xroot;
		}
		else {
			parent[xroot] = yroot;
		}
		if (rank[xroot] == rank[yroot]) {
			rank[yroot]++;
		}
		return true;
	}
}

class Edge implements Comparable<Edge> {
	public final int a;
	public final int b;
	public final int c;
	public final boolean o;

	public Edge(int a, int b, int c, boolean o) {
		this.a = a;
		this.b = b;
		this.c = c;
		this.o = o;
	}

	public int compareTo(Edge other) {
		if (this.c > other.c) return 1;
		if (this.c < other.c) return -1;
		return 0;
	}

	public String toString() {
		return "(" + this.a + ", " + this.b + ", " + this.c + ")";
	}
}
