#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<pair<int, int>>> adj(n + 1);
	vector<array<int, 2>> L(n + 1, {INF, INF});
	int s = 1, t = n;
	
	for (int a, b, w, i = 0; i < m; ++i) {
		cin >> a >> b >> w;
		adj[a].emplace_back(w, b);
		adj[b].emplace_back(w, a);
	}
	
	L[s][0] = 0;
	priority_queue<pair<int, int>> pq;
	pq.emplace(0, s);
	
	while (pq.size()) {
		auto [d, a] = pq.top(); pq.pop();
		// cout << a << " " << d << "\n";
		for (auto [w, b] : adj[a]) {
			int d1 = L[a][0] + w,
				d2 = L[a][1] + w;
			// cout << b << ": " << d1 << " " << d2 << "\n";
			
			/*         b
			0: . . . . || . . .
			1: . . . . \/ . . .
			*/

			if (d1 < L[b][0]) {
				L[b][1] = L[b][0];
				L[b][0] = d1;
				pq.emplace(L[b][0], b);
			}
			else if (L[b][0] < d1 && d1 < L[b][1]) {
				L[b][1] = d1;
				pq.emplace(L[b][1], b);
			}
			else if (L[b][0] < d2 && d2 < L[b][1]) {
				L[b][1] = d2;
				pq.emplace(L[b][1], b);
			}
			// for (int i = 1; i <= n; ++i)
				// cout << L[i][0] << " ";
			// cout << "\n";
			// for (int i = 1; i <= n; ++i)
				// cout << L[i][1] << " ";
			// cout << "\n\n";
		}
		// cout << "\n";
	}
	
	cout << (L[t][1] == INF ? -1 : L[t][1]) << "\n";
}