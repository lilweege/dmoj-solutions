// https://leetcode.com/problems/palindrome-number

public class Solution {
    public bool IsPalindrome(int x) {
        string init = x.ToString();
        char[] c = init.ToCharArray();
        string pal = "";
        for (int i = c.Length - 1; i >= 0; i--) pal+=c[i];
        return pal == init;
    }
}