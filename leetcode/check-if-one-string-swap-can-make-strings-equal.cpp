class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.size();
        optional<pair<char, char>> firstPair = nullopt;
        bool hasSecondPair = false;

        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                if (!firstPair) {
                    firstPair = { s1[i], s2[i] };
                }
                else if (!hasSecondPair) {
                    if (!(firstPair->first == s2[i] && firstPair->second == s1[i]))
                        return false;
                    hasSecondPair = true;
                }
                else return false;
            }
        }
        return firstPair.has_value() == hasSecondPair;
    }
};