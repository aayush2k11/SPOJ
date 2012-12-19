/*
USER: zobayer
TASK: FIBTWIST
ALGO: matrix exponentiation
*/

#include <cstdio>
#include <cstring>

typedef long long i64;

const i64 base[2][2] = {{1, 1}, {1, 0}}, unit[2][2] = {{1, 0}, {0, 1}};

void mul(i64 a[2][2], i64 b[2][2], i64 mod) {
	int i, j, k;
	i64 c[2][2];
	for(i = 0; i < 2; i++) {
		for(j = 0; j < 2; j++) {
			for(c[i][j] = k = 0; k < 2; k++) {
				c[i][j] += a[i][k] * b[k][j];
				if(c[i][j] >= mod) c[i][j] %= mod;
			}
		}
	}
	memcpy(a, c, sizeof(i64)*4);
}

void exp(i64 res[2][2], i64 p, i64 mod) {
	i64 b[2][2];
	memcpy(res, unit, sizeof(i64)*4);
	memcpy(b, base, sizeof(i64)*4);
	while(p > 0) {
		if(p & 1) mul(res, b, mod);
		mul(b, b, mod);
		p >>= 1;
	}
}

i64 fib(i64 n, i64 mod) {
	i64 res[2][2];
	if(!n) return 0;
	exp(res, n - 1, mod);
	return res[0][0];
}

int main() {
	int test, cs;
	i64 n, m, res;
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		scanf("%lld %lld", &n, &m);
		res = (2*(fib(n+2, m) - 1) - n) % m;
		if(res < 0) res += m;
		printf("%lld\n", res);
	}
	return 0;
}
