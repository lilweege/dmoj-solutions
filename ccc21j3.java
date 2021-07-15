import java.util.*;
import java.io.*;

public class ccc21j3 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String lastDirection = "";
		while (true) {
			String N = br.readLine();
			if (N.equals("99999"))
				break;
			
			String numberOfSteps = N.substring(2);
			
			int firstDigit = N.charAt(0) - '0';
			int secondDigit = N.charAt(1) - '0';

			String currentDirection;
			if ((firstDigit + secondDigit) % 2 == 1) {
				currentDirection = "left";
			}
			else if (firstDigit + secondDigit == 0) {
				currentDirection = lastDirection;
			}
			else {
				currentDirection = "right";
			}
			
			System.out.println(currentDirection + " " + numberOfSteps);
			lastDirection = currentDirection;
		}
	}
}