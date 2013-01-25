/*
 * Author  : Xerxes
 * Program : 1108.cxx
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
const int max_node = (int)1000;
const int max_edge = (int)2000;
struct NODE{
	int u;
	int w;
	NODE(int b, int c):
	u(b),w(c){;}
};

int N,E;
vector< vector< NODE > > graph;// revgraph;

inline void Read(){
	CI(N);
	CI(E);
	int u,v,w;
	
	graph.assign( N+5, vector< NODE >() );
	//revgraph.assign( N+5, vector< NODE >() );
	fo(i,E){
		CI(u);
		CI(v);
		CI(w);
		graph[ v ].pb( NODE(u, w) );
		//revgraph[ u ].pb( NODE(v,w) );
	
	}
}
int dist[ max_node+10 ];

inline void BellmanFord(int source){
	fill( dist, dist+N+5, (int)1023456789 );
	
	dist[source]=0;
	for(int i=0;i<N-1; ++i ){
		for( int j=0;j<N;++j ){
			for( int k=0,l=SZ( graph[j] ); k<l; ++k ){
				int pre = dist[ graph[j][k].u ];
				int cur = dist[j] + graph[j][k].w ;
				
				if( cur < pre ){
					dist[ graph[j][k].u ] = cur;
				}
			}
		}
	}
	
}
int vis[ max_node+10 ];

inline void go( int source ){
	if( vis[ source ] == -1 ){
		vis[ source ] = 1;
		for( int i=0,j=SZ( graph[source] ); i<j; ++i ){
			go( graph[source][i].u );
		}
	}
}

inline void Detect(){
	SET( vis, -1 );
	for( int i=0;i<N; ++i){
		for( int j=0,k=SZ(graph[i]); j<k; ++j ){
			int pre = dist[ graph[i][j].u ];
			int cur = dist[i] + graph[i][j].w;
			if( cur < pre && ( vis[i]==-1 ) ){
				go( graph[i][j].u );
			}
		}
	}
}

inline void Proc(){
	BellmanFord(0);
	Detect();
	
	int found=false;
	for( int i=0;i<N;++i ){
		if( vis[ i ] !=-1 ){
			cout<<' '<<i;
			found=true;
		}
	}
	if( found==false ){
		cout<<" impossible";
	}
	cout<<'\n';
}
int main() {
	
	int cases = 1;
	int kase=1;
	for ( CI(cases) ; cases; --cases,++kase) {
			Read();
			cout<<"Case "<<kase<<':';
			Proc();
	}
	
	return 0;
} 
