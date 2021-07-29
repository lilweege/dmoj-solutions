#include <bits/stdc++.h>
using namespace std;

// struct point {
// 	int x, y;
// };
using point = pair<int, int>;
vector<point> points;

struct pair_hash {
	size_t operator() (const pair<int, int> &p) const {
		return hash<int>()(p.first) ^ hash<int>()(p.second);
	}
};

enum dir {
	// clockwise
	UP, RIGHT, DOWN, LEFT
};



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	

	int n;
	cin >> n;

	vector<point> unsorted(n);
	for (auto& [x, y] : unsorted)
		cin >> x >> y;

	vector<int> indices(n);
	iota(indices.begin(), indices.end(), 0);
	sort(indices.begin(), indices.end(),
		[&unsorted] (const auto& l, const auto& r) {
			return unsorted[l] < unsorted[r];
		});

	
	points.resize(n);
	set<int> allStarts;
	unordered_map<int, int> revindices(n);
	for (int i = 0; i < n; ++i) {
		points[i] = unsorted[indices[i]];
		revindices.emplace(indices[i], i);
		allStarts.insert(i);
	}

	int w;
	cin >> w;
	unordered_map<int, unordered_map<int, int>> adj(n);
	unordered_set<int> wallsStanding(w);
	for (int i = 1; i <= w; ++i) {
		wallsStanding.insert(i);
		int A, B;
		cin >> A >> B;
		--A, --B;
		adj[revindices[A]].emplace(revindices[B], i);
		adj[revindices[B]].emplace(revindices[A], i);
	}


	// 0, 1, 2, 3 -> u, r, d, l
	auto getDir = [](int dx, int dy) {
		// same point or diagonal
		assert((dx == 0) != (dy == 0));
		return dx ?
			((dx > 0) ? RIGHT : LEFT) :
			((dy > 0) ? UP : DOWN);
	};


	vector<int> starts;
	starts.push_back(0);
	while (!starts.empty()) {
		// (cur, nxt), count
		unordered_map<pair<int, int>, int, pair_hash> edgeCount(n);

		for (int start : starts) {
			allStarts.erase(start);

			dir startDir = DOWN;
			for (auto [nxt, _] : adj[start]) {
				auto [cx, cy] = points[start];
				auto [nx, ny] = points[nxt];
				dir d = getDir(nx - cx, ny - cy);

				if (d == UP) {
					startDir = UP;
					break;
				}
				if (d == RIGHT) {
					startDir = RIGHT;
				}
			}
			if (startDir == DOWN)
				continue;


			dir cd = startDir;

			int cur = start;
			bool first = true;
			bool done = false;
			do {
				int nextPoints[4] = {-1, -1, -1, -1};
				pair<int, int> nextEdge[4];

				for (auto [nxt, wall] : adj[cur]) {
					if (!wallsStanding.contains(wall))
						continue;
					auto [cx, cy] = points[cur];
					auto [nx, ny] = points[nxt];
					dir d = getDir(nx - cx, ny - cy);
					
					nextPoints[d] = nxt;
					if (cur < nxt)
						nextEdge[d] = {cur, nxt};
					else
						nextEdge[d] = {nxt, cur};
				}
				

				for (int i = -1; i <= 2; ++i) {
					int x = cd + i;
					if (x < 0) x += 4;
					else if (x >= 4) x -= 4;
					dir d = static_cast<dir>(x);
					if (nextPoints[d] != -1) {
						if (!first && cur == start && d == startDir) {
							done = true;
						}
						else {
							cd = d;
							cur = nextPoints[d];
							++edgeCount[nextEdge[d]];
						}
						break;
					}
				}

				if (first) first = false;
			} while (!done);
		}

		int edgesRemoved = 0;

		for (auto [ed, cnt] : edgeCount) {
			if (cnt == 1) {
				++edgesRemoved;
				auto [cur, nxt] = ed;
				int wall = adj[cur][nxt];
				assert(cur != nxt);
				assert(wall != 0);

				wallsStanding.erase(wall);
				adj[cur].erase(nxt);
				if (adj[cur].empty()) {
					adj.erase(cur);
					allStarts.erase(cur);
				}
				adj[nxt].erase(cur);
				if (adj[nxt].empty()) {
					adj.erase(nxt);
					allStarts.erase(nxt);
				}
			}
		}
		if (edgesRemoved == 0)
			break;
		edgeCount.clear();


		starts.clear();
		unordered_set<int> vis(n);

		function<void(int)> dfs = [&](int cur) {
			for (auto [nxt, wall] : adj[cur]) {
				if (!wallsStanding.contains(wall) || vis.contains(nxt))
					continue;
				vis.insert(nxt);
				dfs(nxt);
			}
		};

		for (int cur : allStarts) {
			if (vis.contains(cur))
				continue;
			vis.insert(cur);
			starts.push_back(cur);
			dfs(cur);
		}
	}


	cout << wallsStanding.size() << "\n";
	vector<int> ans;
	ans.reserve(wallsStanding.size());
	for (int wall : wallsStanding)
		ans.push_back(wall);
	sort(ans.begin(), ans.end());
	for (int wall : ans)
		cout << wall << "\n";
}