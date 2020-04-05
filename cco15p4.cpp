#include <bits/stdc++.h>
using namespace std;

int n, m;
vector< vector<char> > lot;
set< pair<int, int> > valid;

void dfs(int r, int c) {
	if (lot[r][c] == 'S') {
		for (int y = r + 1; y < n; y++)
			if (lot[y][c] != '.') dfs(y, c);
	}
	else if (lot[r][c] == 'N') {
		for (int y = r - 1; y >= 0; y--)
			if (lot[y][c] != '.') dfs(y, c);
	}
	else if (lot[r][c] == 'E') {
		for (int x = c + 1; x < m; x++)
			if (lot[r][x] != '.') dfs(r, x);
	}
	else if (lot[r][c] == 'W') {
		for (int x = c - 1; x >= 0; x--)
			if (lot[r][x] != '.') dfs(r, x);
	}
	printf("(%i,%i)\n", r, c);

	lot[r][c] = '.';
	valid.erase(make_pair(r, c));
}

int main() {
	scanf("%i%i", &n, &m);

	lot.resize(n);
	fill(lot.begin(), lot.end(), vector<char>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &lot[i][j]);
			if (lot[i][j] != '.') {
				valid.insert(make_pair(i, j));
			}
		}
	}

	while (!valid.empty()) {
		int r = valid.begin()->first, c = valid.begin()->second;
		dfs(r, c);
	}
}
