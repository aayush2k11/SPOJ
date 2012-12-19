/*
USER: zobayer
TASK: EXPEDI
ALGO: priory queue
*/

#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int main() {
	int test, cs, i, n, d, f, x, cnt;
	//freopen("in.txt", "r", stdin);
	scanf("%d", &test);
	for(cs = 1; cs <= test; cs++) {
		vector< pair< int, int > > stops;
		priority_queue< int > Q;
		
		scanf("%d", &n);
		for(i = 0; i < n; i++) {
			scanf("%d %d", &d, &f);
			stops.push_back(make_pair(d, f));
		}
		stops.push_back(make_pair(0, 0));
		sort(stops.begin(), stops.end());
		
		scanf("%d %d", &d, &f);
		for(cnt = 0, i = stops.size() - 1; i >= 0; i--) {
			x = d - stops[i].first;
			while(!Q.empty() && f < x) {
				cnt++;
				f += Q.top();
				Q.pop();
			}
			if(f < x) break;
			Q.push(stops[i].second);
		}
		if(i >= 0) printf("-1\n");
		else printf("%d\n", cnt);
	}
	return 0;
}
