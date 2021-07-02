#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> h(n+2), dp(n+2, INT_MAX);
	for (int i = 0; i < n; ++i)
		cin >> h[i];
	
	dp[0] = 0;
	for (int i = 0; i < n; ++i) {
		dp[i+1] = min(dp[i+1], dp[i] + abs(h[i] - h[i+1]));
		dp[i+2] = min(dp[i+2], dp[i] + abs(h[i] - h[i+2]));
	}

	cout << dp[n-1] << "\n";
}