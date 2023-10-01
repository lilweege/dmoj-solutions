class Solution {
public:
    string removeKdigits(string num, int k) {
        /*
       string ans = "";
       for (const char& c : num) {
           while (!ans.empty() && ans.back() > c && k)
               ans.pop_back(), --k;
           if (!ans.empty() || c != '0')
               ans.push_back(c);
       }
       
       while (!ans.empty() && k--)
           ans.pop_back();
       
       return ans.empty() ? "0" : ans;
       */
        
        if (k >= num.size())
            return "0";
        while (k--) {
            for (auto it = num.begin() + 1; ; it++) {
                if (*it < *(it - 1) || it == num.end()) {
                    num.erase(it - 1);
                    break;
                }
            }
        }
        while (num.size() > 1 && num[0] == '0')
            num.erase(num.begin());
        return num;
    }
};