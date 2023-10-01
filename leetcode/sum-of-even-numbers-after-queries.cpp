class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        int m = nums.size();
        
        vector<int> answers(n);
        int tot = 0;
        for (int i = 0; i < m; ++i) {
            int x = nums[i];
            bool isEven = !(x & 1);
            tot += isEven * x;
        }
        
        for (int i = 0; i < n; ++i) {
            int val = queries[i][0];
            int index = queries[i][1];
            
            if (val & 1) {
                // add odd, change even
                if (!(nums[index] & 1)) {
                    tot -= nums[index];
                }
                else {
                    tot += nums[index] + val;
                }
            }
            else {
                if (!(nums[index] & 1)) {
                    tot += val;
                }
            }
            nums[index] += val;
            
            answers[i] = tot;
        }
        
        return answers;
    }
};