/*
USER: zobayer
TASK: PCPC12H
ALGO: min cost flow
*/

#include <cassert>
#include <cctype>
#include <climits>
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

#define ALL(p) p.begin(),p.end()
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
const int MAXN = 1 << 10;
const int MAXE = 1 << 20;

int src, snk, nNode, nEdge;
int fin[MAXN], pre[MAXN];
int next[MAXE], to[MAXE], from[MAXE];
i64 cap[MAXE], cost[MAXE], dist[MAXN], INF;

inline void init(int _src, int _snk, int nodes) {
	SET(fin);
	MEM(&INF, 0x3f);
	nNode = nodes, nEdge = 0;
	src = _src, snk = _snk;
}

inline void addEdge(int u, int v, i64 _cap, i64 _cost) {
	from[nEdge] = u, to[nEdge] = v, cap[nEdge] = _cap, cost[nEdge] = _cost;
	next[nEdge] = fin[u], fin[u] = nEdge++;
	from[nEdge] = v, to[nEdge] = u, cap[nEdge] = 0, cost[nEdge] = -(_cost);
	next[nEdge] = fin[v], fin[v] = nEdge++;
}

bool bellman() {
	int iter, u, v, i;
	bool flag = true;
	MEM(dist, 0x3f);
	SET(pre);
	dist[src] = 0;
	for(iter = 1; iter < nNode && flag; iter++) {
		flag = false;
		for(u = 0; u < nNode; u++) {
			for(i = fin[u]; i >= 0; i = next[i]) {
				v = to[i];
				if(cap[i] && dist[v] > dist[u] + cost[i]) {
					dist[v] = dist[u] + cost[i];
					pre[v] = i;
					flag = true;
				}
			}
		}
	}
	return (dist[snk] < INF);
}

i64 mcmf(i64 &fcost) {
	int u, c = 2;
	i64 netflow, bot;
	netflow = fcost = 0;
	while(c-- && bellman()) {
		bot = INF;
		for(u = pre[snk]; u >= 0; u = pre[from[u]]) bot = min(bot, cap[u]);
		for(u = pre[snk]; u >= 0; u = pre[from[u]]) {
			cap[u] -= bot;
			cap[u^1] += bot;
			fcost += bot * cost[u];
		}
		netflow += bot;
	}
	return netflow;
}

struct Node {
	i64 x, t, m;
} nd[MAXN];

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int n, i, j;
	while(scanf("%d", &n)==1 && n) {
		for(i = 1; i <= n; i++) {
			scanf("%lld %lld %lld", &nd[i].x, &nd[i].t, &nd[i].m);
		}
		init(1, 2*n+2, 2*n+3);
		for(i = 1; i <= n; i++) {
			for(j = 1; j <= n; j++) if(i != j) {
				if(nd[i].t + _abs(nd[i].x - nd[j].x) <= nd[j].t) {
					addEdge(2*i + 1, 2*j, 1, 0);
				}
			}
		}
		for(i = 1; i <= n; i++) {
			addEdge(2*i, 2*i+1, 1, -nd[i].m);
			addEdge(1, 2*i, 1, 0);
			addEdge(2*i+1, 2*n+2, 1, 0);
		}
		i64 dummy;
		mcmf(dummy);
		printf("%lld\n", -dummy);
	}
	return 0;
}