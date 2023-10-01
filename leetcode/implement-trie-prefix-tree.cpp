class Trie {
    Trie* child[26];
    bool isTerminal;
public:
    Trie() {
        for (int i = 0; i < 26; ++i)
            child[i] = nullptr;
        isTerminal = false;
    }
    
    void insert(string word, int idx = 0) {
        if (idx >= word.size()) return;
        char c = word[idx];
        if (!child[c-'a']) child[c-'a'] = new Trie();
        Trie* node = child[c-'a'];
        node->isTerminal |= idx == word.size()-1;
        node->insert(word, idx+1);
    }
    
    bool search(string word) {
        Trie* node = child[word[0]-'a'];
        for (int i = 1; i < word.size(); ++i) {
            if (!node) return false;
            node = node->child[word[i]-'a'];
        }
        if (!node) return false;
        return node->isTerminal;
    }
    
    bool startsWith(string word) {
        Trie* node = child[word[0]-'a'];
        for (int i = 1; i < word.size(); ++i) {
            if (!node) return false;
            node = node->child[word[i]-'a'];
        }
        if (!node) return false;
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */