class Solution {
    
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int m = students.size();    // num people
        int n = students[0].size(); // num responses
        
        vector<unsigned char> newStudents(m, 0);
        vector<unsigned char> newMentors(m, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (students[i][j])
                    newStudents[i] |= 1 << j;
                if (mentors[i][j])
                    newMentors[i] |= 1 << j;
            }
        }
        
        int best = 0;
        // int i = 0;
        vector<int> pairings(m);
        iota(pairings.begin(), pairings.end(), 0);
        do {
            best = max(best, [&]() {
                int x = 0;
                for (int i = 0; i < m; ++i)
                    x += __builtin_popcount(((1 << n) - 1) & ~(newStudents[pairings[i]] ^ newMentors[i]));
                return x;
            }());
        } while (next_permutation(pairings.begin(), pairings.end()));

        return best;
    }
};