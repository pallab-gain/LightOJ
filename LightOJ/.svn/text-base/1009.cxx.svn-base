/*
 * Author  : Xerxes
 * Program : Back to Underworld
 *
 *
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
const int max_relation = (int)20000;
const int max_node = (int)1e5+5;
const int mmxx = max_node*2 +5 ;
int root[ mmxx+5 ];
inline void _Set(){
	for(int i=0;i<=mmxx; ++i ){
		root[i]=i;
	}
}
inline int _Find(int x){
	if( x!= root[x] ){
		root[x] = _Find( root[x] );
	}
return root[x];
}

inline void _SetFriend(int x, int y){
	int fx = _Find(x);
	int fy = _Find(y);
	int ex = _Find(x+max_node);
	int ey = _Find(y+max_node);
	root[fy] = fx;
	root[ey] = ex;
}
inline void _SetEnemny(int x, int y){
	int fx = _Find(x);
	int fy = _Find(y);
	int ex = _Find(x+max_node);
	int ey = _Find(y+max_node);
	
	root[ex] = fy;
	root[ey] = fx;
}
inline bool isFriend(int x, int y){
	return _Find(x)==_Find(y);
}
inline bool isEnemy(int x, int y){
	int fx = _Find(x);
	int fy = _Find(y);
	int ex = _Find(x+max_node);
	int ey = _Find(y+max_node);
	
	return ( fx==ey || ey==ex ) ;
}
int kase = 1;
int nrelation;
int u,v;
int id[ max_node+5 ];
int D[ max_node+5 ];

inline void Proc(){
	
	SET(id,-1);
	SET(D,0);
	CI(nrelation);
	
	
	_Set();
	fo(i,nrelation){
		CI(u);
		CI(v);
		_SetEnemny(u,v);
		_SetFriend( _Find(u+max_node),v);
		_SetFriend( u ,_Find(v+max_node) );
		id[ u ] = id[ v ]= 1;
	}
	
	fo(i,max_node){
		if( id[i]!=-1 ){
			++D[ _Find(i) ];
		}
	}
	vector< pair<int,int> > vi;
	fo(i,max_node){
		if( id[i]!=-1 ){
			vi.pb( mk(D[i], i) );
		}
	}
	sort( vi.begin(), vi.end(), greater< pair<int,int> >() );
	int best = 0;
	int ep = -1;
	SET(id,0);
	
	for( int i=0,j=SZ( vi ) ; i<j ;++i ){
		if( id[ vi[i].s ]==0 ){
			//cout<<vi[i].f<<" "<<vi[i].s<<"\n";
			best+=vi[i].f;
			id[ _Find(vi[i].s) ]=1;
			id[ _Find(vi[i].s+max_node) ] = 1;
		}
	}

	cout<<"Case "<<kase<<": "<<best<<'\n';
	
}
int main() {
	
	int cases = 1;
	for ( CI(cases) ; cases; --cases,++kase) {
		Proc();
	}
	
	return 0;
} 
