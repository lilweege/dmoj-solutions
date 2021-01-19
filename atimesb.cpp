#include <bits/stdc++.h>
using namespace std;

void FFT(vector<complex<double>>& P, int n) {
	n /= 2;
	if (n == 0)
		return;

	// even, odd
	vector<complex<double>> Pe(n), Po(n);
	for (int i = 0; i < n; ++i)
		Pe[i] = P[i * 2    ],
		Po[i] = P[i * 2 + 1];
	
	FFT(Pe, n);
	FFT(Po, n);

	// w = e ^ (2 * pi * i / n)
	// w = cos(a) + i * sin(a)
	// => a = 2 * pi / n, (n is halved)
	double a = M_PI / n;
	complex<double> w(cos(a), sin(a));
	complex<double> wi(1);
	for (int i = 0; i < n; ++i, wi *= w)
		P[i    ] = Pe[i] + wi * Po[i],
		P[i + n] = Pe[i] - wi * Po[i];
}

void IFFT(vector<complex<double>>& P, int n) {
	n /= 2;
	if (n == 0)
		return;

	vector<complex<double>> Pe(n), Po(n);
	for (int i = 0; i < n; ++i)
		Pe[i] = P[i * 2    ],
		Po[i] = P[i * 2 + 1];
	
	IFFT(Pe, n);
	IFFT(Po, n);

	double a = -M_PI / n;
	complex<double> w(cos(a), sin(a));
	complex<double> wi(1);
	for (int i = 0; i < n; ++i, wi *= w)
		P[i    ] = (Pe[i] + wi * Po[i]),
		P[i + n] = (Pe[i] - wi * Po[i]);
}

void FFT(vector<complex<double>>& P) {
	FFT(P, P.size());
}
void IFFT(vector<complex<double>>& P) {
	int n = P.size();
	IFFT(P, n);
	for (complex<double>& x : P)
		x /= n;
}

vector<int> F(const vector<int>& Xr, const vector<int>& Yr) {
	int n = exp2(ceil(log2(Xr.size() + Yr.size())));
	
	vector<complex<double>>
		Xc(Xr.begin(), Xr.end()),
		Yc(Yr.begin(), Yr.end());
	Xc.resize(n);
	Yc.resize(n);
	
	FFT(Xc);
	FFT(Yc);
	for (int i = 0; i < n; ++i)
		Xc[i] *= Yc[i];
	IFFT(Xc);
	
	vector<int> Zr(n);
	for (int i = 0, c = 0; i < n; ++i) {
		Zr[i] = round(Xc[i].real()) + c;
		c = Zr[i] / 10;
		Zr[i] %= 10;
	}
	return Zr;
}

vector<int> read() {
	string s;
	cin >> s;
	
	int sz = s.size();
	vector<int> v(sz);
	for (int i = 0; i < sz; ++i)
		v[sz - i - 1] = s[i] - '0';
	return v;
}


void print(const vector<int>& v) {
	int i = v.size() - 1;
	while (i >= 0 && v[i] == 0)
		--i;
	
	if (i == -1)
		cout << 0;
	else
		for (; i >= 0; --i)
			cout << v[i];
}


int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	print(F(read(), read()));
}