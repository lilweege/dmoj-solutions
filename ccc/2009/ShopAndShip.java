import java.util.*;
import java.io.*;
public class ShopAndShip {
	public static FastReader r = new FastReader();
	public static int n;
	public static int[][] ship;
	public static int[] shop;
	public static boolean[] visited;
	public static int INF = 999999999;
	public static void main(String[] args) throws Exception {
		n = r.nextInt();
		ship = new int[n+1][];
		shop = new int[n+1];
		visited = new boolean[n+1];

		for (int i = 1; i <= n; i++) {
			ship[i] = new int[i+1];
			for (int j = 1; j < i; j++) {
				ship[i][j] = INF;
			}
			ship[i][i] = 0;
			shop[i] = INF;
			visited[i] = false;
		}

		int t = r.nextInt();
		for (int i = 0; i < t; i++) {
			int x = r.nextInt();
			int y = r.nextInt();
			int cost = r.nextInt();
			if (x <= n && y <= n) {
				ship[Math.max(x, y)][Math.min(x, y)] = cost;
			}
		}

		int k = r.nextInt();
		for (int i = 0; i < k; i++) {
			int city = r.nextInt();
			int cost = r.nextInt();
			if (city <= n) {
				shop[city] = cost;
			}
		}

		int dest = r.nextInt();
		int cost = 0;
		int prev = 0;
		do {
			prev = cost;
			cost = getCheapest(dest);
		} while (cost != prev);

		cost = 0;
		prev = 0;
		do {
			prev = cost;
			for (int i = 1; i <= n; i++) {
				visited[i] = false;
			}
			cost = getCheapest(dest);
		} while (cost != prev);

		System.out.println(cost);
	}

	public static int getCheapest(int city) {
		if (visited[city]) {
			return shop[city];
		}
		visited[city] = true;

		int cheapest = shop[city];
		for (int c = 1; c <= n; c++) {
			cheapest = Math.min(cheapest, ship[Math.max(c, city)][Math.min(c, city)] + getCheapest(c));
		}
		shop[city] = cheapest;

		return cheapest;
	}




	static class FastReader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;
        public FastReader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
        public FastReader(String file_name) throws IOException {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
		public int[] readLineAsIntArr() throws IOException {
			byte[] buf = new byte[64]; // line length
			int cnt = 0, c;
			while ((c = read()) != -1) {
				if (c == '\n') {
					break;
				}
				buf[cnt++] = (byte) c;
			}
			return Arrays.stream(new String(buf, 0, cnt).split(" ")).mapToInt(Integer::parseInt).toArray();
		}
        public String readLine() throws IOException {
            byte[] buf = new byte[64]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n') {
					break;
				}
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }
        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ') {
				c = read();
			}
            boolean neg = (c == '-');
            if (neg) {
				c = read();
			}
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (neg) {
				return -ret;
			}
            return ret;
        }
        public long nextLong() throws IOException {
            long ret = 0;
            byte c = read();
            while (c <= ' ') {
				c = read();
			}
            boolean neg = (c == '-');
            if (neg) {
				c = read();
			}
            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');
            if (neg) {
				return -ret;
			}
            return ret;
        }
        public double nextDouble() throws IOException {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ') {
				c = read();
			}
            boolean neg = (c == '-');
            if (neg) {
				c = read();
			}
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }
            if (neg) {
				return -ret;
			}
            return ret;
        }
        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1) {
				buffer[0] = -1;
			}
        }
        private byte read() throws IOException {
            if (bufferPointer == bytesRead) {
				fillBuffer();
			}
            return buffer[bufferPointer++];
        }
        public void close() throws IOException {
            if (din == null) {
				return;
			}
            din.close();
        }
    }
}
