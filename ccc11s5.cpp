#include <bits/stdc++.h>
using namespace std;


int main() {
    int k;
    cin >> k;
    int n = 0;
    for (int w, i = 0; i < k; ++i) {
        cin >> w;
        n |= w * (1 << i);
    }

    auto turnOn = [k](int x, int j) {
        int numAdj = 0;
        for (int i = j+1; i < k; ++i) {
            if ((x & (1 << i)) == 0) break;
            ++numAdj;
        }
        int r = j-1;
        for (int i = j-1; i >= 0; --i) {
            if ((x & (1 << i)) == 0) break;
            ++numAdj;
            r = i;
        }
        if (numAdj < 3)
            return x | (1 << j);
        return x & ~(((1 << (numAdj+1))-1) << r);
    };

    int i = 0;
    unordered_set<int> s;
    queue<int> q, b;
    for (q.push(n); !q.empty(); ++i) {
        for (b.swap(q); !b.empty();) {
            int x = b.front(); b.pop();
            if (s.contains(x))
                continue;
            s.insert(x);
            if (x == 0) {
                cout << i << '\n';
                return 0;
            }
            for (int j = 0; j < k; ++j)
                if ((x & (1 << j)) == 0)
                    q.push(turnOn(x, j));
        }
    }
}
