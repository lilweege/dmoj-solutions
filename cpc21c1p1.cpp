#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int _ = 0; _ < t; ++_) {
		ull a, b;
		cin >> a >> b;

		// reduce
		ull g = gcd(a, b);
		if (g != 1) {
			a /= g;
			b /= g;
		}

		// p / (2^m * 5^n) is terminating
		// p ∈ Z
		// m, n ∈ W
		ull d = b;
		while (d % 2 == 0)
			d /= 2;
		if (d % 3 == 0) {
			cout << "-1\n";
			continue;
		}
		while (d % 5 == 0)
			d /= 5;
		if (d != 1) {
			cout << "-1\n";
			continue;
		}

		// long division
		int digs = 0;
		while (a != 0) {
			while (a < b) {
				a *= 10ULL;
				++digs;
			}
			a %= b;
		}
		cout << digs << "\n";
	}
}
