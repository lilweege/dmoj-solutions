#include <bits/stdc++.h>
using namespace std;

// https://sites.google.com/site/glennmurray/Home/rotation-matrices-and-formulas/rotation-about-an-arbitrary-axis-in-3-dimensions
void solve() {
	double x, y, z, u, v, w, a;
	cin >> x >> y >> z >> u >> v >> w >> a;

	double
		c = cos(a),
		s = sin(a),
		d = u*u + v*v + w*w,
		m = sqrt(d),
		t1 = (u*x + v*y + w*z) * (1-c);
	
	double
		xp = (u*t1 + d*x*c + m*(-w*y+v*z)*s) / d,
		yp = (v*t1 + d*y*c + m*( w*x-u*z)*s) / d,
		zp = (w*t1 + d*z*c + m*(-v*x+u*y)*s) / d;
	
	cout << fixed << setprecision(6) << xp << " " << yp << " " << zp << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	while (t--)
		solve();
}