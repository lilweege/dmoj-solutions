#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n, a, b, c;
  cin >> n;
  cin >> a >> b >> c;
  vector<ll> dp(n+1);
  vector<ll> d(n+1, LONG_MIN); d[0] = 0;

  ll x, y;
  for (int i = 1, p = 0; i <= n; i++) {
	cin >> x;
	dp[i] += dp[i-1] + x;
	for (int j = p; j < i; j++) {
	  x = dp[i] - dp[j];
	  y = a * pow(x, 2) + b * x + c + d[j];
	  if (y > d[i]) {
		p = j;
		d[i] = y;
	  }
	}
  }
  cout << d[n];
}
