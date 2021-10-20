// https://leetcode.com/problems/roman-to-integer

class Solution {
    public static int symbolValue(char c) {
		return switch (c) {
			case 'I' -> 1;
			case 'V' -> 5;
			case 'X' -> 10;
			case 'L' -> 50;
			case 'C' -> 100;
			case 'D' -> 500;
			case 'M' -> 1000;
			// default -> throw new IllegalArgumentException("The value of '" + c + "' was invalid.");
            default -> 0;
		};
	}
    public int romanToInt(String s) {
		if (s.isEmpty()) return 0;
		int val = 0,
			cur = symbolValue(s.charAt(0));
		for (int i = 1; i < s.length(); ++i) {
			int nxt = symbolValue(s.charAt(i));
			val += (cur >= nxt ? cur : -cur);
			cur = nxt;
		}
		return val + cur;
    }
}