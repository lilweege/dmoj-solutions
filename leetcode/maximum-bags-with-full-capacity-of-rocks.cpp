class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
//         int n = rocks.size();
//         map<int, int> m;
//         for (int i = 0; i < n; ++i)
//             ++m[capacity[i] -= rocks[i]];
//         int full = 0;
//         for (auto [diff, cnt] : m) {
//             if (additionalRocks > diff*cnt) {
//                 additionalRocks -= diff*cnt;
//                 full += cnt;
//             }
//             else {
//                 full += additionalRocks / diff;
//                 break;
//             }
//         }
//         return full;
        
        int n = rocks.size();
        for (int i = 0; i < n; ++i)
            capacity[i] -= rocks[i];
        sort(capacity.begin(), capacity.end());
        int i = 0;
        while (i < n && additionalRocks >= capacity[i]) {
            additionalRocks -= capacity[i];
            ++i;
        }
        return i;
    }
};