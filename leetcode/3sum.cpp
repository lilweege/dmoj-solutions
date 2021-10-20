// https://leetcode.com/problems/3sum

class Solution {
//     typedef tuple<int, int, int> tiii;

//     // define a hash function for this tuple
//     struct KeyHash : public std::unary_function<tiii, size_t> {
//         size_t operator()(const tiii& k) const {
//             // the magic operation below makes collisions less likely than just the standard XOR
//             size_t seed = hash<int>()(get<0>(k));
//             seed ^= hash<int>()(get<1>(k)) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
//             return seed ^ (hash<int>()(get<2>(k)) + 0x9e3779b9 + (seed << 6) + (seed >> 2));
//         }
//     };

//     // define the comparison operator for this tuple
//     struct KeyEqual : public std::binary_function<tiii, tiii, bool> {
//         bool operator()(const tiii& v0, const tiii& v1) const {
//             return get<0>(v0) == get<0>(v1) && get<1>(v0) == get<1>(v1) && get<2>(v0) == get<2>(v1);
//         }
//     };

//     typedef unordered_set<tiii, KeyHash, KeyEqual> MySet;
    
//     tiii sort_tup(int x, int y, int z) {
//         int f = min(min(x, y), z);
//         if (f == x) {
//             if (y > z)
//                 return make_tuple(x, z, y);
//             else
//                 return make_tuple(x, y, z);
//         }
//         else if (f == y) {
//             if (x > z)
//                 return make_tuple(y, z, x);
//             else
//                 return make_tuple(y, x, z);
//         }
//         else {
//             if (x > y)
//                 return make_tuple(z, y, x);
//             else
//                 return make_tuple(z, x, y);
//         }
//     }
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         // naive
//         MySet s(1000000);
//         int n = size(nums);
//         for (int i = 0; i < n; ++i)
//             for (int j = i+1; j < n; ++j)
//                 for (int k = j+1; k < n; ++k)
//                     if (i != j && i != k && j != k && nums[i] + nums[j] + nums[k] == 0)
//                         s.insert(sort_tup(nums[i], nums[j], nums[k]));
        
//         vector<vector<int>> ans(size(s), vector<int>(3));
//         int i = 0;
//         for (const auto& [a, b, c] : s) {
//             ans[i][0] = a;
//             ans[i][1] = b;
//             ans[i++][2] = c;
//         }
//         return ans;
        
//     }
    
    
    
    
public:
    /*
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
    */
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(begin(nums), end(nums));
        int n = size(nums);
        for (int i = 0; i < n; i++) {
            int target = -nums[i];
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum == target) {
                    vector<int> t = {nums[i], nums[l], nums[r]};
                    ans.push_back(t);
                    while (l < r && nums[l] == t[1]) ++l;
                    while (l < r && nums[r] == t[2]) --r;
                }
                else if (sum < target)
                    ++l;
                else
                    --r;
            }
            while (i + 1 < n && nums[i + 1] == nums[i]) ++i;
        }
        return ans;
    }
};