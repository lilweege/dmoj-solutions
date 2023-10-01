class Solution {
public:
    bool asteroidsDestroyed(unsigned long long mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        for (int x : asteroids) {
            if (x > mass)
                return false;
            mass += x;
        }
        return true;
    }
};