class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int s = size(matrix);
        int n = s-1;
        for (int i = 0; i < s/2+s%2; ++i)
            for (int j = 0; j < s/2; ++j) {
                int t = matrix[i][j];
                matrix[i][j] = matrix[n-j][i];
                matrix[n-j][i] = matrix[n-i][n-j];
                matrix[n-i][n-j] = matrix[j][n-i];
                matrix[j][n-i] = t;
            }
    }
};

// 1 2 3 4 5
// 2 3 4 5 6
// 3 4 5 6 7
// 4 5 6 7 8
// 5 6 7 8 9