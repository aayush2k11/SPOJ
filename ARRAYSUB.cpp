/*
USER: zobayer
TASK: ARRAYSUB
ALGO: segment tree
*/

#include <cstdio>
#include <algorithm>
using namespace std;

const int MAX = 1 << 18;

int tree[MAX];
int a[1000000];

void update(int Node, int L, int R, int idx, int val) {
    if(L == R) {
        tree[Node] = val;
        return;
    }
    int mid = (L + R) >> 1, lt = Node << 1, rt = lt | 1;
    if(idx <= mid) update(lt, L, mid, idx, val);
    else update(rt, mid + 1, R, idx, val);
    tree[Node] = max(tree[lt], tree[rt]);
}

int main() {
    int n, k, i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++) scanf("%d", a + i);
    scanf("%d", &k);
    for(i = 0; i < k; i++) update(1, 0, k-1, i, a[i]);
    printf("%d", tree[1]);
    for(j = 0; i < n; i++, j++) {
        if(j == k) j = 0;
        update(1, 0, k-1, j, a[i]);
        printf(" %d", tree[1]);
    }
    printf("\n");
    return 0;
}
