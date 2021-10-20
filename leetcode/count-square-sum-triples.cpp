// https://leetcode.com/problems/count-square-sum-triples

class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        for (int a = 1; a <= n; ++a)
            for (int b = 1; b <= n; ++b) {
                int x = a*a + b*b;
                int sq = sqrt(x);
                cnt += sq*sq == x && sq <= n;
            }
        return cnt;
    }
};