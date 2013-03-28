/*
USER: zobayer
TASK: LCPC12F
ALGO: binary search
*/

#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long i64;

const int MAX = 100000;

int a[MAX];

int main() {
	int test, cs, n, i, ub, lb, x; i64 res;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%d %d", &x, &n);
		for(i = 0; i < n; i++) scanf("%d", &a[i]);
		sort(a, a + n);
		for(res = i = 0; i < n; i++) {
			ub = upper_bound(a, a + n, x-a[i]) - a;
			lb = lower_bound(a, a + n, x-a[i]) - a;
			res += ub - lb - (lb <= i && i < ub);
		}
		printf("%d. %lld\n", cs, res >> 1);
	}
	return 0;
}