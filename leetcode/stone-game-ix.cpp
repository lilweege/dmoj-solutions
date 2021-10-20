// https://leetcode.com/problems/stone-game-ix

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n = size(stones);
        if (n == 1)
            return false;
        int cnt[3] = {0, 0, 0};
        // mod 3 = 0, 1, 2
        for (int x : stones)
            ++cnt[x%3];
        
        if (cnt[0] % 2 == 0)
            return cnt[1] != 0 && cnt[2] != 0;
        return cnt[2] > cnt[1] + 2 || cnt[1] > cnt[2] + 2;
    }
};