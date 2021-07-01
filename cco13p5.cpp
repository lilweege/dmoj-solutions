#include <bits/stdc++.h>
using namespace std;


struct point {
	int x, y;
	point operator - (const point& rhs) const { return point{ x - rhs.x, y - rhs.y }; }
	double operator * (const point& rhs) const { return x * rhs.x + y * rhs.y; }
	double cross (const point& rhs) const { return x * rhs.y - y * rhs.x; }
	double mag() const { return sqrt(x * x + y * y); }
};

bool equal(double a, double b, double eps = 1e-5) {
	return abs(a - b) < eps;
}


void doit() {
	int n;
	cin >> n;

	vector<point> v1(n), v2(n);
	for (auto& [x, y] : v1)
		cin >> x >> y;
	for (auto& [x, y] : v2)
		cin >> x >> y;
	

	auto encode = [](point p1, point p2, point p3) -> double {
		point a = p1 - p2;
		point b = p3 - p2;

		double
			dot = a * b,
			cross = a.cross(b),
			magA = a.mag(),
			magB = b.mag();
		
		// double angle = acos(dot / (magA * magB));
		double angle = atan2(cross, dot);
		double ratio = magA / magB;

		return angle * ratio;
	};
	
	vector<double> s(n), t(2*n);
	for (int i = 0; i < n; ++i) {
		s[i]          = encode(v1[i], v1[(i+1)%n], v1[(i+2)%n]);
		t[i] = t[i+n] = encode(v2[i], v2[(i+1)%n], v2[(i+2)%n]); // mod
	}


	auto kmp = [](const vector<double>& s, const vector<double>& t) -> int {
		int n = s.size(),
			m = t.size();

		vector<int> lps(n);
		for (int i = 1; i < n; ++i) {
			int j = lps[i-1];
			while (j > 0 && !equal(s[i], s[j]))
				j = lps[j-1];
			if (equal(s[i], s[j]))
				++j;
			
			lps[i] = j;
		}

		for (int i = 0, j = 0; i < m; ) {
			if (equal(s[j], t[i]))
				++i, ++j;
			
			if (j == n) {
				return i - j; // one
				j = lps[j - 1];
			}
			else if (i < m && !equal(s[j], t[i])) {
				if (j) {
					j = lps[j-1];
				}
				else {
					++i;
				}
			}
		}
		return -1;
	};

	cout << (kmp(s, t) + 1) << "\n";
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
		doit();
}