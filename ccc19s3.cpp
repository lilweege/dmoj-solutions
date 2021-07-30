#include <bits/stdc++.h>
using namespace std;

// this problem sucks lol

// lmaoo rng submission
auto randint(int a, int b) { // [a, b]
	return rand() % (a - b - 1) + a;
}

const int UNSET = INT_MAX / 2; // > BOUND
const int BOUND = 1000000000;
const int NUM_ITERS = 10;


auto ok(int e) {
	return e != UNSET;
};

auto done(const vector<vector<int>>& m) {
	for (auto r : m) {
		for (auto e : r)
			cout << e << " ";
		cout << "\n";
	}
	exit(0);
}

auto trivial(vector<vector<int>>& m) {
	for (int _ = 0; _ < 2; ++_) {
		for (int i = 0; i < 3; ++i) {
			if (ok(m[i][1]) && ok(m[i][2]) && !ok(m[i][0]))
				m[i][0] = 2 * m[i][1] - m[i][2];
			if (ok(m[i][0]) && ok(m[i][2]) && !ok(m[i][1]))
				m[i][1] = (m[i][0] + m[i][2]) / 2;
			if (ok(m[i][0]) && ok(m[i][1]) && !ok(m[i][2]))
				m[i][2] = 2 * m[i][1] - m[i][0];
		}
		for (int j = 0; j < 3; ++j) {
			if (ok(m[1][j]) && ok(m[2][j]) && !ok(m[0][j]))
				m[0][j] = 2 * m[1][j] - m[2][j];
			if (ok(m[0][j]) && ok(m[2][j]) && !ok(m[1][j]))
				m[1][j] = (m[0][j] + m[2][j]) / 2;
			if (ok(m[0][j]) && ok(m[1][j]) && !ok(m[2][j]))
				m[2][j] = 2 * m[1][j] - m[0][j];
		}
	}
}

auto has_x(const vector<vector<int>>& m) {
	for (auto r : m)
		for (auto e : r)
			if (e == UNSET)
				return true;
	return false;
}

auto valid(const vector<vector<int>>& m) {
	for (int i = 0; i < 3; ++i) {
		if (!ok(m[i][0]) || !ok(m[i][1]) || !ok(m[i][2]))
			continue;
		if (m[i][2] - m[i][1] != m[i][1] - m[i][0])
			return false;
	}
	for (int j = 0; j < 3; ++j) {
		if (!ok(m[0][j]) || !ok(m[1][j]) || !ok(m[2][j]))
			continue;
		if (m[2][j] - m[1][j] != m[1][j] - m[0][j])
			return false;
	}
	return true;
};

auto solve(vector<vector<int>> m) {
	trivial(m);
	if (!valid(m))
		return make_pair(false, m);
	if (!has_x(m))
		return make_pair(true, m);
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j) {
			if (m[i][j] != UNSET)
				continue;
			for (int _ = 0; _ < NUM_ITERS; ++_) {
				m[i][j] = randint(-BOUND >> 3, BOUND >> 3);
				auto [good, nm] = solve(m);
				if (good)
					return make_pair(true, nm);
			}
		}
	
	return make_pair(false, m);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	srand(time(0));
	
	vector<vector<int>> m(3, vector<int>(3, UNSET));

	int n = 0;
	for (auto& r : m)
		for (auto& e : r) {
			string s;
			cin >> s;
			if (s != "X") {
				++n;
				e = stoi(s);
			}
		}


	if (n == 0) {
		for (auto& r : m)
			for (auto& e : r)
				e = 0;
		done(m);
	}
	if (n == 1) {
		auto get_one = [&m]() {
			for (auto r : m)
				for (auto e : r)
					if (e != UNSET)
						return e;
			return -1;
		};
		int x = get_one();
		for (auto& r : m)
			for (auto& e : r)
				e = x;
		done(m);
	}

	done(solve(m).second);
}