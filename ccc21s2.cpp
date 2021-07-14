#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n, k;
	cin >> m >> n >> k;

	vector<bool> row(m);
	vector<bool> col(n);

	while (k--) {
		char c;
		int i;
		cin >> c >> i;

		(c == 'R' ? row : col)[i-1].flip();
	}


	int ans = 0;
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			ans += row[i] ^ col[j];

	cout << ans << "\n";
}