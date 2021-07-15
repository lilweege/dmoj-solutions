import java.util.*;
import java.io.*;

public class ccc21j4 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String bookshelf = br.readLine();

		int numberOfL = 0;
		int numberOfM = 0;
		for (int i = 0; i < bookshelf.length(); i++) {
			char book = bookshelf.charAt(i);
			if (book == 'L') {
				numberOfL++;
			}
			else if (book == 'M') {
				numberOfM++;
			}
		}

		int numberWrongInL = 0;
		int numberMediumInL = 0;
		int numberWrongInM = 0;
		int numberLargeInM = 0;
		for (int i = 0; i < numberOfL; i++) {
			char book = bookshelf.charAt(i);
			if (book != 'L') {
				numberWrongInL++;
				if (book == 'M') {
					numberMediumInL++;
				}
			}
		}
		for (int i = numberOfL; i < numberOfL + numberOfM; i++) {
			char book = bookshelf.charAt(i);
			if (book != 'M') {
				numberWrongInM++;
				if (book == 'L') {
					numberLargeInM++;
				}
			}
		}

		int numberOfSwaps = numberWrongInL + numberWrongInM
				- Math.min(numberMediumInL, numberLargeInM);
		
		System.out.println(numberOfSwaps);
	}
}