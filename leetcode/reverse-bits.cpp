class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev = 0;
        for (int i = 0; i < 32/2; ++i) {
            uint32_t low = (1 << (i));
            uint32_t high = (1 << (31-i));
            if (n & low) rev |= high;
            if (n & high) rev |= low;
        }
        return rev;
    }
};