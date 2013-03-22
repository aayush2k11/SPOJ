/*
USER: zobayer
TASK: VONNY
ALGO: backtracking
*/

#include <cstdio>
#include <cstring>

int flag[7][7];
int grid[7][8];
int mark[7][8];
int cnt;

#define chkf(x,y) flag[x][y]==0
#define setf(x,y) flag[x][y]=flag[y][x]=1
#define clrf(x,y) flag[x][y]=flag[y][x]=0

void count(int r, int c) {
	if(c == 8) {
		r++;
		c = 0;
	}
	if(r == 7) {
		cnt++;
		return;
	}
	if(mark[r][c]) count(r, c + 1);
	else {
		if(r + 1 < 7 && chkf(grid[r][c], grid[r+1][c]) && !mark[r][c] && !mark[r+1][c]) {
			setf(grid[r][c], grid[r+1][c]);
			mark[r][c] = mark[r+1][c] = 1;
			count(r, c+1);
			mark[r][c] = mark[r+1][c] = 0;
			clrf(grid[r][c], grid[r+1][c]);
		}
		if(c + 1 < 8 && chkf(grid[r][c], grid[r][c+1]) && !mark[r][c] && !mark[r][c+1]) {
			setf(grid[r][c], grid[r][c+1]);
			mark[r][c] = mark[r][c+1] = 1;
			count(r, c + 2);
			mark[r][c] = mark[r][c+1] = 0;
			clrf(grid[r][c], grid[r][c+1]);
		}
	}
}

int main() {
	int test, i, j;
	//freopen("in.txt", "r", stdin);
	scanf("%d", &test);
	while(test--) {
		for(i = 0; i < 7; i++) {
			for(j = 0; j < 8; j++) {
				scanf("%d", &grid[i][j]);
			}
		}
		cnt = 0;
		memset(flag, 0, sizeof flag);
		memset(mark, 0, sizeof mark);
		count(0, 0);
		printf("%d\n", cnt);
	}
	return 0;
}