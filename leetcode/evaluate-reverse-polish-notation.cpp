class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> s;
        for (const auto& tok : tokens) {
            // cout << tok << '\n';
            if (tok[0] == '+') {
                long x = s.top(); s.pop();
                long y = s.top(); s.pop();
                s.push(x + y);
            }
            else if (tok[0] == '-' && tok.size() == 1) {
                long x = s.top(); s.pop();
                long y = s.top(); s.pop();
                s.push(y - x);
            }
            else if (tok[0] == '*') {
                long x = s.top(); s.pop();
                long y = s.top(); s.pop();
                s.push(x * y);
            }
            else if (tok[0] == '/') {
                long x = s.top(); s.pop();
                long y = s.top(); s.pop();
                s.push(y / x);
            }
            else {
                s.push(stoi(tok));
            }
        }
        return s.top();
    }
};