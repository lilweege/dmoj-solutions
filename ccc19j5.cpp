// this solution is not optimal, but is sufficient to pass official tests
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

// too lazy to work out the exact upper bound
// #define MAX 200
#define MAX 64
#define B_LO 'A'
#define B_HI 'B'

// turns out that the gain of using bitset is useless since
// string operations are nothing in comparison to the bfs
struct seq {
	size_t n;
	bitset<MAX> bs;

	seq() = default;
	seq(const string& s) : n(size(s)), bs(s, 0, n, B_LO, B_HI) {}
	
	[[nodiscard]] auto to_string() const -> string {
		return bs.to_string(B_LO, B_HI).substr(size(bs)-n);
	}

	auto replace(const seq& x, size_t i, size_t l) -> void {
		// insert x into self at position i replacing length l
		int grow = int(x.n - l);
		if (grow > 0) {
			bs <<= grow;
			for (size_t b = 0; b < i; ++b)
				bs[b] = bs[b+grow];
		}
		else if (grow < 0) {
			for (size_t b = i-1; b+1 > 0; --b)
				bs[b-grow] = bs[b];
			bs >>= -grow;
		}
		for (size_t b = i; b < i+x.n; ++b)
			bs[b] = x.bs[b-i];
		n += grow;
	}

	[[nodiscard]] auto find_all(const seq& s) const -> vector<size_t> {
		vector<size_t> all;
		size_t m = s.n;

		vector<int> lps(m);
		for (size_t i = 1; i < m; ++i) {
			size_t j = lps[i-1];
			while (j > 0 && s.bs[i] != s.bs[j])
				j = lps[j-1];
			if (s.bs[i] == s.bs[j])
				++j;
			lps[i] = int(j);
		}

		for (size_t i = 0, j = 0; i < n;) {
			if (s.bs[j] == bs[i])
				++i, ++j;
			if (j == m) {
				all.push_back(i-j);
				j = lps[j-1];
			}
			else if (i < n && s.bs[j] != bs[i]) {
				if (j)
					j = lps[j-1];
				else
					++i;
			}
		}
		return all;
	}

	auto operator == (const seq& o) const -> bool {
		return bs == o.bs && n == o.n;
	}
};

struct seq_hash {
	auto operator () (const seq &s) const -> size_t {
		return hash<bitset<MAX>>()(s.bs) ^ hash<size_t>()(s.n);
		// return hash<string>()(s.to_string());
	}
};

struct sub {
	size_t r, p; // one indexed
	seq s;
};

struct rule {
	seq fr, to;
};

auto main() -> int {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	array<rule, 3> rules;
	for (auto& [fr, to] : rules) {
		string a, b;
		cin >> a >> b;
		fr = a, to = b;
	}

	int N; // steps
	string a, b;
	cin >> N >> a >> b;
	seq S(a), T(b); // start, end
	
	// this approach is sufficient for naive datasets
	// for which the breadth size does not blow up
	auto half = [&](auto& q, const seq& s, bool fwd) -> void {
		size_t n = size(q);
		q[0].emplace(s, sub(0, 0, seq(""))); // filler value
		for (size_t i = 1; i < n; ++i)
			for (auto& [cur, _] : q[i-1])
				for (size_t r = 1; r <= size(rules); ++r) {
					auto& [fr, to] = rules[r-1];
					if (!fwd) swap(fr, to);
					for (size_t pos : cur.find_all(fr)) {
						seq nxt = cur; nxt.replace(to, pos, fr.n);
						q[i].emplace(nxt, sub(r, cur.n-fr.n-pos+1, cur));
					}
					if (!fwd) swap(fr, to);
				}
	};

	vector<unordered_map<seq, sub, seq_hash>> qf(N/2+1), qb(N-N/2+1);
	half(qf, S, true);
	half(qb, T, false);

	// string cur_check = S.to_string();
	// int step_check = 0;
	for (auto& [mid, _] : qf.back())
		if (qb.back().contains(mid)) {
			vector<sub> ans1;
			seq cur = mid;
			for (auto& x : qf | views::drop(1) | views::reverse) {
				auto& nxt = x.find(cur)->second;
				ans1.emplace_back(nxt.r, nxt.p, cur);
				cur = nxt.s;
			}
			for (auto& [r, p, s] : ans1 | views::reverse) {
				// cur_check = cur_check.substr(0, p-1) + rules[r-1].to.to_string() + cur_check.substr(p-1 + rules[r-1].fr.n);
				// assert(cur_check == s.to_string());
				// ++step_check;
				cout << r << " " << p << " " << s.to_string() << "\n";
			}
			cur = mid;
			for (auto& x : qb | views::drop(1) | views::reverse) {
				auto& [r, p, s] = x.find(cur)->second;
				// cur_check = cur_check.substr(0, p-1) + rules[r-1].to.to_string() + cur_check.substr(p-1 + rules[r-1].fr.n);
				// assert(cur_check == s.to_string());
				// ++step_check;
				cout << r << " " << p << " " << s.to_string() << "\n";
				cur = s;
			}
			// assert(cur_check == T.to_string());
			// assert(step_check == N);
			return 0;
		}
	// something went wrong (queues didn't meet in middle)
	assert(false);
}
