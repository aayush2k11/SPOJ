/*
USER: zobayer
TASK: GSS6
ALGO: splay tree
*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 200009;
const int INF = 0x7f7f7f7f;

inline bool scan_d(int &ret) {
	char c; int sgn;
	if(c=getchar(),c==EOF) return 0;
	while(c!='-'&&(c<'0'||c>'9')) c=getchar();
	sgn=(c=='-')?-1:1;
	ret=(c=='-')?0:(c-'0');
	while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
	ret*=sgn;
	return 1;
}

struct SplayTree {

	int root, n;
	int child[MAX][2], par[MAX];
	int cnt[MAX], key[MAX];
	int tsum[MAX], lsum[MAX], rsum[MAX], msum[MAX];

	void push_up(int x) {
		int lx = child[x][0], rx = child[x][1];
		cnt[x] = cnt[lx] + 1 + cnt[rx];
		tsum[x] = tsum[lx] + key[x] + tsum[rx];
		lsum[x] = max(lsum[lx], tsum[lx] + key[x] + max(0, lsum[rx]));
		rsum[x] = max(rsum[rx], tsum[rx] + key[x] + max(0, rsum[lx]));
		msum[x] = max(0, rsum[lx]) + key[x] + max(0, lsum[rx]);
		msum[x] = max(msum[x], max(msum[lx], msum[rx]));
	}

	void rotate(int x, int f) {
		int y = par[x], z = par[y];
		child[y][!f] = child[x][f];
		par[child[x][f]] = y; child[x][f] = y;
		par[y] = x; par[x] = z;
		if(par[x]) child[z][child[z][1] == y] = x;
		push_up(y);
	}

	void splay(int x, int t) {
		while(par[x] != t) {
			if(par[par[x]] == t) rotate(x, child[par[x]][0] == x);
			else {
				int y = par[x], z = par[y], f = (child[z][0] == y);
				if(child[y][f] == x) { rotate(x, !f); rotate(x, f); }
				else { rotate(y, f); rotate(x, f); }
			}
		}
		push_up(x);
		if(!t) root = x;
	}

	void rotate_to(int k, int t) {
		int x = root;
		while(cnt[child[x][0]] != k) {
			if(k < cnt[child[x][0]]) x = child[x][0];
			else { k = k - cnt[child[x][0]] - 1; x = child[x][1]; }
		}
		splay(x, t);
	}

	void new_node(int &x, int val) {
		x = ++n; child[x][0] = child[x][1] = par[x] = 0; cnt[x] = 1;
		key[x] = lsum[x] = rsum[x] = tsum[x] = msum[x] = val;
	}

	void build(int a[], int &x, int l, int r, int f) {
		if(l > r) return;
		int m = (l + r) >> 1;
		new_node(x, a[m]);
		build(a, child[x][0], l, m - 1, x);
		build(a, child[x][1], m + 1, r, x);
		par[x] = f;
		push_up(x);
	}

	void clear() {
		child[0][0] = child[0][1] = par[0] = cnt[0] = 0;
		root = n = 0; tsum[0] = 0;
		key[0] = lsum[0] = rsum[0] = msum[0] = -INF;
		new_node(root, -INF);
		new_node(child[root][1], -INF);
		par[n] = root;
		cnt[root] = 2;
	}

	void init(int a[], int pos, int tot) {
		clear();
		rotate_to(pos, 0);
		rotate_to(pos + 1, root);
		build(a, child[child[root][1]][0], 1, tot, child[root][1]);
		push_up(child[root][1]);
		push_up(root);
	}

	void insert(int pos, int val) {
		rotate_to(pos, 0);
		rotate_to(pos + 1, root);
		int k = child[child[root][1]][0];
		new_node(k, val);
		child[child[root][1]][0] = k;
		par[k] = child[root][1];
		push_up(child[root][1]);
		push_up(root);
	}

	void remove(int pos) {
		rotate_to(pos - 1, 0);
		rotate_to(pos + 1, root);
		int k = child[child[root][1]][0];
		child[child[root][1]][0] = 0;
		push_up(child[root][1]);
		push_up(root);
	}

	void replace(int pos, int val) {
		rotate_to(pos - 1, 0);
		rotate_to(pos + 1, root);
		int k = child[child[root][1]][0];
		key[k] = tsum[k] = lsum[k] = rsum[k] = msum[k] = val;
		push_up(child[root][1]);
		push_up(root);
	}

	int query(int l, int r) {
		rotate_to(l - 1, 0);
		rotate_to(r + 1, root);
		int k = child[child[root][1]][0];
		return msum[k];
	}

} spTree;

int a[100009];

int main() {
	int n, q, i, j, pos, val;
	char op[2];
	//freopen("in.txt", "r", stdin);
	//scanf("%d", &n);
	scan_d(n);
	for(i = 1; i <= n; i++) scan_d(a[i]); //scanf("%d", &a[i]);
	spTree.init(a, 0, n);
	//scanf("%d", &q);
	scan_d(q);
	while(q--) {
		scanf("%s", op);
		switch(op[0]) {
		case 'I':
			//scanf("%d %d", &pos, &val);
			scan_d(pos); scan_d(val);
			spTree.insert(pos - 1, val);
		break;
		case 'D':
			//scanf("%d", &pos);
			scan_d(pos);
			spTree.remove(pos);
		break;
		case 'R':
			//scanf("%d %d", &pos, &val);
			scan_d(pos); scan_d(val);
			spTree.replace(pos, val);
		break;
		default :
			//scanf("%d %d", &i, &j);
			scan_d(i); scan_d(j);
			printf("%d\n", spTree.query(i, j));
		break;
		}
	}
	return 0;
}