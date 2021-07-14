#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct fr {
	// position, walking rate (s/m), hearing distance
	int p, w, d;
	bool operator < (const fr& rhs) const { return this->p < rhs.p; }
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int n;
	cin >> n;

	vector<fr> friends(n);
	int maxP = 0;
	for (auto& [p, w, d] : friends) {
		cin >> p >> w >> d;
		maxP = max(maxP, p);
	}

	if (n == 1) {
		cout << "0\n";
		return 0;
	}

	sort(friends.begin(), friends.end());

	auto cost = [](fr f, int c) {
		ull dst = abs(f.p - c);
		if (dst > f.d)
			return (dst - f.d) * f.w;
		return 0ULL;
	};

	auto sum = [cost, &friends](int c) {
		ull sum = 0;
		for (const fr& f : friends)
			sum += cost(f, c);
		return sum;
	};

	int l = 0, h = maxP;
	while (l + 1 < h) {
		int m = (l + h) / 2;
		ll x = sum(m-1) - sum(m);
		(x > 0 ? l : h) = m;
	}
	
	cout << sum(l) << "\n";
}