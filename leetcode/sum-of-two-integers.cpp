class Solution {
    int fulladd(int a, int b) {
        int c = 0;
        int x = 0;
        for (int i = 0; i < 32; ++i) {
            int A = a & 1;
            int B = b & 1;
            int AB = A ^ B;
            int s = AB ^ c;
            x |= s << i;
            c = (A & B) | (AB & c);
            a >>= 1;
            b >>= 1;
        }
        return x;
    }
public:
    int getSum(int a, int b) {
        return fulladd(a, b);
    }
};