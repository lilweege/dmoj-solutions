#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	int m;
	cin >> s >> m;

	int n = s.size();
	int dp[n+1][n+1];
	for (int i = 0; i <= n; ++i) {
		dp[i][0] = 1;
		dp[0][i] = 1;
	}

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1];
			if (s[i] != s[j]) {
				dp[i+1][j+1] -= dp[i][j];
				if (dp[i+1][j+1] < 0)
					dp[i+1][j+1] += m;
			}
			
			dp[i+1][j+1] %= m;
		}

	cout << dp[n][n] << "\n";
}