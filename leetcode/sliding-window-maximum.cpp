class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /*
        int n = nums.size();
        multiset<int> ss;
        for (int i = 0; i < k; ++i)
            ss.insert(nums[i]);
        
        vector<int> ans;
        ans.reserve(n);
        for (int i = k; i < n; ++i) {
            ans.push_back(*max_element(begin(ss), end(ss)));
            ss.erase(ss.find(nums[i-k]));
            ss.insert(nums[i]);
        }
        ans.push_back(*max_element(begin(ss), end(ss)));

        return ans;
        */

        int n = nums.size();
        deque<int> q;
        vector<int> ans;
        ans.reserve(n);
        for (int i = 0; i < n; ++i) {
            if (!q.empty() && q.front() == i-k) q.pop_front();
            while (!q.empty() && nums[q.back()] < nums[i])
                q.pop_back();
            q.push_back(i);
            if (i >= k-1) ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};