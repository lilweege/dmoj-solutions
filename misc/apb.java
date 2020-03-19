import java.util.*;
import java.io.*;
public class apb {
	public static void main(String[] args) throws Exception {
		/*
		System.out.println(isSmaller("11","5")); // -1
		System.out.println(isSmaller("5","11")); // 1
		System.out.println(isSmaller("5","6")); // 1
		System.out.println(isSmaller("6","5")); // -1
		System.out.println(isSmaller("5","5")); // 0
		*/
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		for (int i = 0; i < n; i++) {
			String[] line = br.readLine().split(" ");
			System.out.println(APlusB(line[0], line[1]));
		}
	}
	
	public static String APlusB(String a, String b) {
		String res = "";
		boolean aIsNeg = a.charAt(0) == '-';
		boolean bIsNeg = b.charAt(0) == '-';
		if (aIsNeg == bIsNeg) {
			if (aIsNeg) {
				res = "-" + trimZeros(add(a.substring(1), b.substring(1)));
			}
			else {
				res = trimZeros(add(a, b));
			}
		}
		else {
			if (aIsNeg) {
				a = a.substring(1);
				int smaller = isSmaller(b, a);
				if (smaller > 0) {
					res = "-" + trimZeros(sub(a, b));
				}
				else if (smaller < 0) {
					res = trimZeros(sub(b, a));
				}
				else {
					return "0";
				}
			}
			else {
				b = b.substring(1);
				int smaller = isSmaller(b, a);
				if (smaller > 0) {
					res = trimZeros(sub(a, b));
				}
				else if (smaller < 0) {
					res = "-" + trimZeros(sub(b, a));
				}
				else {
					return "0";
				}
			}
		}
		
		return res;
	}
	
	public static int isSmaller(String a, String b) {
		int lenA = a.length();
		int lenB = b.length();
		
		if (lenA < lenB) {
			return 1;
		}
		
		if (lenA > lenB) {
			return -1;
		}
		
		for (int i = 0; i < lenA; i++) {
			if (a.charAt(i) < b.charAt(i)) {
				return 1;
			}
			if (a.charAt(i) > b.charAt(i)) {
				return -1;
			}
		}
		
		return 0;
	}
	
	public static String trimZeros(String str) {
		char[] chars = str.toCharArray();
		int s;
		for (s = 0; s < chars.length; s++) {
			if (chars[s] != '0') {
				break;
			}
		}
		return new String(Arrays.copyOfRange(chars, s, chars.length));
	}
	
	public static String add(String a, String b) {
		String res = "";
		int lenA = a.length();
		int lenB = b.length();
		if (lenA > lenB) {
			String t = a;
			a = b;
			b = t;
			int nt = lenA;
			lenA = lenB;
			lenB = nt;
		}
		
		int lenDiff = lenB - lenA;
		int carry = 0;
		for (int i = lenA- 1; i >= 0; i--) {
			int sum = (a.charAt(i) - '0') + (b.charAt(i + lenDiff) - '0') + carry;
			res += (char)(sum % 10 + '0');
			carry = sum / 10;
		}
		
		for (int i = lenDiff-1; i >= 0; i--) {
			int sum = b.charAt(i) - '0' + carry;
			res += (char)(sum % 10 + '0');
			carry = sum / 10;
		}
		
		if (carry > 0) {
			res += (char)(carry + '0');
		}
		
		return new StringBuilder(res).reverse().toString();
	}
	
	public static String sub(String a, String b) {
		String res = "";
		int lenA = a.length();
		int lenB = b.length();
		int lenDiff = lenA - lenB;
		int carry = 0;
		
		for (int i = lenB-1; i >= 0; i--) {
			int diff = (a.charAt(i + lenDiff) - '0') - (b.charAt(i) - '0') - carry;
			if (diff < 0) {
				diff += 10;
				carry = 1;
			}
			else {
				carry = 0;
			}
			res += String.valueOf(diff);
		}
		
		for (int i = lenDiff-1; i >= 0; i--) {
			if (a.charAt(i) == '0' && carry > 0) {
				res += "9";
				continue;
			}
			int diff = a.charAt(i) - '0' - carry;
			if (i > 0 || diff > 0) {
				res += String.valueOf(diff);
			}
			carry = 0;
		}
		return new StringBuilder(res).reverse().toString();
	}
}