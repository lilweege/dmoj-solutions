#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int BASE = 101, MOD = 1e9+7;

auto main() -> int {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	size_t k;
	cin >> s >> k;
	size_t n = size(s);
	
	vector<ll> HSH(n), POW(n);
	auto substr_hsh = [&HSH, &POW](size_t l, size_t r) -> ll {
		ll x = HSH[r] - HSH[l] * POW[r-l] % MOD;
		if (x < 0) x += MOD;
		return x;
	};
	
	POW[0] = 1LL;
	for (size_t i = 1; i < n; ++i) {
		HSH[i] = (HSH[i-1] * BASE + s[i]) % MOD;
		POW[i] = (POW[i-1] * BASE) % MOD;
	}
	
	size_t idx = 0;
	for (size_t i = 0; i < n-(k-1); ++i) {
		if (s[i] < s[idx]) {
			idx = i;
		}
		else if (s[i] == s[idx]) {
			size_t l = 0, r = k;
			while (l <= r) {
				size_t m = midpoint(l, r);
				if (substr_hsh(i, i+m) == substr_hsh(idx, idx+m))
					l = m+1;
				else
					r = m-1;
			}
			size_t x = r == k ? 0 : r+1;
			if (s[i+x] < s[idx+x])
				idx = i;
		}
	}
	cout << s.substr(idx, k) << "\n";
}