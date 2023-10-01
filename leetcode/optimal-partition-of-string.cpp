const static auto initialize = [] { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return nullptr; }();

class Solution {
public:
    int partitionString(string s) {
        int yes = 0;
        int x = 1;
        for (char c : s) {
            if (yes & (1 << (c-'a'))) {
                ++x;
                yes = 0;
            }
            yes |= 1 << (c-'a');
        }
        return x;
    }
};