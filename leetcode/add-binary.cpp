class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size();
        int m = b.size();
        if (n < m) {
            a = string(m-n+1, '0') + a;
            b = "0" + b;
        }
        else if (n > m) {
            b = string(n-m+1, '0') + b;
            a = "0" + a;
        }
        else {
            a = "0" + a;
            b = "0" + b;
        }
        
        n = a.size();
        string ss(n, '0');
        int carry = 0;
        for (int i = n-1; i >= 0; --i) {
            int c = a[i] == '1';
            int d = b[i] == '1';
            int s = c + d + carry;
            carry = (s & 2) != 0;
            ss[i] += s & 1;
        }
        if (ss[0] == '0') ss = ss.substr(1);
        return ss;
    }
};