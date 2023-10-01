struct Trie {

    Trie* child[26] = {};
    bool wordEnd = false;

    Trie() {}

    void insert(string_view word) {
        Trie* node = this;
        for (char c : word) {
            int i = c - 'a';
            if (node->child[i] == nullptr)
                node->child[i] = new Trie();
            node = node->child[i];
        }
        node->wordEnd = true;
    }
};

class Solution {
    Trie* t;
    int n, m;
    vector<vector<char>> board;
    unordered_set<string> ans;
    string s;

    void dfs(int i, int j, Trie* node) {
        if (!(0 <= i && i < n && 0 <= j && j < m))
            return;
        
        char ch = board[i][j];
        if (!ch) return;

        node = node->child[ch-'a'];
        if (node == nullptr)
            return;
        s.push_back(ch);
        if (node->wordEnd) {
            ans.insert(s);
        }

        board[i][j] = 0;
        dfs(i+1, j, node);
        dfs(i-1, j, node);
        dfs(i, j+1, node);
        dfs(i, j-1, node);
        board[i][j] = ch;

        s.pop_back();
    }

public:
    vector<string> findWords(vector<vector<char>>& _board, vector<string>& words) {
        ans.clear();

        board = _board;
        n = board.size();
        m = board[0].size();
        Trie _t;
        t = &_t;
        for (const auto& word : words)
            _t.insert(word);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                dfs(i, j, t);

        return vector<string>(ans.begin(), ans.end());
    }
};
