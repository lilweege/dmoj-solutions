class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int w = heights.size();
        
        vector<int> clean = heights;
        sort( clean.begin(), clean.end() );
        clean.erase( unique( clean.begin(), clean.end() ), clean.end() );
        int h = 0;
        for (const int n : clean)
            if (h < n)
                h = n;
        
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < w; ++i) {
            if (m.find(heights[i]) == m.end())
                m.emplace(heights[i], vector<int>());
            m[heights[i]].push_back(i);
        }
        
        
        int best = 0;
        for (const int j : clean) {
            
            // sol 1
            int area = 0;
            for (int i = 0; i < w; ++i) {
                if (j <= heights[i]) {
                    area += j;
                }
                else {
                    if (best < area)
                        best = area;
                    area = 0;
                }
            }
            if (best < area)
                best = area;
            
            // sol 2 (tle?)
            // unordered_set<int> checked;
            // for (const int i : m[j]) {
            //     int area = 0;
            //     for (int l = i - 1; l >= 0 && j <= heights[l]; --l) {
            //         if (checked.find(l) != checked.end())
            //             break;
            //         checked.insert(l);
            //         area += j;
            //     }
            //     for (int r = i; r < w && j <= heights[r]; ++r) {
            //         if (checked.find(r) != checked.end())
            //             break;
            //         checked.insert(r);
            //         area += j;
            //     }
            //     best = max(best, area);
            // }
            
        }
        
        return best;
    }
};