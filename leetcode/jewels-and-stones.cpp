class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int ans = 0;
        unordered_set<char> jewels;
        for (char& c : J)
            jewels.insert(c);
        for (char& c : S)
            ans += jewels.count(c);
        return ans;
    }
};