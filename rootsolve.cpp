#include <bits/stdc++.h>
using namespace std;

#define pv(v) do { for (const auto& x : v) cerr << x << " "; cerr << "\n"; } while (0)

using ld = long double;
using cld = complex<ld>;
const cld UNSET = cld(0, LDBL_MAX);

// void pld(ld x) {
// 	static_assert(sizeof(x) == sizeof(__uint128_t));
// 	__uint128_t not_ub;
// 	memcpy(&not_ub, &x, sizeof(x));
// 	cerr << x << ": ";
// 	int top = 80; // x86 be like
// 	int sign = top-2, mant = LDBL_MANT_DIG-1;
// 	for (int i = top-1; i >= 0; --i) {
// 		if (i == sign || i == mant)
// 			cerr << " ";
// 		bool b = (not_ub >> i) & 1;
// 		cerr << b;
// 	}
// 	cerr << endl;
// }

bool eq(ld a, ld b, ld EPS = 1e-7) {
	return abs(a - b) < EPS;
}
pair<cld, cld> quadratic(ld a, ld b, ld c) {
	ld d = b*b - 4*a*c;
	cld r1 = UNSET, r2 = UNSET;
	if (eq(d, 0)) {
		r1 = -b / (2*a);
		r2 = UNSET;
	}
	else if (d > 0) {
		r1 = (-b + sqrt(d)) / (2*a);
		r2 = (-b - sqrt(d)) / (2*a);
	}
	else if (d < 0) {
		r1 = cld(-b, sqrt(-d)) / (2*a);
		r2 = conj(r1);
	}
	// d == nan
	return make_pair(r1, r2);
}


ld startpoint(const vector<ld>& a) {
	int n = a.size()-1;
	ld r = log(abs(a[n])), mi = INFINITY;
	for (int i = 0; i < n; ++i)
		if (a[i] != 0)
			// with Ofast exp(...) becomes nan
			mi = min(mi, exp((r - log(abs(a[i]))) / (n - i)));
	return mi * 0.5;
}

cld horner(const vector<ld>& a, cld z) {
	int n = a.size()-1;
	cld fz = 0;
	for (int i = 0; i <= n; ++i)
		fz = fz * z + a[i];
	return fz;
}

// Adam's stopping criteria
ld upperbound(const vector<ld>& a, cld z) {
	int n = a.size()-1;
	// complex point real coeff horner
	ld t, p = -2 * z.real(),
		q = norm(z),
		s = 0,
		r = a[0];
	ld u = abs(z);
	ld e = abs(r) * (3.5 / 4.5);
	for (int i = 1; i < n; ++i) {
		t = a[i] - p * r - q * s;
		s = r;
		r = t;
		e = u * e + abs(t);
	}
	t = a[n] + z.real() * r - q * s;
	e = u * e + abs(t);
	e = (9 * e - 7 * (abs(t) + abs(r) * u) +
		abs(z.real()) * abs(r) * 2) * pow(2, -LDBL_MANT_DIG+1);
	return e * e;
}

cld adjust(cld dz, ld m) {
	return cld(
		dz.real() * 0.6 - dz.imag() * 0.8,
		dz.real() * 0.8 + dz.imag() * 0.6) * m;
}


void forwarddeflation(vector<ld>& a, ld x) {
	int n = a.size()-1;
	ld r = 0;
	for (int i = 0; i < n; ++i) {
		r = r * x + a[i];
		a[i] = r;
	}
	a.pop_back();
}
void forwarddeflation(vector<ld>& a, cld z) {
	int n = a.size()-1;
	ld r = -2 * z.real(), u = norm(z);
	a[1] -= r * a[0];
	for (int i = 2; i < n-1; ++i) {
		a[i] = a[i] - r * a[i-1] - u * a[i-2];
	}
	a.pop_back();
	a.pop_back();
}


