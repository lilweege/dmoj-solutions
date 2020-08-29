#include <bits/stdc++.h>
using namespace std;

long long length = 0, numWays = 0;

vector<vector<int>> adj;
vector<int> dst;
vector<long long> pos;

int dfs(int u, int v) {
	if (adj[u].empty() && u != v)
		return 0;
	
	for (int n : adj[u]) {
		if (n == v)
			continue;
		int d = dfs(n, u) + 1;
		if (length < d + dst[u]) {
			length = d + dst[u];
			numWays = pos[u] * pos[n];
		}
		else if (length == d + dst[u]) {
			numWays += pos[u] * pos[n];
		}
		
		if (dst[u] < d) {
			dst[u] = d;
			pos[u] = pos[n];
		}
		else if (dst[u] == d) {
			pos[u] += pos[n];
		}
	}
	return dst[u];
}

int main() {
	int n;
	cin >> n;
	
	adj.resize(n);
	dst.resize(n);
	pos.resize(n, 1);
	
	for (int u, v; --n;) {
		cin >> u >> v; u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(0, 0);
	cout << length + 1 << " " << numWays << endl;
}