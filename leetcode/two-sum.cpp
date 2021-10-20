// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            int comp = target - nums[i];
            if (m.find(comp) != m.end()) {
                return { m.at(comp), i };
            }
            m.insert( { nums[i], i } );
        }
        return { };
    }
};