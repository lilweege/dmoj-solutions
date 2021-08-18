#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;
	int n = s.size();
	int na = 0, nb = 0, nc = 0;
	for (char c : s) switch (c) {
		case 'A': ++na; break;
		case 'B': ++nb; break;
		default: ++nc; break;
	}

	s += s; // circular be like
	array<vector<int>, 'C'+1> ps;
	for (int c = 'A'; c <= 'C'; ++c) {
		ps[c].resize(n*2);
		ps[c][0] = ps[c][0] == c;
	}
	for (int c = 'A'; c <= 'C'; ++c)
		for (int i = 0; i < n*2; ++i)
			ps[c][i] = ps[c][i-1] + (s[i] == c);

	int best = INT_MAX;
	auto cnt = [&ps](int c, int i, int x) {
		return ps[c][i+x] - ps[c][i];
	};
	for (int i = 0; i < n; ++i)
		best = min(best, na - cnt('A', i, na) + min(
			cnt('C', i+na, nb) + max(0, cnt('A', i+na, nb) - cnt('B', i, na)),
			cnt('B', i+na, nc) + max(0, cnt('A', i+na, nc) - cnt('C', i, na))
		));
	cout << best;
}