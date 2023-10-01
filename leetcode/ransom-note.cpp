class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt1[127]{};
        int cnt2[127]{};
        for (char c : magazine) ++cnt1[c];
        for (char c : ransomNote) ++cnt2[c];
        for (int i = 0; i < 127; ++i)
            if (cnt2[i] > cnt1[i]) return false;
        return true;
    }
};