#include <bits/stdc++.h>
using namespace std;

const int
	MAXN = 1e6,
	MAXH = ceil(log2(MAXN));

void Init();
void TypeLetter(char L);
void UndoCommands(int U);
char GetLetter(int P);


struct Tree {
	char letter;
	int depth;
	vector<Tree*> ancestry;

	Tree(char l, Tree* p = nullptr) : letter(l) {
		depth = p ? p->depth + 1 : 0;
		
		ancestry.resize(MAXH, nullptr);
		ancestry.front() = p;
		for (int i = 1; i < MAXH && ancestry[i - 1]; ++i)
			ancestry[i] = ancestry[i - 1]->ancestry[i - 1];
	}
};


vector<Tree*> history;
void Init() {
	history.reserve(MAXN);
}

void TypeLetter(char L) {
	history.push_back(history.empty() ?
		new Tree(L) :
		new Tree(L, history.back()));
}

void UndoCommands(int U) {
	history.push_back(history[history.size() - U - 1]);
}

char GetLetter(int P) {
	Tree* curr = history.back();

	int d = curr->depth - P;
	for (int i = MAXH - 1; i >= 0; --i) {
		int nd = d - (1 << i);
		// cout << d << "\n";
		if (nd >= 0) {
			d = nd;
			curr = curr->ancestry[i];
		}
	}
	// cout << d << "\n";
	return curr->letter;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin >> n;
	Init();
	
	do {
		char c;
		cin >> c;
		if (c == 'T') {
			char T;
			cin >> T;
			TypeLetter(T);
		}
		else if (c == 'U') {
			int U;
			cin >> U;
			UndoCommands(U);
		}
		else /*if (c == 'P') */{
			int P;
			cin >> P;
			cout << GetLetter(P) << "\n";
		}
	} while (--n);
}
