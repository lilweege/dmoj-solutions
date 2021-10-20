// https://leetcode.com/problems/number-of-1-bits

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int num = 0;
        for (int i = 0; i < 32; ++i)
            num += (n >> i) & 1;
        return num;
    }
};