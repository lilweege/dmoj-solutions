class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        vector<int> diff(1001);
        int n = size(target);
        for (int i = 0; i < n; ++i) {
            ++diff[target[i]];
            --diff[arr[i]];
        }
        
        return all_of(begin(diff), end(diff), [](int x){return x == 0;});
    }
};