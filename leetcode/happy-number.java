class Solution {
    public int sq(int x) { return x * x; }
    
    public boolean isHappy(int n) {
        int loops = 50;
        while (--loops > 0) {
            if (n == 1)
                return true;

            int t = 0;
            for (char num : String.valueOf(n).toCharArray())
                t += sq(Character.getNumericValue(num));
            n = t;
        }
        return false;
    }
}