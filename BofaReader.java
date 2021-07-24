import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

class BofaReader {
	private BufferedReader br;
	private StringTokenizer st;
	
	public BofaReader(InputStreamReader streamReader) {
		br = new BufferedReader(streamReader);
	}

	public String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	public long readLong() throws IOException {
		return Long.parseLong(next());
	}

	public char readCharacter() throws IOException {
		return next().charAt(0);
	}

	public int readInt() throws IOException {
		return Integer.parseInt(next());
	}

	public double readDouble() throws IOException {
		return Double.parseDouble(next());
	}

	public String readLine() throws IOException {
		return br.readLine().trim();
	}
}