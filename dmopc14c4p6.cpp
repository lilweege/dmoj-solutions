#include <bits/stdc++.h>
using namespace std;

// similar to thicc17p6

int main() {
	int N;
	cin >> N;

	vector<vector<int>> adj(N+1);

	for (int i = 1; i < N; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	vector<bool> vis(N+1);
	auto clear = [&]() { fill(begin(vis), end(vis), false); };

	int md;
	function<void(int, int&, int)> dfs1 = [&]
	(int cur, int& idx, int d) {
		vis[cur] = true;
		if (md < d) {
			md = d;
			idx = cur;
		}
		for (int nxt : adj[cur])
			if (!vis[nxt])
				dfs1(nxt, idx, d+1);
	};

	int node1 = 0, node2 = 0;
	clear(); md = 0; dfs1(1, node1, 0);
	clear(); md = 0; dfs1(node1, node2, 0);
	
	
	function<void(int, vector<int>&)> dfs2 = [&]
	(int cur, vector<int>& dist) {
		vis[cur] = true;
		for (int nxt : adj[cur])
			if (!vis[nxt]) {
				dist[nxt] = dist[cur] + 1;
				dfs2(nxt, dist);
			}
	};

	vector<int> dist1(N+1);
	vector<int> dist2(N+1);
	clear(); dfs2(node1, dist1);
	clear(); dfs2(node2, dist2);
	
	for (int i = 1; i <= N; ++i)
		cout << max(dist1[i], dist2[i])+1 << "\n";
}