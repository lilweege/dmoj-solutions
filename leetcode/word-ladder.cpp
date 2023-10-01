class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        for (string& s : wordList) words.insert(s);
        if (words.find(endWord) == words.end()) return 0;
        int n = beginWord.size();

        int depth = 1;
        queue<string> q;
        unordered_set<string> vis;
        q.push(beginWord);
        while (!q.empty()) {
            queue<string> b;
            q.swap(b);
            while (!b.empty()) {
                string word = b.front(); b.pop();
                if (word == endWord) return depth;
                if (vis.find(word) != vis.end())
                    continue;
                vis.insert(word);
                
                for (int i = 0; i < n; ++i) {
                    char ch = word[i];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        word[i] = c;
                        auto it = words.find(word);
                        if (it != words.end()) {
                            words.erase(it);
                            q.push(word);
                        }
                    }
                    word[i] = ch;
                }
            }
            ++depth;
        }
        return 0;
    }
};