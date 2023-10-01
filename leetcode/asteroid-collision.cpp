class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        vector<int> ans;
        int n = size(asteroids);
        
        for (int cur : asteroids) {
            if (ans.empty()) {
                ans.push_back(cur);
            }
            else {
                int last = ans.back();
                bool curLeft = cur < 0;
                bool lastLeft = last < 0;
                bool curExplode = false;
                while (!lastLeft && curLeft) {
                    if (abs(cur) == abs(last)) {
                        // both explode
                        ans.pop_back();
                        curExplode = true;
                        break;
                    }
                    else if (abs(cur) > abs(last)) {
                        // last explode
                        ans.pop_back();
                        if (ans.empty())
                            break;
                        last = ans.back();
                        lastLeft = last < 0;
                    }
                    else {
                        // cur explode
                        curExplode = true;
                        break;
                    }
                }
                if (!curExplode)
                    ans.push_back(cur);
            }
        }
        
        return ans;
    }
};