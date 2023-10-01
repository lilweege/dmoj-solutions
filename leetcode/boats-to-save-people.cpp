#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

static const auto fast = []() {
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0); return 0;
} ();

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        vector<int> freq(limit + 1); // 1 <= weight <= limit
        for (int w : people)
            ++freq[w];
        
        int ans = freq[limit];
        freq[limit] = 0;
        
        int l = 1,
            r = limit - 1;
        
        
        while (l < r)
        {
            while (freq[l] == 0 && l < r) ++l;
            while (freq[r] == 0 && l < r) --r;
            
            if (l == r)
                break;
            
            if (l + r <= limit)
            {
                // good pair
                while (freq[l] && freq[r])
                {
                    --freq[l];
                    --freq[r];
                    ++ans;
                }
                
                if (freq[l] == 0 && freq[r] == 0)
                {
                    ++l;
                    --r;
                }
                else if (freq[l] == 0) ++l;
                else if (freq[r] == 0) --r;
            }
            else
            {
                ans += freq[r];
                freq[r] = 0;
                --r;
            }
        }
        
        if (l + r <= limit)
            ans += ceil(freq[l] / 2.0);
        else
            ans += freq[l];
        freq[l] = 0;

        
        return ans;
    }
};