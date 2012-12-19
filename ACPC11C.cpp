/*
USER: zobayer
TASK: ACPC11C
ALGO: ad-hoc
*/

//#pragma warning (disable: 4786)
//#pragma comment (linker, "/STACK:0x800000")
//#define _CRT_SECURE_NO_WARNINGS 1

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
#define root 1
#define lft 2*idx
#define rgt 2*idx+1
#define cllft lft,st,mid
#define clrgt rgt,mid+1,ed
#define i64 long long
#define ld long double
#define pii pair< int, int >
#define psi pair< string, int >

const double EPS = 1e-9;
const int INF = 0x7f7f7f7f;
const int MAX = 100009;

int L[MAX];

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int test, i, n, sum, mn, res, x, y;
	cin >> test;
	while(test--) {
	    cin >> n;
	    for(i = 0; i < n; i++) {
	        cin >> L[i];
	    }
	    for(i = sum = 0; i < n; i++) sum += L[i];
	    for(i = x = 0, res = INF; i < n; i++) {
            y = sum - x - L[i];
            mn = 2*_min(x, y) + _max(x, y);
            res = _min(res, mn);
            x += L[i];
	    }
	    cout << res << endl;
	}
	return 0;
}

