// https://leetcode.com/problems/find-the-town-judge

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trusts) {
        vector<int> trustsI(N + 1);
        vector<int> Itrusts(N + 1);
        for (vector<int> trust : trusts)
            ++Itrusts[trust[0]], ++trustsI[trust[1]];
        
        for (int i = 1; i <= N; i++)
            if (trustsI[i] == N - 1 && Itrusts[i] == 0)
                return i;
        return -1;
    }
};