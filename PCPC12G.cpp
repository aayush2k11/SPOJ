/*
USER: zobayer
TASK: PCPC12G
ALGO: dynamic programming
*/
#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int dp[101][20001];
int vis[101][20001];
int flag, p[101];
int n, m, t;

int solve(int row, int ppl) {
	if(ppl <= 0) return 0;
	if(row >= n) return INF;
	if(vis[row][ppl] == flag) return dp[row][ppl];
	vis[row][ppl] = flag;
	int &ret = dp[row][ppl];
	ret = solve(row + 1, ppl - m + p[row] * 2) + p[row];
	if(row + 1 < n) ret = min(ret, solve(row + 2, ppl - m + p[row + 1] * 2) + p[row + 1]);
	return ret;
}

int main() {
	//freopen("in.txt", "r", stdin);
	for(flag = 1; scanf("%d %d %d", &n, &m, &t) == 3; flag++) {
		for(int i = 0; i < n; i++) scanf("%d", &p[i]);
		printf("%d\n", solve(0, t));
	}
	return 0;
}