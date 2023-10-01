
class Solution {
    string s;
    int idx;
    long parseInt() {
        long x = 0;
        while (true) {
            char c = s[idx];
            if (!('0' <= c && c <= '9'))
                break;
            x = x * 10L + c - '0';
            if (++idx >= s.size())
                break;
        }
        return x;
    }
    
    #define END (-(1L<<32))
    #define PLUS (-((1L<<32)+1))
    #define MINUS (-((1L<<32)+2))
    #define LPAREN (-((1L<<32)+3))
    #define RPAREN (-((1L<<32)+4))

    long getToken() {
        while (idx < s.size() && s[idx] == ' ')
            ++idx;
        if (idx >= s.size()) return END;
        char c = s[idx++];
        if (c == '+') return PLUS;
        if (c == '-') return MINUS;
        if (c == '(') return LPAREN;
        if (c == ')') return RPAREN;
        --idx;
        return parseInt();
    }

    long parseFactor() {
        long tok = getToken();
        if (tok >= 0) return tok;
        if (tok == MINUS) return -parseFactor();
        if (tok == LPAREN) {
            long expr = parseTerm();
            assert(getToken() == RPAREN);
            return expr;
        }
        assert(false);
        return 0;
    }

    long parseTerm() {
        long lhs = parseFactor();
        while (true) {
            long delim = getToken();
            if (delim == RPAREN) {
                --idx;
                break;
            }
            if (delim == END) break;
            long rhs = parseFactor();
            if (delim == PLUS) lhs += rhs;
            if (delim == MINUS) lhs -= rhs;
        }
        return lhs;
    }

public:
    int calculate(string s_) {
        s = move(s_);
        return parseTerm();
    }
};