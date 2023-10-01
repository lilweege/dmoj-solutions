class Solution {
    size_t m, n;
    bool dfs(vector<vector<char>>& board, const string& word, size_t i, size_t j, size_t x) {
        if (x == word.size())
            return true;
        if (i >= m || j >= n)
            return false;
        if (board[i][j] != word[x])
            return false;
        
        board[i][j] = 0;
        bool yes = dfs(board, word, i+1, j, x+1) ||
                   dfs(board, word, i-1, j, x+1) ||
                   dfs(board, word, i, j+1, x+1) ||
                   dfs(board, word, i, j-1, x+1);
        board[i][j] = word[x];
        return yes;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for (size_t i = 0; i < m; ++i)
            for (size_t j = 0; j < n; ++j)
                if (dfs(board, word, i, j, 0))
                    return true;
        return false;
    }
};