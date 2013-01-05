/*
USER: zobayer
TASK: PCPC12D
ALGO: sorting
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
const int INF = 0x7f7f7f7f;
const int MAX = 1024;
const int LEN = 256;

char str[MAX][LEN];
int cnt[MAX][26];
int idx[MAX];

bool comp(int i, int j) {
	for(int k = 0; k < 26; k++) {
		if(cnt[i][k] > cnt[j][k]) return true;
		if(cnt[i][k] < cnt[j][k]) return false;
	}
	return i<j;
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int test, n, i, j, cs;
	char buff[2];
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d", &n);
		gets(str[0]);
		for(i = 0; i < n; i++) {
			gets(str[i]);
			idx[i] = i;
			CLR(cnt[i]);
			for(j = 0; str[i][j]; j++) {
				if(isalpha(str[i][j])) {
					cnt[i][tolower(str[i][j])-'a']++;
				}
			}
		}
		sort(idx, idx + n, comp);
		printf("case: %d\n", cs);
		for(i = 0; i < n; i++) {
			printf("%s\n", str[idx[i]]);
		}
	}
	return 0;
}