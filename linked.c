#include <stdio.h>

typedef long long ll;
typedef unsigned long long ull;
#define mn 1000002

ull arr[mn];
int prv, cur, empty;

// max_n = 1e6 < 2**20
// max_x = 8e12 < 2**43 (+1 neg)
// => store nxt index in top bits of ll

const ll IDX = (ll)((1<<20)-1)<<44;
const ll VAL = (1LL<<44)-1;

int get_idx(int i) {
	return (int)((arr[i] & IDX) >> 44);
}

void set_idx(int i, int v) {
	arr[i] = (arr[i] ^ (arr[i] & IDX)) + ((ll)v << 44);
}

void set_val(int i, ll v) {
	arr[i] = (arr[i] ^ (arr[i] & VAL)) + v;
}

void next() { // >
	int nxt = get_idx(cur);
	set_idx(cur, prv);
	prv = cur;
	cur = nxt;
}

void prev() { // <
	int nxt = get_idx(prv);
	set_idx(prv, cur);
	cur = prv;
	prv = nxt;
}

ll get_x() {
	ll x;
	scanf("%lld", &x);
	if (x < 0)
		x = (-x) | (1LL << 43);
	return x;
}

void update() { // =
	set_val(cur, get_x());
}

void insert() { // +
	int nxt = empty;
	empty = get_idx(empty);
	set_val(nxt, get_x());
	set_idx(nxt, cur);
	cur = nxt;
}

void delete() { // -
	int freed = cur;
	cur = get_idx(cur);
	set_idx(freed, empty);
	empty = freed;
}

void print() { // !
	ll x = arr[cur] & VAL;
	if (x & (1LL << 43)) {
		x ^= 1LL << 43;
		printf("-%lld\n", x);
	}
	else {
		printf("%lld\n", x);
	}
}

int main() {
	prv = 0, cur = 1, empty = 2;
	for (int i = 1; i < mn; ++i)
		arr[i] = (ll)(i+1) << 44;

	int m;
	scanf("%d\n", &m);
	while (m--) {
		char op;
		scanf(" %c", &op);
		switch (op) {
			case '>': next(); break;
			case '<': prev(); break;
			case '=': update(); break;
			case '+': insert(); break;
			case '-': delete(); break;
			case '!': print(); break;
			default: break;
		}
	}
}