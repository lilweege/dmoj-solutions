#include <bits/stdc++.h>
using namespace std;

auto kmp(string_view s, string_view t) -> int {
	size_t n = size(t),
		m = size(s);

	vector<int> lps(n);
	for (size_t i = 1; i < n; ++i) {
		size_t j = lps[i-1];
		while (j > 0 && t[i] != t[j])
			j = lps[j-1];
		if (t[i] == t[j]) ++j;
		lps[i] = j;
	}

	for (size_t i = 0, j = 0; i < m;) {
		if (t[j] == s[i])
			++i, ++j;
		if (j == n) {
			return i-j; // first
			j = lps[j-1];
		}
		else if (i < m && t[j] != s[i]) {
			if (j)
				j = lps[j-1];
			else
				++i;
		}
	}
	return -1;
};

auto main() -> int {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s, t;
	cin >> s >> t;
	cout << kmp(s, t) << "\n";
}