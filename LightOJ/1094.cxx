/*
 * Author  : Xerxes
 * Program : 1094.cxx
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
const int max_node = (int)30000 ;

struct NODE{
	int u;
	int w;
	NODE( int a, int b ):
	u(a),w(b){;}
};

int N;
vector< vector<NODE>  > E;

inline void Read(){
	CI(N);
	E.assign( N, vector< NODE >() );
	int u,v,w;
	for( int i=1; i<N; ++i ){
		CI(u);
		CI(v);
		CI(w);
		E[u].pb( NODE(v,w) );
		E[v].pb( NODE(u,w) );
	}
}

int D[ max_node ];
int F[ max_node ];

inline void dj(int source){
	fill(D, D+N, (int)1023456789);
	SET(F,-1);
	
	set< pair<int,int> , less< pair<int,int> > > pq;
	
	pq.insert( mk(0,source) );
	D[ source ] = 0;
	
	while( pq.empty()==false ){
		int f = pq.begin()->s;
		pq.erase( pq.begin() );
		
		if( F[f]!=-1 )continue;
		
		vector< NODE > cango = E[ f ];
		for( int i=0,j=SZ(cango); i<j; ++i){
			int c = cango[i].u;
			int d = cango[i].w;
			
			if( F[c]==-1 && ( D[f]+d < D[c] ) ){
				D[c] = D[f]+d;
				pq.insert( mk(D[c], c) );
			}
		}
		
		F[f]=1;
		
	}
}
int dist;
int id;
int prothom;
inline void give_farther(){
	prothom = 1;
	
	for(int i=0;i<N;++i){
		if( prothom ){
			dist = D[i];
			id = i;
			prothom = 0;
		}
		else{
			if( D[i] > dist ){
				dist = D[i];
				id = i;
			}
		}		
	}
}
inline void Proc(){
	dj(0);
	give_farther();
	dj( id );
	give_farther();
	
	cout<<dist<<'\n';	
}

int main() {
	
	int cases = 1;
	int kase = 1;
	for ( CI(cases) ; cases; --cases,++kase) {
		Read();
		cout<<"Case "<<kase<<": ";
		Proc();
	}
	
	return 0;
} 
