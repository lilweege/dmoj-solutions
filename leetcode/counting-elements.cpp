// https://leetcode.com/problems/counting-elements

class Solution {
public:
    int countElements(vector<int>& arr) {
        set<int> s;
        for (int x : arr)
            s.insert(x);
        
        int cnt = 0;
        for (int x : arr)
            cnt += (s.find(x + 1) != s.end());
        
        return cnt;
    }
};