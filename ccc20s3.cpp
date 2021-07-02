#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
struct pll_hash {
	size_t operator() (const pair<ll, ll> &p) const {
		return hash<ll>()(p.first) ^ hash<ll>()(p.second);
	}
};


constexpr ll BASE1 = 101, MOD1 = 1e9+7;
constexpr ll BASE2 = 257, MOD2 = 1e9+9;
ll POW1, POW2;
int distinctPerms(const string& needle, const string& haystack) {
	int n = needle.size(),
		h = haystack.size();
	
	if (n > h)
		return 0;

	pll hash;
	auto rollHash = [&hash](char cNew, char cOld = 0) {
		static ll hash1 = 0;
		static ll hash2 = 0;

		hash1 = (hash1 * BASE1 + cNew) % MOD1;
		hash2 = (hash2 * BASE2 + cNew) % MOD2;

		if (cOld) {
			hash1 -= (POW1 * cOld) % MOD1;
			hash2 -= (POW2 * cOld) % MOD2;
			if (hash1 < 0) hash1 += MOD1;
			if (hash2 < 0) hash2 += MOD2;
		}

		hash = { hash1, hash2 };
	};
	
	vector<int> freq(26), window(26);
	POW1 = 1LL, POW2 = 1LL;
	for (int i = 0; i < n; ++i) {
		char cN = needle[i] - 'a';
		char cH = haystack[i] - 'a';
		
		++freq[cN];
		++window[cH];
		
		POW1 = (POW1 * BASE1) % MOD1;
		POW2 = (POW2 * BASE2) % MOD2;
		rollHash(cH);
	}
	
	unordered_set<pll, pll_hash> seen;
	if (freq == window)
		seen.insert(hash);
	
	for (int i = n; i < h; ++i) {
		char cOld = haystack[i-n] - 'a';
		char cNew = haystack[i  ] - 'a';

		--window[cOld];
		++window[cNew];
		rollHash(cNew, cOld);
		if (freq == window)
			seen.insert(hash);
	}

	return seen.size();
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string needle, haystack;
	cin >> needle >> haystack;

	cout << distinctPerms(needle, haystack) << "\n";
}