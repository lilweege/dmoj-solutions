#include <bits/stdc++.h>
using namespace std;

#define MAXN 10002
bool b[MAXN][MAXN];

int main() {
	int n, m;
	cin >> n >> m;

	for (int x, y, w, h; m > 0; m--) {
		cin >> x >> y >> w >> h;
		x++; y++;

		b[x][y] ^= true;
		b[x + w][y] ^= true;
		b[x][y + h] ^= true;
		b[x + w][y + h] ^= true;
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		bool c = false;
		for (int j = 1; j <= n; j++) {
			c ^= b[i][j];
			cnt += c;
			b[i + 1][j] ^= b[i][j];
		}
	}
	cout << cnt;
}
