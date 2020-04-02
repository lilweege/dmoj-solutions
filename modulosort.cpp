#include <bits/stdc++.h>
using namespace std;
#define pi pair<int, int>

int main () {
  int n, k;
  cin >> n >> k;
  pi m[n];
  for (int i = 0; i < n; i++) {
	cin >> m[i].second;
	m[i].first = m[i].second % k;
  }

  sort(m, m+n);
  for (pi x : m)
	cout << x.second << " ";

}
