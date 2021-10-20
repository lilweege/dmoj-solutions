// https://leetcode.com/problems/counting-bits

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> numOnes(num + 1);
        for (int i = 0; i <= num; ++i) {
            numOnes[i] = bitset<32>(i).count();
        }
        return numOnes;
    }
};