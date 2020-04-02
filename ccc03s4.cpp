#include <bits/stdc++.h>
using namespace std;

int lcp(string a, string b) {
  int cnt = 0;
  for (; a[cnt] == b[cnt] && cnt < min(a.length(), b.length()); cnt++);
  return cnt;
}

int main() {
	int n;
	cin >> n;

	while (n--) {
		string s;
		cin >> s;
		vector<string> sa;

		for (int x = 0; x < s.length(); x++) {
			sa.push_back(s.substr(x, s.length() - x));
		}
		sort(sa.begin(), sa.end());

		int cnt = sa[0].length() + 1;
		for (int x = 1; x < s.length(); x++) {
			cnt += sa[x].length() - lcp(sa[x], sa[x-1]);
		}
		cout << cnt << endl;
	}
}
