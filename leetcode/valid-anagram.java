// https://leetcode.com/problems/valid-anagram

class Solution {
    public boolean isAnagram(String s, String t) {
        char[] one = s.toCharArray();
		char[] two = t.toCharArray();
		Arrays.sort(one);
		Arrays.sort(two);
		return String.valueOf(one).equals(String.valueOf(two));

    }
}
