#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class st {
	// other structures may be slightly more suitable for static rmq
	// st is fast enough tho

	int n;
	vector<int> t;

	int add(int a, int b) const {
		return max(a, b);
	}

	int build(int tl, int tr, int i, const vector<int>& a) {
		if (tl == tr)
			return t[i] = a[tl];
		int tm = tl + (tr - tl) / 2;
		return t[i] = add(
			build(tl  , tm, i*2  , a),
			build(tm+1, tr, i*2+1, a));
	}

	int query(int tl, int tr, int i, int l, int r) const {
		if (tl >= l && tr <= r)
			return t[i];
		if (l > tr || r < tl)
			return 0;
		int tm = tl + (tr - tl) / 2;
		return add(
			query(tl  , tm, i*2  , l, r),
			query(tm+1, tr, i*2+1, l, r));
	}

public:
	st(const vector<int>& a) : n(a.size()) {
		t.resize(4*n);
		build(0, n-1, 1, a);
	}
	
	int query(int l, int r) const {
		assert(l <= r);
		return query(0, n-1, 1, l, r);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> scores(n);
	for (int& a : scores)
		cin >> a;
	
	st rmq(scores);
	vector<ll> dp(n+1);

	int minDays = ceil(n / float(k));
	int diff = minDays * k - n;

	for (int day = 0; day < minDays; ++day) {
		int rmin = n - k * day;
		int lmin = n - k * (day+1);
		
		for (int l = lmin + diff, r = rmin + diff; l >= max(0, lmin); --l, ++r)
			for (r = min(n, min(r, l+k)); r >= rmin; --r) {
				ll res = dp[r] + rmq.query(l, r-1);
				if (dp[l] > res)
					break;
				dp[l] = res;
			}
	}

	cout << dp[0] << "\n";
}