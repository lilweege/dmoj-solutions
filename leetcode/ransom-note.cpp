// https://leetcode.com/problems/ransom-note

class Solution {
public:
    bool canConstruct(string r, string mag) {
        ios_base::sync_with_stdio(false);cin.tie(0),cout.tie(0);
        vector<int> vr(26,0),vm(26,0);
        for(char c:r) vr[c-'a']++;
        for(char c:mag) vm[c-'a']++;
        for(int i=0;i<26;i++) if(vm[i]<vr[i]) return false;
        return true;
    }
};