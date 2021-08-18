#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;
bool vis[MAX+1][MAX+1];
int grid[MAX+1][MAX+1];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int m, n;
	cin >> m >> n;
	for (int j = 1; j <= m; ++j)
		for (int i = 1; i <= n; ++i)
			cin >> grid[j][i];

	queue<pair<int, int>> q;
	q.emplace(1, 1);
	vis[1][1] = true;
	while (!q.empty()) {
		auto [r, c] = q.front(); q.pop();
		int v = grid[r][c];
		int i0 = max(v/1000, 1);
		for (int i = i0; i <= sqrt(v); ++i)
			if (v % i == 0) {
				int j = v / i;
				if ((j == m && i == n) ||
					(i == m && j == n)) {
					cout << "yes";
					return 0;
				}
				if (j <= m && i <= n && !vis[j][i]) {
					q.emplace(j, i);
					vis[j][i] = true;
				}
				if (i <= m && j <= n && !vis[i][j]) {
					q.emplace(i, j);
					vis[i][j] = true;
				}
			}
	}
	cout << "no";
}