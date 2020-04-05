#include <bits/stdc++.h>
using namespace std;
#define MAXN 200001

int m, t[4 * MAXN], lazy[4 * MAXN];

void propagate(int i, int l, int r) {
	lazy[i] %= m;
	if (lazy[i]) {
		t[i] = (t[i] + (r - l + 1) * lazy[i]) % m;
		if (l != r) {
			lazy[i * 2] += lazy[i];
			lazy[i * 2 + 1] += lazy[i];
		}
		lazy[i] = 0;
	}
}

void build(int i, int l, int r, int* a) {
	if (l == r) {
		t[i] = a[l];
	}
	else {
		int mid = l + (r - l) / 2;
		build(i * 2, l, mid, a);
		build(i * 2 + 1, mid + 1, r, a);
		t[i] = (t[i * 2] + t[i * 2 + 1]) % m;
	}
}

int query(int i, int tl, int tr, int l, int r) {
	propagate(i, tl, tr);
	if (l > r) return 0;
	if (tl >= l && tr <= r) return t[i];
	int tm = tl + (tr - tl) / 2;
	return (query(i * 2, tl, tm, l, min(r, tm)) + query(i * 2 + 1, tm + 1, tr, max(l, tm + 1), r)) % m;
}

void update(int i, int tl, int tr, int l, int r, int v) {
	propagate(i, tl, tr);
	if (tl <= r && tr >= l) {
		if (tl >= l && tr <= r) {
			lazy[i] = v;
			propagate(i, tl, tr);
		}
		else {
			int mid = tl + (tr - tl) / 2;
			update(i * 2, tl, mid, l, r, v);
			update(i * 2 + 1, mid + 1, tr, l, r, v);
			t[i] = (t[i * 2] + t[i * 2 + 1]) % m;
		}
	}
}

int main() {
	int n, q;
	cin >> m >> n >> q;

	int a[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] %= m;
	}

	build(1, 1, n, a);

	for (int o, l, r, x; q; q--) {
		cin >> o;
		if (o == 1) {
			cin >> l >> r >> x;
			update(1, 1, n, l, r, x);
		}
		else {
			cin >> l >> r;
			cout << query(1, 1, n, l, r) << endl;
		}
	}
}
