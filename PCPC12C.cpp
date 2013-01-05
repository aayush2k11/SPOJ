/*
USER: zobayer
TASK: PCPC12C
ALGO: brute force
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

enum {UP, RT, DN, LT};

string tiles[9];
int idx[9];

bool valid() {
	return (
		tiles[idx[0]][RT] == tiles[idx[1]][LT] &&
		tiles[idx[0]][DN] == tiles[idx[3]][UP] &&
		tiles[idx[1]][RT] == tiles[idx[2]][LT] &&
		tiles[idx[1]][DN] == tiles[idx[4]][UP] &&
		tiles[idx[2]][DN] == tiles[idx[5]][UP] &&
		tiles[idx[3]][RT] == tiles[idx[4]][LT] &&
		tiles[idx[3]][DN] == tiles[idx[6]][UP] &&
		tiles[idx[4]][RT] == tiles[idx[5]][LT] &&
		tiles[idx[4]][DN] == tiles[idx[7]][UP] &&
		tiles[idx[5]][DN] == tiles[idx[8]][UP] &&
		tiles[idx[6]][RT] == tiles[idx[7]][LT] &&
		tiles[idx[7]][RT] == tiles[idx[8]][LT]
	);
}

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int test, i;
	cin >> test;
	while(test--) {
		for(i = 0; i < 9; i++) {
			cin >> tiles[i];
			idx[i] = i;
		}
		do {
			if(valid()) break;
		} while(next_permutation(idx, idx + 9));
		for(i = 0; i < 9; i++) printf("%d", idx[i] + 1);
		printf("\n");
	}
	return 0;
}