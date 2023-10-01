class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        for (int row = 0, col = n - 1; row < m && col >= 0;  matrix[row][col] < target ? ++row : --col)
            if (matrix[row][col] == target)
                return true;
        
        return false;
    }
};