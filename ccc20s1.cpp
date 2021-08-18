#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> p(n);
	for (auto& [t, x] : p)
		cin >> t >> x;
	sort(begin(p), end(p));
	double best = 0;
	for (int i = 0; i < n-1; ++i) {
		auto [ct, cx] = p[i];
		auto [nt, nx] = p[i+1];
		double dt = nt - ct, dx = nx - cx;
		best = max(best, abs(dx / dt));
	}
	cout << best;
}