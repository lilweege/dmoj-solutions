#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	vector<vector<int>> dp(n);
	dp[0].resize(1);
	cin >> dp[0][0];
	
	for (int i = 1; i < n; ++i) {
		dp[i].resize(i + 1);
		for (int j = 0; j <= i; ++j) {
			cin >> dp[i][j];
			if (j == 0)
				dp[i][j] += dp[i-1][j];
			else if (j == i)
				dp[i][j] += dp[i-1][j-1];
			else
				dp[i][j] += max(dp[i-1][j], dp[i-1][j-1]);
		}
	}
	
	// for (auto& v : dp) {
		// for (int x : v)
			// cout << x << " ";
		// cout << endl;
	// }
	cout << *max_element(dp.back().begin(), dp.back().end());
	
}