class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; ++i) {
            vector<bool> hasNum(n, false); // row
            for (int j = 0; j < n; ++j) {
                int x = matrix[i][j] - 1;
                hasNum[x] = true;
            }
            for (bool b : hasNum) {
                if (!b) {
                    return false;
                }
            }
            
        }
        
        for (int j = 0; j < n; ++j) {
            vector<bool> hasNum(n, false);
            for (int i = 0; i < n; ++i) {
                int x = matrix[i][j] - 1;
                hasNum[x] = true;
            }
            for (bool b : hasNum) {
                if (!b) {
                    return false;
                }
            }
            
        }
        
        return true;
    }
};