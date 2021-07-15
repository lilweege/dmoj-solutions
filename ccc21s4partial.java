import java.util.*;
import java.io.*;

// partial solution (7/15)
public class ccc21s4 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		int N = Integer.parseInt(st.nextToken());
		int W = Integer.parseInt(st.nextToken());
		int D = Integer.parseInt(st.nextToken());


		ArrayList<Integer>[] walkways = new ArrayList[N];
		for (int i = 0; i < N; i++) {
			walkways[i] = new ArrayList<Integer>();
		}

		for (int i = 0; i < W; i++) {
			st = new StringTokenizer(br.readLine());
			int A = Integer.parseInt(st.nextToken()) - 1;
			int B = Integer.parseInt(st.nextToken()) - 1;
			walkways[A].add(B);
		}

		int[] stations = new int[N];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			stations[i] = Integer.parseInt(st.nextToken());
		}


		for (int d = 0; d < D; d++) {
			st = new StringTokenizer(br.readLine());
			int X = Integer.parseInt(st.nextToken()) - 1;
			int Y = Integer.parseInt(st.nextToken()) - 1;

			int temp = stations[X];
			stations[X] = stations[Y];
			stations[Y] = temp;

			int depth = 0;
			boolean[] visited = new boolean[N];
			HashSet<Integer> waiting = new HashSet<>();
			Queue<Integer> queue = new LinkedList<>();
			visited[0] = true;
			queue.add(0);

			boolean done = false;
			while (!queue.isEmpty()) {
				Queue<Integer> breadth = queue;
				queue = new LinkedList<>();

				while (!breadth.isEmpty()) {
					int current = breadth.remove();

					if (current == N-1) {
						done = true;
						break;
					}

					// stay put
					waiting.add(current);

					// walk
					for (int next : walkways[current]) {
						if (!visited[next]) {
							visited[next] = true;
							queue.add(next);
						}
					}
				}

				// take subway
				if (waiting.contains(stations[depth] - 1)) {
					queue.add(stations[depth+1] - 1);
				}

				if (done) {
					break;
				}
				depth++;
			}

			System.out.println(depth);
		}
		
	}
}
