class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int lo = 0, hi = letters.size()-1;
        char c = letters[0];
        while (lo <= hi) {
            int mi = (lo + hi) / 2;
            if (letters[mi] > target) {
                c = letters[mi];
                hi = mi - 1;
            }
            else {
                lo = mi + 1;
            }
        }
        return c;
    }
};