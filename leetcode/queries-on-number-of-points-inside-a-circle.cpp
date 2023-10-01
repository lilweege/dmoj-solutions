class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        // NM because why not
        vector<int> ans;
        for (const auto& query : queries) {
            int cx = query[0];
            int cy = query[1];
            int cr = query[2];
            int tot = 0;
            for (const auto& point : points) {
                int x = point[0];
                int y = point[1];
                if (sqrt((x-cx)*(x-cx) + (y-cy)*(y-cy)) <= cr)
                    ++tot;
            }
            ans.push_back(tot);
        }
        return ans;
    }
};