class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        ans.reserve(size(arr1));
        // idx, cnt
        unordered_map<int, int> cnt;
        for (int x : arr1)
            ++cnt[x];
        for (int x : arr2) {
            ans.insert(end(ans), cnt[x], x);
            cnt[x] = -1;
        }
        int sz = size(ans);
        for (int x : arr1) {
            if (cnt[x] != -1)
                ans.push_back(x);
        }
        sort(begin(ans)+sz, end(ans));
        return ans;
    }
};