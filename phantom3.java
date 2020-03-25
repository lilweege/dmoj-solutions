import java.util.*;
import java.io.*;

public class The_Torture_Chamber {
	public static long m;
	public static long n;
	public static boolean[] sieve;
	public static ArrayList<Long> primes = new ArrayList<Long>();
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Long.parseLong(br.readLine());
		m = Long.parseLong(br.readLine());
		sieve = new boolean[20000010];
		System.out.println(countSegmentedSieve(m));
	}

	public static void sieve(long lim) {
		Arrays.fill(sieve, true);
		for (long i = 3; i <= (int)lim; i+=2) {
			if (sieve[(int)i]) {
				for (long j = i*i; j < lim; j += i) {
					sieve[(int)j] = false;
				}
				primes.add(i);
			}
		}
	}

	public static long countSegmentedSieve(long lim) {
		long cnt = 0;
		lim = (long)(Math.sqrt(lim));
		sieve(lim);
		Arrays.fill(sieve, true);
		long low = n;
		long high = m;

		for (int i = 0; i < primes.size(); i++) {
			long curPrime = primes.get(i);
			long loLim = low/curPrime * curPrime;
			if (loLim < low) {
				loLim += curPrime;
			}
			for (long j = loLim; j < high; j += curPrime) {
				sieve[(int)(j-low)] = false;
			}
			if (curPrime >= n && curPrime < m) {
				sieve[(int)(curPrime-low)] = true;
			}
		}

		for (long i = (low%2 == 0 ? low+1 : low); i < high; i += 2) {
			if (sieve[(int)(i-low)]) {
				cnt++;
			}
		}
		return cnt;
	}

}
