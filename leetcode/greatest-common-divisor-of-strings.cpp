class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        size_t n = str1.size();
        size_t m = str2.size();
        if (str1+str2 == str2+str1)
            return str1.substr(0, gcd(n, m));
        return "";
    }
};