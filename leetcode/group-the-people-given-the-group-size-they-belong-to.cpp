class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<int>> groups(n+1);
        vector<vector<int>> ans;

        for (int i = 0; i < n; ++i)
            groups[groupSizes[i]].push_back(i);
        
        // for (int i = 0; i <= n; ++i) {
        //     for (int j = 0; j < groups[i].size(); ++j)
        //         cout << groups[i][j] << ' ';
        //     cout << '\n';
        // }
        for (int i = 0; i <= n; ++i) {
            int sz = groups[i].size();
            if (sz == 0) continue;
            int x = groupSizes[groups[i][0]];
            if (sz == x) {
                ans.push_back(groups[i]);
            }
            else if (sz > x) {
                assert(sz % x == 0);
                for (int j = 0; j < sz; j += x) {
                    ans.emplace_back();
                    auto& v = ans.back();
                    for (int k = j; k < j+x; ++k)
                        v.push_back(groups[i][k]);
                }
            }
            else {
                assert(false);
            }
        }

        return ans;
    }
};