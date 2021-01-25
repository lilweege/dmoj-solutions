#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
vector<bool> inf;

int cnt;
bool dfs(int u) {
	vis[u] = true;
	bool rec = false;
	for (int v : adj[u]) {
		if (!vis[v])
			rec |= dfs(v);
		if (inf[v])
			inf[u] = true;
	}
	if (!rec && !inf[u]) {
		inf[u] = true;
		++cnt;
	}
	return rec;
}
	
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	for (int t = 0; t < 2; ++t) {
		int n;
		cin >> n;
		
		adj.clear();
		vis.clear();
		inf.clear();
		adj.resize(n + 1);
		vis.resize(n + 1);
		inf.resize(n + 1);
		cnt = 0;
		
		// u -> v
		for (int v = 1; v <= n; ++v) {
			int u;
			cin >> u;
			adj[v].push_back(u);
		}
		for (int i = 1; i <= n; ++i)
			if (!vis[i])
				dfs(i);
		cout << cnt << " ";
	}
}