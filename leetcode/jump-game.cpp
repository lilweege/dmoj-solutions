class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = size(nums);
        
        // vector<bool> vis(n);
        // queue<int> q;
        // q.push(0);
        // while (!q.empty()) {
        //     int cur = q.front(); q.pop();
        //     if (vis[cur])
        //         continue;
        //     vis[cur] = true;
        //     if (cur == n-1)
        //         return true;
        //     // this will TLE
        //     for (int i = cur+1; i <= cur+nums[cur] && i < n; ++i)
        //         q.push(i);
        // }
        // return false;
        
        int cur = n-1;
        for (int i = n-1; i >= 0; --i) {
            int maxJump = i + nums[i];
            if (maxJump >= cur)
                cur = i;
        }
        return cur == 0;
    }
};