// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = size(nums);
        int numJumps = 0;
        int curMax = 0;
        int furthest = 0;
        for (int i = 0; i < n-1; ++i) {
            curMax = max(curMax, i + nums[i]);
            if (i == furthest) {
                furthest = curMax;
                ++numJumps;
            }
        }
        return numJumps;
        
        // vector<bool> vis(n);
        // queue<pair<int, int>> q;
        // // number of steps, index
        // q.emplace(0, 0);
        // while (!empty(q)) {
        //     auto [steps, cur] = q.front(); q.pop();
        //     if (vis[cur])
        //         continue;
        //     vis[cur] = true;
        //     if (cur == n-1)
        //         return steps;
        //     for (int i = cur+1; i <= cur+nums[cur] && i < n; ++i)
        //         q.emplace(steps+1, i);
        // }
        // return -1; // impossible
        
        
    }
};