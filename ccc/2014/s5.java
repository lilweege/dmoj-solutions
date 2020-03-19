import java.util.*;
import java.io.*;
public class s5 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int[] best = new int[n+1];
		int[] prev = new int[n+1];
		double[] dist = new double[n+1];
		
		Point[] points = new Point[n+1];
		points[0] = new Point(0, 0);
		for (int i = 1; i <= n; i++) {
			points[i] = new Point(in.nextInt(), in.nextInt());
		}
		
		ArrayList<Pair> pairs = new ArrayList<Pair>();
		for (int a = 0; a <= n; a++) {
			for (int b = a+1; b <= n; b++) {
				pairs.add(new Pair(euclidDist(points[a], points[b]), a, b));
			}
		}
		
		Collections.sort(pairs, Pair::compareTo);
		
		for (Pair pair : pairs) {
			double cost = pair.dist;
			int a = pair.a;
			int b = pair.b;
			if (dist[a] != cost) {
				prev[a] = best[a];
				dist[a] = cost;
			}
			if (dist[b] != cost) {
				prev[b] = best[b];
				dist[b] = cost;
			}
			
			if (a == 0) {
				best[a] = Math.max(best[a], prev[b]);
			}
			else {
				best[a] = Math.max(best[a], prev[b]+1);
				best[b] = Math.max(best[b], prev[a]+1);
			}
		}
		
		System.out.println(best[0] + 1);
	}
	
	public static double euclidDist(Point a, Point b) {
		return Math.sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
	}
}

class Point {
	public final int x;
	public final int y;
	public Point(int x, int y) {
		this.x = x;
		this.y = y;
	}
}

class Pair {
	public final double dist;
	public final int a;
	public final int b;
	
	public Pair(double dist, int a, int b) {
		this.dist = dist;
		this.a = a;
		this.b = b;
	}

	public int compareTo(Pair other) {
		if (this.dist > other.dist) return 1;
		if (this.dist < other.dist) return -1;
		return 0;
	}
}