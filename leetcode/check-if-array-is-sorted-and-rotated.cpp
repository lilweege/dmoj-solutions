class Solution {
public:
    bool check(vector<int>& a) {
        int n = a.size();
        bool rot = false;
        for (int i = 0; i < n; ++i) {
            if (a[(i+1)%n] < a[i]) {
                if (rot)
                    return false;
                rot = true;
            }
        }
        return true;
    }
};