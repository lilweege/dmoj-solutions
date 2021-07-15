import java.util.*;
import java.io.*;

public class ccc21s1 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		int N = Integer.parseInt(br.readLine());

		int[] heights = new int[N+1];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i <= N; i++) {
			heights[i] = Integer.parseInt(st.nextToken());
		}

		int[] widths = new int[N];
		st = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			widths[i] = Integer.parseInt(st.nextToken());
		}

		double totalArea = 0;
		for (int i = 0; i < N; i++) {
			int leftHeight = heights[i];
			int rightHeight = heights[i+1];
			int width = widths[i];

			double triangleArea = Math.abs(leftHeight - rightHeight) * width / 2.0f;
			double rectangleArea = Math.min(leftHeight, rightHeight) * width;
			double area = triangleArea + rectangleArea;
			totalArea += area;
		}

		System.out.println(totalArea);
	}
}