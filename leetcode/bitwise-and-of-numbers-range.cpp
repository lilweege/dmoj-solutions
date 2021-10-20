// https://leetcode.com/problems/bitwise-and-of-numbers-range

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        while (n > m)
            n &= n - 1;
        return n;
    }
};