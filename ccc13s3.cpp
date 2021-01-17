#include <bits/stdc++.h>
using namespace std;


// lol recursion who?
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

	vector<int> s(4, 0);
	vector<pair<int, int>> r = {
		{ 1, 2 },
		{ 1, 3 },
		{ 1, 4 },
		{ 2, 3 },
		{ 2, 4 },
		{ 3, 4 },
	};
	
	int t, g;
	cin >> t >> g;
	
	
	for (int i = 0; i < g; ++i) {
		int a, b, sa, sb;
		cin >> a >> b >> sa >> sb;
		
		for (int j = 0; j < r.size(); ++j)
			// 6 * 5 worst is fine
			if (r[j].first == a && r[j].second == b || 
				r[j].first == b && r[j].second == a) {
				r.erase(r.begin() + j);
				break;
			}
		// should break every time
		
		--a, --b;
		if (sa == sb)
			++s[a], ++s[b];
		else
			s[sa > sb ? a : b] += 3;
	}
	
	int sz = r.size();
	int n = pow(3, sz);
	int numWays = 0;
	// ith permutation
	for (int i = 0; i < n; ++i) {
		vector<int> v = s;
		
		// jth game outcome
		for (int j = 0; j < sz; ++j) {
			// base 3
			int out = i / int(pow(3, j)) % 3;
			// out (0, 1, 2) -> a win, b win, tie
			if (out == 0) {
				v[r[j].first - 1] += 1;
				v[r[j].second - 1] += 1;
			}
			else if (out == 1) {
				v[r[j].first - 1] += 3;
			}
			else if (out == 2) {
				v[r[j].second - 1] += 3;
			}
		}
		
		// is t-1 strictly largest
		bool f = true;
		for (int j = 0; j < v.size(); ++j)
			if (j != (t - 1) && v[j] >= v[t - 1]) {
				f = false;
				break;
			}
		
		if (f)
			++numWays;
	}
	
	cout << numWays;
}