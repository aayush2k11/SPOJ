/*
USER: zobayer
TASK: PRHYME
ALGO: trie
*/

#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;

template< class T > T _abs(T n) { return (n < 0 ? -n : n); }
template< class T > T _max(T a, T b) { return (!(a < b) ? a : b); }
template< class T > T _min(T a, T b) { return (a < b ? a : b); }
template< class T > T sq(T x) { return x * x; }

#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const int POOL = 800000;
const int MAX = 250001;

struct Trie {
	int next[27];
	int min1, min2;
	inline void init() {
		min1 = min2 = INF;
	}
	inline void upd(int x) {
		if(x < min1) min2 = min1, min1 = x;
		else if(x < min2) min2 = x;
	}
} nodes[POOL];

int nextnode, root;
char dict[MAX][32];
int len[MAX], sorted[MAX];

void insert(char *s, int n) {
	int i, k, len = strlen(s), curr = root;
	nodes[curr].upd(n);
	for(i = len - 1; i >= 0; i--) {
		k = s[i] - 'a';
		if(!nodes[curr].next[k]) {
			nodes[curr].next[k] = nextnode++;
			nodes[nextnode-1].init();
		}
		curr = nodes[curr].next[k];
		nodes[curr].upd(n);
	}
	nodes[curr].next[26] = n+1;
}

bool find(char *s, int &id) {
	int i, k, len = strlen(s), curr = root;;
	for(i = len - 1; i >= 0; i--) {
		k = s[i] - 'a';
		if(!nodes[curr].next[k]) {
			id = nodes[curr].min1;
			return false;
		}
		curr = nodes[curr].next[k];
	}
	if(nodes[curr].next[26]) {
		id = nodes[curr].next[26]-1;
		return true;
	}
	id = nodes[curr].min1;
	return false;
}

int finddiff(char *s, int id) {
	int i, k, x, len = strlen(s), curr = root;
	for(i = len - 1; i >= 0; i--) {
		k = s[i] - 'a';
		x = nodes[curr].next[k];
		if(nodes[x].min2 == INF) {
			if(nodes[curr].min1 != id) return nodes[curr].min1;
			return nodes[curr].min2;
		}
		curr = x;
	}
	if(nodes[curr].min1 != id) return nodes[curr].min1;
	return nodes[curr].min2;
}

inline bool comp(int a, int b) {
	return strcmp(dict[a], dict[b]) < 0;
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int n = 0, i;
	char s[32];
	while(gets(dict[n]) && dict[n][0]) n++;
	for(i = 0; i < n; i++) sorted[i] = i;
	sort(sorted, sorted + n, comp);
	root = nextnode++;
	nodes[root].init();
	for(i = 0; i < n; i++) insert(dict[sorted[i]], i);
	while(gets(s)) {
		if(!find(s, i)) puts(dict[sorted[i]]);
		else puts(dict[sorted[finddiff(s, i)]]);
	}
	return 0;
}

