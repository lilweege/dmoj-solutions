#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001

int rnk[MAXN], par[MAXN];
vector<int> mst;

int find(int n) {
	if (par[n] != n)
	par[n] = find(par[n]);
	return par[n];
}

void merge(int x, int y) {
  if (rnk[x] == rnk[y]) {
	par[x] = y;
	rnk[x]++;
  }
	else if (rnk[x] > rnk[y]) {
		par[y] = x;
	}
	else if (rnk[y] > rnk[x]) {
		par[x] = y;
	}
}

int main() {
  int n, m;
  cin >> n >> m;

	for (int i = 1; i <= n; i++) par[i] = i;

	for (int i = 1, u, v; i <= m; i++) {
	cin >> u >> v;
		u = find(u); v = find(v);
		if (u != v) {
			merge(u, v);
	  mst.push_back(i);
		}
	}

	if (mst.size() + 1 != n) {
		cout << "Disconnected Graph" << endl;
	}
  else {
	for (auto e : mst)
	  cout << e << endl;
  }
}
