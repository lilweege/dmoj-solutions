// https://leetcode.com/problems/perform-string-shifts

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int n = s.length(), totalShift = 0;
        
        vector<char> sb;
        sb.reserve(n);
        for (char& c : s)
            sb.push_back(c);
        
        for (vector<int>& v : shift)
            totalShift += (v[0] ? v[1] : -v[1]);
        totalShift %= n;
        
        if (totalShift > 0) {
            while (totalShift--) {
                sb.insert(sb.begin(), sb.back());
                sb.pop_back();
            }
        }
        else {
            while (totalShift++) {
                sb.push_back(sb.front());
                sb.erase(sb.begin());
            }
        }
        return string(sb.begin(), sb.end());
    }
};