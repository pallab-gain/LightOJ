/*
 * Author  : Pallab
 * Program : 1057
 * 
 * 2011-11-20 18:27:06
 * I have not failed, I have just found 10000 ways that won't work.
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
#include <iomanip>

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <cstring>
#include <cstdlib>

using namespace std;

#define VI vector< int >
#define CI( x ) scanf("%d",&x)
#define CL( x ) scanf("%lld",&x)
#define CD( x ) scanf("%lf",&x )
#define foR(i,st,ed) for(int i = st ; i < ed ; ++i )
#define fo(i,ed) foR( i , 0 , ed )
#define foE(i,st,ed) for(int i = st ; i <= ed ; ++i )
#define foit(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define bip system("pause")
#define Int long long
#define pb push_back
#define SZ(X) (int)(X).size()
#define LN(X) (int)(X).length()
#define mk make_pair
#define f first
#define s second
#define SET( ARRAY , VALUE ) memset( ARRAY , VALUE , sizeof(ARRAY) )

inline void wait(double seconds) {
	double endtime = clock()+(seconds * CLOCKS_PER_SEC);
	while (clock() < endtime) {
		;
	}
}
const int inf = (int)1e9;
int R,C;
char G[ 20 ][ 20 ];
inline void Read(){
	scanf("%d %d",&R,&C);
	fo(i,R){
		fo(j,C){
			cin>>G[i][j];
		}
	}
}
int ngold ;
pair<int,int> ng[ 16 ];
pair< int, int > H;
inline void collectg(){
	ngold=0;
	
	fo(i,R){
		fo(j,C){
			if( G[i][j]=='g' ){
				ng[ ngold ] = mk(i,j);
				++ngold;
			}
		}
	}
}
inline void collecth(){
	fo(i,R){
		fo(j,C){
			if( G[i][j]=='x' ){
				H = mk( i,j );
			}
		}
	}
}
int rr[]={-1,+1,+0,+0, -1,-1,+1,+1};
int cc[]={+0,+0,-1,+1, -1,+1,-1,+1};
int D[20][20];
int dist[ 25 ][ 25 ];
int dp[16][ 1<<16 ];
int maxbit;
inline void bfs(int x,int y){
	fo(i,20){
		fill(D[i],D[i]+20,inf);
	}
	
	queue< pair<int,int> > q;
	
	D[x][y]=0;
	q.push( mk(x,y) );
	
	while( q.empty()==false ){
		int r = q.front().f;
		int c = q.front().s;
		q.pop();
		
		fo(i,8){
			int tr = r+rr[i];
			int tc = c+cc[i];
			if( tr < 0 || tc < 0 || tr >= R || tc >= C)continue;
			int cc = D[r][c]+1;
			if( cc < D[tr][tc] ){
				D[tr][tc]=cc;
				q.push( mk(tr,tc) );
			}
		}
		
	}
}
inline bool isSelected(int msk, int bit){
	return ( ( msk&(1<<bit) )!=0 );
}
inline int Select(int msk, int bit){
	return ( msk|(1<<bit) ) ;
}

int go( int cur_p, int msk ){
	
	if( msk == maxbit ){
		return dist[ cur_p ][ 0 ];
	}
	int&best = dp[cur_p][msk];
	if( best !=-1 ){
		return best;
	}
	
	best = inf;
	for(int i=1;i<=ngold;++i){
		if( cur_p==0 ){
			int v = dist[0][i] + go( i, Select(msk,i) );
			if( v < best ){
				best = v ;
			}
		}
		else{
			if( isSelected(msk,i)==false ){
				int v = dist[cur_p][i]+go(i,Select(msk,i) );
				if( v < best ){
					best= v;
				}
			}
		}
	}
return best;
}
inline void Proc(){
	collectg();
	collecth();
	fo(i,ngold){
		bfs( ng[i].f , ng[i].s );
		for(int j=0;j<ngold;++j){
			dist[i+1][j+1]= D[ ng[j].f ][ ng[j].s ];
		}
		dist[i+1][0] = D[ H.f ][ H.s ];
	}
	bfs( H.f,H.s );
	for(int j=0;j<ngold;++j){
		dist[0][j+1] = D[ ng[j].f ][ ng[j].s ] ;
	}
	maxbit = ( 1<<(ngold+1) )-2;
	SET(dp,-1);
	int v = go(0,0);
	cout<<v<<"\n";
	
}
int main() {
	int t;
	CI(t);
	for(int i=1;i<=t;++i){
		Read();
		cout<<"Case "<<i<<": ";
		Proc();
	}
	
	return 0;
} 
