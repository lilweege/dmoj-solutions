#include <bits/stdc++.h>
using namespace std;

const int MM = 5e5+1;
const int MN = 1e6+1;
int last[MM], b[MN];
double dp[MM];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		last[b[i]] = i;
		// back-most person to want bi
	}
	int coach = b[0], josh = b[n-1];
	double yoink = 1.0 / n; // coach took random
	for (int i = 1; i < n; ++i) {
		int want = b[i]; // ith teammate ordered this
		if (want != coach) // coach took his
			dp[want] += yoink;
		if (last[want] == i) // cur guy is backmost
			yoink += dp[want] / (n-i);
	}
	cout << (1 - dp[josh]);
}