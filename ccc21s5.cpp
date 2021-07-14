#include <bits/stdc++.h>
using namespace std;


// template <typename T>
// void pv(const vector<T>& v) {
// 	for (const T& x : v)
// 		cout << x << " ";
// 	cout << "\n";
// }

// gcds
namespace st1 {
	int n;
	vector<int> t;

	void init(int sz) {
		n = sz;
		t.resize(n*4+1, 1);
	}

	void update(int x, int y, int z, int l, int r, int i) {
		if (l >= x && r <= y) {
			t[i] = lcm(t[i], z);
		}
		else if (x <= r && y >= l) {
			int m = (l + r) / 2;
			update(x, y, z, l  , m, i*2  );
			update(x, y, z, m+1, r, i*2+1);
		}
	}
	void update(int x, int y, int z) {
		update(x-1, y-1, z, 0, n-1, 1);
	}
}

// seq
namespace st2 {
	int n;
	vector<int> t;
	vector<bool> s;

	void init(int sz) {
		n = sz;
		t.resize(n*4+1);
		s.resize(n*4+1);
	}

	void build(int l, int r, int i, int v = 1) {
		v = lcm(v, st1::t[i]);
		if (l == r) {
			t[i] = v;
			s[i] = true;
		}
		else {
			int m = (l + r) / 2;
			build(l  , m, i*2  , v);
			build(m+1, r, i*2+1, v);
			t[i] = gcd(t[i*2], t[i*2+1]);
		}
	}
	void build() {
		build(0, n-1, 1);
	}

	int query(int x, int y, int l, int r, int i) {
		if (l >= x && r <= y) {
			return t[i];
		}
		else if (x <= r && y >= l) {
			int m = (l + r) / 2;
			return gcd(
				query(x, y, l  , m, i*2  ),
				query(x, y, m+1, r, i*2+1));
		}
		return 0;
	}
	int query(int x, int y) {
		return query(x-1, y-1, 0, n-1, 1);
	}

	void print(int i) {
		if (i > n * 4)
			return;
		print(i * 2);
		if (s[i])
			cout << t[i] << " ";
		print(i * 2 + 1);
	}
	void print() {
		print(1);
		cout << "\n";
	}
}


const int maxA = 1e9;

struct rule {
	int x, y, z;
	// gcd(A[x:y]) == z
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	st1::init(n);
	st2::init(n);

	vector<rule> rules(m);
	for (auto& [x, y, z] : rules) {
		cin >> x >> y >> z;
		st1::update(x, y, z);
	}

	st2::build();

	for (auto [x, y, z] : rules) {
		int g = st2::query(x, y);
		if (g != z || g > maxA) {
			cout << "Impossible\n";
			return 0;
		}
	}
	
	st2::print();
}