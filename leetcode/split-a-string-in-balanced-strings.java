class Solution {
    public int balancedStringSplit(String s) {
        int diff = 0;
        int res = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == 'R') {
                diff++;
            }
            if (s.charAt(i) == 'L') {
                diff--;
            }
            if (diff == 0) {
                res++;
            }
        }
        return res;
    }
}