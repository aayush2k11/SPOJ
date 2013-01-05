/*
USER: zobayer
TASK: PCPC12I
ALGO: cumulative sum
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
#define mx 2000100
int d[mx];
pii us[mx];
pii ul[mx];

int main() {
	//READ("in.txt");
	//WRITE("out.txt");
	int i,n,sm,si,lg,li,r,qi,qj,qk,tt;
	while(cin>>n) {
		
		//cin>>n;
		//cin>>sm;
		for(i=1;i<=n;i++) scanf("%d",&d[i]);
		us[n]=ul[n]=pii(d[n],n);
		for(i=n-1;i>1;i--) {
			if(d[i]<=us[i+1].ff) {
				us[i]=pii(d[i],i);
			}
			else us[i]=us[i+1];
			if(d[i]>=ul[i+1].ff) {
				ul[i]=pii(d[i],i);
			}
			else ul[i]=ul[i+1];
		}
		lg=sm=d[1];
		si=li=1;
		r=-1;
		bool f=0;
		for(i=2;i<n;i++) {
			//scanf("%d",&x);
			//cout<<i<<' '<<d[i]<<' '<<sm<<' '<<us[i+1].ff<<' '<<us[i+1].ss<<'\n';
			//cout<<i<<' '<<d[i]<<' '<<lg<<' '<<ul[i+1].ff<<' '<<ul[i+1].ss<<'\n';
			if(d[i]>=sm && d[i]>=us[i+1].ff) {
				//cout<<1<<'\n';
				f=1;
				tt=2*d[i]-us[i+1].ff-sm;
				//cout<<i<<' '<<d[i]<<' '<<tt<<' '<<sm<<' '<<st.top().ff<<' '<<st.top().ss<<'\n';
				if(tt>r || (tt==r && si<qi)) {
					r=tt;
					qi=si;
					qj=i;
					qk=us[i+1].ss;
				}
			}
			if(d[i]<=lg && d[i]<=ul[i+1].ff) {
				//cout<<2<<'\n';
				f=1;
				tt=-2*d[i]+ul[i+1].ff+lg;
				if(tt>r || (tt==r && li<qi)) {
					r=tt;
					qi=li;
					qj=i;
					qk=ul[i+1].ss;
				}
			}
			
			
			if(d[i]>lg) {
				lg=d[i];
				li=i;
			}
			if(d[i]<sm) {
				sm=d[i];
				si=i;
			}
		}
		if(!f) printf("-1\n");
		else printf("%d %d %d\n",qi,qj,qk);
		//else cout<<qi<<' '<<qj<<' '<<qk<<'\n';
	}
	return 0;
}