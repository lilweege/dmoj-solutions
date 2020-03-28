#include <bits/stdc++.h>

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;

#include <regex>
std::string trim(std::string s) { return regex_replace(s, std::regex("(^[ ]+)|([ ]+$)"), ""); }

#define XMAX 2501
int x;

struct Leaf {
    int dp[XMAX];
    int v;
    Leaf* l;
    Leaf* r;
};

Leaf* createLeafC(Leaf* l, Leaf* r) {
    Leaf* newLeaf;
    newLeaf = (Leaf*)malloc(sizeof(Leaf));

    newLeaf->l = l;
    newLeaf->r = r;
    newLeaf->v = 0;

    return newLeaf;
}

Leaf* createLeafV(int v) {
    Leaf* newLeaf;
    newLeaf = (Leaf*)malloc(sizeof(Leaf));

    newLeaf->l = NULL;
    newLeaf->r = NULL;
    newLeaf->v = v;

    return newLeaf;
}


Leaf* createTree(std::string s) {

    if (s[0] != '(') return createLeafV(stoi(s));

    int len = s.length();
    s = trim(s.substr(1, len - 2));

    int i = 1;
    if (s[0] == '(') {
        //for (int cnt = 1; cnt != 0 && i < len; cnt += (s[i] == '(') - (s[i] == ')'), i++);
        for (int cnt = 1; cnt != 0; i++) {
            if (s[i] == '(') cnt++;
            else if (s[i] == ')') cnt--;
        }
    }
    else {
        i = s.find_first_of(' ');
    }

    return createLeafC(createTree(s.substr(0, i)), createTree(s.substr(i + 1)));
}


void calc(Leaf* leaf) {

    if (leaf->l) {
        calc(leaf->l);
        calc(leaf->r);

        int* dpl = (int*)malloc(XMAX * sizeof(int));
        int* dpr = (int*)malloc(XMAX * sizeof(int));

        for (int i = 0; i <= x; i++) {
            for (int w = 0; w <= i; w++) {
                int s = pow(w + 1, 2);
                int j = i - w;
                *(dpl + i) = std::max(*(dpl + i), std::min(s, leaf->l->dp[j]));
                *(dpr + i) = std::max(*(dpr + i), std::min(s, leaf->r->dp[j]));
            }
        }

        for (int i = 0; i <= x; i++) {
            for (int w = 0; w <= i; w++) {
                leaf->dp[i] = std::max(leaf->dp[i], *(dpl + w) + *(dpr + i - w));
            }
        }
    }
    else {
        for (int s = 0; s <= x; s++) {
            leaf->dp[s] = leaf->v + s;
        }
    }
}

int main() {
    std::string s;
    getline(std::cin, s);
    Leaf* root = createTree(s);

    scan(x);
    calc(root);

    printf("%d", root->dp[x]);
}