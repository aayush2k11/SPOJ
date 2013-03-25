/*
USER: zobayer
TASK: FINDPRM
ALGO: prime, sieve
*/

#include <cstdio>

const int MAX = 10010896;
const int LMT = 3164;
const int N = 10000001;

int flag[MAX >> 6], ans[N];

#define ifc(i) (flag[i>>6]&(1<<((i>>1)&31)))
#define isc(i) (flag[i>>6]|=(1<<((i>>1)&31)))

#define chk(n) (n==2||(n>2&&(n&1)&&!ifc(n)))

void sieve() {
    int i, j, k;
    for(i = 3; i < LMT; i+=2) if(!ifc(i)) for(j = i * i, k = i << 1; j < MAX; j += k) isc(j);
}

void calc() {
    ans[0] = ans[1] = 0;
    for(int i = 2, j; i < N; i++) {
        ans[i] = ans[i-1];
        j = i >> 1;
        if((i & 1) == 0 && chk(j)) ans[i]--;
        if(chk(i)) ans[i]++;
    }
}

int main() {
    sieve();
    calc();
    int t, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
    return 0;
}
