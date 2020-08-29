#include <bits/stdc++.h>
using namespace std;

int numIslands(vector<vector<char>>& grid) {
	int cnt = 0;
	int r = grid.size(), c = grid[0].size();
	
	
	vector<pair<int, int>> transform = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
	auto pointRect = [&](int px, int py, int rx, int rw, int ry, int rh) { return (rx <= px) && (px < (rx + rw)) && (ry <= py) && (py < (ry + rh)); };
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (grid[i][j] == '1') {
				cnt++;
				queue<pair<int, int>> q;
				q.push({i, j});
				while (!q.empty()) {
					pair<int, int> cur = q.front(); q.pop();
					int y = cur.first, x = cur.second;
					if (grid[y][x] == '1') {
						grid[y][x] = 'v';
						for (pair<int, int> t : transform) {
							int ny = y + t.first, nx = x + t.second;
							if (pointRect(nx, ny, 0, c, 0, r)) {
								q.push({ny, nx});
							}
						}
					}
				}
			}
		}
	}
	return cnt;
}

int main() {
	vector<vector<char>> grid = {
		{'1','1','0','0','0'},
		{'1','1','0','0','0'},
		{'0','0','1','0','0'},
		{'0','0','0','1','1'}
	};
	cout << numIslands(grid) << endl;
}