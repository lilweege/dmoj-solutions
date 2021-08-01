#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int _ = 0; _ < t; ++_) {
		int r1, r2, r3;
		cin >> r1 >> r2 >> r3;

		double p_total = 0;

		int valid_radius = r2 - r3;
		int inner_radius = r1 - r3;
		if (inner_radius > 0)
			p_total += pow(inner_radius, 2);
		else {
			double outmost_radius = min(valid_radius, -inner_radius);
			p_total += pow(outmost_radius, 2);
		}

		int outer_width = r2 - r1;
		if (2 * r3 < outer_width) {
			double strip_outer = r2 - r3;
			double strip_inner = r1 + r3;
			p_total += pow(strip_outer, 2) - pow(strip_inner, 2);
		}

		p_total /= pow(valid_radius, 2);
		cout << p_total << "\n";
	}
}
