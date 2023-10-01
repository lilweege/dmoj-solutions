class Solution {
public:
    bool isPerfectSquare(int num) {
        // if (num == 1)
        //     return true;
        // int l = 1, h = num / 2;
        // while (l <= h) {
        //     long long m = l + (h - l) / 2;
        //     if (m * m == num)
        //         return true;
        //     else if (m * m < num)
        //         l = m + 1;
        //     else
        //         h = m - 1;
        // }
        // return false;
        
        // long long r = num;
        // while (r * r > num)
        //     r = (r + num / r) / 2;
        // return num == r * r;
        
        // return sqrt(num) == (int)sqrt(num);
        
        return pow(num, 0.5) == (int)pow(num, 0.5);
    }
};