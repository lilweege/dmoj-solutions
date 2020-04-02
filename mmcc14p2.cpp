#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 2001
#define MAXM 5001
#define PSEED 101



struct Hash {
	ll* hashval = (ll*)malloc(MAXM * sizeof(ll));

	Hash() {}

	Hash(string s) {
		hashval[0] = 0;
		for (int i = 1, n = s.length(); i <= n; i++) {
			hashval[i] = hashval[i - 1] * PSEED + s[i - 1];
		}
	}

	ll hash(int i) {
		return hashval[i];
	}
};
Hash hashes[MAXN];



struct Node {
	int id = -1, val = 0;

	Node() {}

	Node(int i, int v) {
		id = i;
		val = v;
	}

	Node operator + (const Node o) const {
		if (id == -1) return o;
		if (o.id == -1) return *this;

		int l = 1, r = min(val, o.val) + 1;
		while (l < r) {
			int m = l + (r - l) / 2;
			if (hashes[id].hash(m) == hashes[o.id].hash(m)) {
				l = m + 1;
			}
			else {
				r = m;
			}
		}
		return Node(id, r - 1);
	}
};
Node ids[MAXN];



struct SegmentTree {
	Node* t = (Node*)malloc(4 * MAXN * sizeof(Node));
	int n = 0;

	SegmentTree() {}

	SegmentTree(int _n) {
		n = _n;
	}

	void build(int i, int l, int r, Node* a) {
		if (l == r) {
			t[i] = a[l];
		}
		else {
			int m = l + (r - l) / 2;
			build(i * 2, l, m, a);
			build(i * 2 + 1, m + 1, r, a);
			t[i] = t[i * 2] + t[i * 2 + 1];
		}
	}

	Node query(int i, int tl, int tr, int l, int r) {
		if (l > r) return Node();
		if (tl == l && tr == r) return t[i];
		int tm = tl + (tr - tl) / 2;
		return query(i * 2, tl, tm, l, min(r, tm)) + query(i * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
	}

	void update(int i, int l, int r, int p, Node v) {
		if (l == r) {
			t[i] = v;
		}
		else {
			int m = l + (r - l) / 2;
			if (p <= m) {
				update(i * 2, l, m, p, v);
			}
			else {
				update(i * 2 + 1, m + 1, r, p, v);
			}
			t[i] = t[i * 2] + t[i * 2 + 1];
		}
	}
};
SegmentTree seg;



int main() {
	int n, m;
	cin >> n >> m;

	string s;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		hashes[i] = Hash(s);
		ids[i] = Node(i, m);
	}

	seg = SegmentTree(n);
	seg.build(1, 1, n, ids);

	int q, i, j;
	cin >> q;
	while (q--) {
		cin >> i >> j;
		cout << (j - i + 1) * seg.query(1, 1, n, i, j).val << endl;

		swap(ids[i].id, ids[j].id);

		seg.update(1, 1, n, i, ids[i]);
		seg.update(1, 1, n, j, ids[j]);
	}
}
