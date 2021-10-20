// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        
        stack<char> stack;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            }
            else {
                if (stack.empty())
                    return false;
                char open = stack.top();
                stack.pop();
                if (c == '}' && open != '{' ||
                   c == ')' && open != '(' ||
                   c == ']' && open != '[')
                    return false;
            }
        }
        return stack.empty();
    }
};