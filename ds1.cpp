#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct bit {
	int n;
	vector<ll> t;
	// everything one indexed

	bit(int _n) : n(_n) {
		t.resize(n+1);
	}

	ll sum(int i) const {
		ll ans = 0;
		for (; i > 0; i -= i & -i)
			ans += t[i];
		return ans;
	}

	ll sum(int l, int r) const {
		return sum(r) - sum(l-1);
	}

	void add(int i, int x) {
		for (; i <= n; i += i & -i)
			t[i] += x;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	bit ft(n), cnt(500000);
	vector<int> a(n+1);
	for (int x = 1; x <= n; ++x) {
		int v;
		cin >> v;
		cnt.add(v, 1);
		ft.add(x, v);
		a[x] = v;
	}

	while (m--) {
		char c;
		cin >> c;
		switch (c) {
			case 'C': {
				int x, v;
				cin >> x >> v;
				cnt.add(a[x], -1);
				cnt.add(v, 1);
				ft.add(x, v-a[x]);
				a[x] = v;
			} break;
			case 'S': {
				int l, r;
				cin >> l >> r;
				cout << ft.sum(l, r) << "\n";
			} break;
			case 'Q': {
				int v;
				cin >> v;
				cout << cnt.sum(v) << "\n";
			} break;
			default: break;
		}
	}
}