vector<cld> NewtonMadsen(vector<ld> a) {
	int n = a.size()-1;
	vector<cld> roots;
	roots.reserve(n);
	for (; n >= 0; --n)
		if (a[n] != 0) {
			if (n != int(a.size()-1)) {
				roots.resize(a.size()-1-n, 0);
				a.erase(a.begin()+n+1, a.end());
			}
			break;
		}

	while (n > 2) {
		// derivative
		vector<ld> a1(n);
		for (int i = 0; i < n; ++i)
			a1[i] = a[i] * (n - i);

		ld u = startpoint(a);
		cld z0 = 0,
			fz0 = a[n-1];
		ld ff = 2 * a[n] * a[n],
			f0 = ff;
		cld z = a[n-1] == 0 ? 1 : -a[n] / a[n-1];
		z = z.real() / abs(z.real()) * u;
		cld dz = z,
			fz = horner(a, z);
		ld f = abs(fz),
			r0 = 5 * u,
			r = abs(dz),
			eps = 4 * n * n * f0 * pow(2, -LDBL_MANT_DIG * 2);

		bool stage1 = true;
		// iteration until done
		while (z + dz != z && f > eps) {
			cld fz1 = horner(a1, z);
			ld f1 = norm(fz1);
			if (f1 == 0)
				// saddle
				dz = adjust(dz, 5);
			else {
				dz = fz / fz1;
				r = abs(dz);
				if (r > r0)
					dz = adjust(dz, r0 / r);
				r0 = r * 5;
				
				cld wz = (fz0 - fz1) / (z0 - z);
				ld wsq = abs(wz);
				stage1 = (wsq/f1 > f1/f/2) || (f != ff);
			}

			z0 = z;
			f0 = f;
			fz0 = fz;
			z = z0 - dz;
			fz = horner(a, z);
			f = norm(fz);
			ff = f;
			
			if (stage1) {
				cld wz = z;
				bool div2 = f > f0;
				for (int i = 1; i <= n; ++i) {
					if (div2) {
						dz *= 0.5;
						wz = z0 - dz;
					}
					else {
						wz -= dz;
					}
					cld fwz = horner(a, wz);
					ld fw = norm(fwz);
					if (fw >= f)
						// no improvement
						break;
					f = fw;
					fz = fwz;
					z = wz;
					if (div2 && i == 2) {
						dz = adjust(dz, 0.5);
						z = z0 - dz;
						fz = horner(a, z);
						f = norm(fz);
						break;
					}
				}
			}
			else {
				eps = upperbound(a, z);
			}
		}

		z0 = z.real();
		fz = horner(a, z0);
		if (norm(fz) <= f) {
			forwarddeflation(a, z.real());
			roots.push_back(z.real());
		}
		else {
			forwarddeflation(a, z);
			// these are removed anyways
			roots.push_back(z);
			roots.push_back(conj(z));
		}
		n = a.size()-1;
	}

	auto [r1, r2] = quadratic(a[2], a[1], a[0]);
	roots.push_back(r1);
	roots.push_back(r2);
	return roots;
}


#define MN 101
int main() {
	int T;
	cin >> T;
	vector<ld> coeffs(MN);
	while (T--) {
		ld coeff; int expo;
		cin >> coeff >> expo;
		coeffs[MN-1-expo] = coeff;
	}
	vector<cld> roots = NewtonMadsen(coeffs);
	auto bad = [](cld x) {
		return x.imag() != 0 ||
			x.real() != x.real() ||
			x.real() == INFINITY;
	};
	roots.erase(remove_if(roots.begin(), roots.end(), bad), roots.end());
	// pv(roots);
	if (roots.empty()) {
		cout << "NO REAL ROOTS\n";
	}
	else {
		sort(roots.begin(), roots.end(),
			[](cld a, cld b) { return a.real() < b.real(); });
		for (cld x : roots)
			cout << fixed << setprecision(5) << x.real() << "\n";
	}
}