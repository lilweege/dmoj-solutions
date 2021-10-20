// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        // naive
        int l1 = 0, l2 = 0;
        for (const string& s : word1)
            l1 += s.size();
        for (const string& s : word2)
            l2 += s.size();
        
        if (l1 != l2)
            return false;
        
        // check every char
        int i1 = 0, i2 = 0;
        int w1 = 0, w2 = 0;
        for (int x = 0; x < l1; ++x, ++i1, ++i2)
        {
            if (word1[w1].size() == i1)
                i1 = 0, ++w1;
            if (word2[w2].size() == i2)
                i2 = 0, ++w2;
            
            if (word1[w1][i1] != word2[w2][i2])
                return false;
        }
        
        return true;
    }
};