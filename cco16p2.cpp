#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define th 1e-9

bool closeEnough(ld a, ld b) {
	return abs(a - b) < th;
}

struct point {
	int x, y;
};

struct bunny : point {
	int w;
};

ld angle(point a, point b) {
	int dx = a.x - b.x;
	int dy = a.y - b.y;
	int g = abs(__gcd(dx, dy));
	return atan2(dy/g, dx/g);
}

int main() {
	int n;
	cin >> n;

	vector<bunny> bunnies(n);
	for (bunny &b : bunnies)
		cin >> b.x >> b.y >> b.w;


	int best = 0;
	for (int i = 0; i < n; i++) {
		map<ld, int> /*angle, goodness*/ m;
		int total = 0;
		for (int j = 0; j < n; j++) {
			if (i != j) {
				m[angle(bunnies[i], bunnies[j])] += bunnies[j].w;
				total += bunnies[j].w;
			}
		}

		int sz = m.size();

		vector<pair<ld, int>> cur(2 * sz);
		int c = 0;
		for (pair<ld, int> p : m) {
			cur[c++] = p;
		}
		for (pair<ld, int> p : m) {
			cur[c] = p;
			cur[c++].first += 2 * M_PI;
		}

		for (int x = 0, y = 0, w = 0; x < sz; x++) {
			ld a1 = cur[x].first + M_PI;

			for (; cur[y].first < a1 && y < 2 * sz; y++)
				w += cur[y].second;

			ld a2 = cur[y].first;

			best = max(best, bunnies[i].w + max(total - w, (cur[y].second + w) * closeEnough(a1, a2)));
			w -= cur[x].second;
		}
	}

	cout << best;
}
