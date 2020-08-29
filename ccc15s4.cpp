#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

template <class T> constexpr T &lv(T &&v) { return v; }

int main() {
	const int mn = 200;

	int K, N, M;
	cin >> K >> N >> M;

	vector<unordered_map<int, vector<pair<int, int>>>> adj(N);
	vector<vector<bool>> vis(N, vector<bool>(mn, false));
	vector<vector<int>> tim(N, vector<int>(mn, 1e9));
	for (int a, b, t, h; M--;) {
		cin >> a >> b >> t >> h; a--; b--;
		adj[a][b].emplace_back(t, h);
		adj[b][a].emplace_back(t, h);
	}

	int A, B;
	cin >> A >> B; A--; B--;
	tim[A][K] = 0;

	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push( { 0, { A, K } } );

	int ans = -1;
	for (int t, a, h; !pq.empty(); pq.pop()) {
		tie(t, lv(tie(a, h))) = pq.top();
		if (a == B) {
			ans = t;
			break;
		}
		if (!vis[a][h]) {
			vis[a][h] = true;
			for (auto[b, v] : adj[a]) {
				for (auto[pt, ph] : v) {
					int nt = tim[a][h] + pt, nh = h - ph;
					if (nh > 0) {
						tim[b][nh] = min(tim[b][nh], nt);
						pq.push({ nt, { b, nh } });
					}
				}
			}
		}
	}
	cout << ans << endl;
}
