class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (c == '(' || c == '{' || c == '[')
                st.push(c);
            else {
                if (st.empty()) return false;
                char d = st.top(); st.pop();
                if (!(d == '(' && c == ')' || d == '{' && c == '}' || d == '[' && c == ']'))
                    return false;
            }
        }
        return st.empty();
    }
};