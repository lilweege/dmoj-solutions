// naive
class MagicDictionary {
    vector<string> ss;
        
    static bool offByOne(string_view a, string_view b) {
        if (a.size() != b.size()) return false;
        int n = a.size();
        int d = 0;
        for (int i = 0; i < n; ++i)
            if ((d += (a[i] != b[i])) == 2)
                return false;
        return d == 1;
    }
    
public:
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        ss = move(dictionary);
    }
    
    bool search(const string& searchWord) {
        for (const auto& word : ss)
            if (offByOne(word, searchWord))
                return true;
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */