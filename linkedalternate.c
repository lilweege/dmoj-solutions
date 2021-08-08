#include <stdio.h>

typedef long long ll;
#define mn 1000002

// max_n = 1e6 < 2**20
// max_x = 8e12 < 2**43 (+1 neg)
// => store nxt index in top bits of ll

typedef struct node node;
// bit field go brr
struct node {
	unsigned idx: 20;
	ll val: 44;
}; // no need to tell compiler to pack

node arr[mn];
unsigned prv, cur, empty;

void next() { // >
	unsigned nxt = arr[cur].idx;
	arr[cur].idx = prv;
	prv = cur;
	cur = nxt;
}

void prev() { // <
	unsigned nxt = arr[prv].idx;
	arr[prv].idx = cur;
	cur = prv;
	prv = nxt;
}

void update() { // =
	ll x;
	scanf("%lld", &x);
	arr[cur].val = x;
}

void insert() { // +
	ll x;
	scanf("%lld", &x);
	unsigned nxt = empty;
	empty = arr[empty].idx;
	arr[nxt].idx = cur;
	arr[nxt].val = x;
	cur = nxt;
}

void delete() { // -
	unsigned freed = cur;
	cur = arr[cur].idx;
	arr[freed].idx = empty;
	empty = freed;
}

void print() { // !
	// implicit conversion works despite compiler warning
	printf("%lld\n", arr[cur].val);
}

int main() {
	prv = 0, cur = 1, empty = 2;
	for (unsigned i = 1; i < mn; ++i)
		arr[i].idx = i+1;

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