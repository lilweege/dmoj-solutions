import java.util.*;
import java.io.*;

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
			// one-way, backwards
			walkways[B].add(A);
		}

		int[] walkingDistance = new int[N];
		Arrays.fill(walkingDistance, (int)2e5+1);
		walkingDistance[N-1] = 0;

		Queue<Integer> queue = new LinkedList<>();
		queue.add(N-1);
		while (!queue.isEmpty()) {
			int current = queue.remove();
			for (int next : walkways[current]) {
				if (walkingDistance[next] > walkingDistance[current] + 1) {
					walkingDistance[next] = walkingDistance[current] + 1;
					queue.add(next);
				}
			}
		}

		// fake multiset
		// time, count
		TreeMap<Integer, Integer> totalTimes = new TreeMap<>();

		int[] stations = new int[N];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			stations[i] = Integer.parseInt(st.nextToken()) - 1;
			multisetInsert(totalTimes, time(i, walkingDistance, stations));
		}

		for (int d = 0; d < D; d++) {
			st = new StringTokenizer(br.readLine());
			int X = Integer.parseInt(st.nextToken()) - 1;
			int Y = Integer.parseInt(st.nextToken()) - 1;

			multisetRemove(totalTimes, time(X, walkingDistance, stations));
			multisetRemove(totalTimes, time(Y, walkingDistance, stations));
			int temp = stations[X];
			stations[X] = stations[Y];
			stations[Y] = temp;
			multisetInsert(totalTimes, time(X, walkingDistance, stations));
			multisetInsert(totalTimes, time(Y, walkingDistance, stations));

			System.out.println(totalTimes.firstKey());
		}
	}

	static void multisetInsert(Map<Integer, Integer> map, int val) {
		int count = map.getOrDefault(val, 0);
		map.put(val, count + 1);
	}

	static void multisetRemove(Map<Integer, Integer> map, int val) {
		int count = map.get(val);
		if (count == 1) {
			map.remove(val);
		}
		else {
			map.put(val, count - 1);
		}
	}

	static int time(int station, int[] walkingDistance, int[] stations) {
		return station + walkingDistance[stations[station]];
	}
}
