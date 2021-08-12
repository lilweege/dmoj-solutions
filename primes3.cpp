#include <bits/stdc++.h>
using namespace std;

using u64 = uint64_t;
using u128 = __uint128_t;

// thank you cp-algorithms
u64 binpower(u64 b, u64 e, u64 m) {
	u64 r = 1;
	b %= m;
	for (; e; e >>= 1) {
		if (e & 1)
			r = u128(r) * b % m;
		b = u128(b) * b % m;
	}
	return r;
}

bool composite(u64 n, u64 a, u64 d, int s) {
	u64 x = binpower(a, d, n);
	if (x == 1 || x == n - 1)
		return false;
	for (int r = 1; r < s; r++) {
		x = u128(x) * x % n;
		if (x == n - 1)
			return false;
	}
	return true;
}

// detirministic version
bool millerrabin(u64 x) {
	if (x < 4)
		return x == 2 || x == 3;

	int s = 0;
	u64 d = x-1;
	for (; (d & 1) == 0; d >>= 1, ++s);

	for (int a : { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 }) {
		if (x == u64(a))
			return true;
		if (composite(x, a, d, s))
			return false;
	}
	return true;
}


int main() {
	int T;
	cin >> T;
	while (T--) {
		u64 x;
		cin >> x;
		cout << (millerrabin(x) ? "PRIME\n" : "NOT\n");
	}
}