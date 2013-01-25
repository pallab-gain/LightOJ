/*
 * Author  : Pallab
 * Program : 1002.cxx
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
int kase;
int n; // number of nodes
int ne; // number of bi-directional edges
int myIndex; 

		//  (cango, cost)
vector< vector< pair<int,int> > > E ; // number of edges in the graph

inline void Read(){
	scanf("%d %d",&n,&ne);
	//initialiges E
	E.assign( n, vector< pair<int,int> >() );
	int u,v,w;
	fo(i,ne){
		scanf("%d %d %d",&u,&v,&w);
		E[u].pb( mk(v,w) ); // from 'U' I can go 'V' with cost 'W'
		E[v].pb( mk(u,w) ); // from 'V' I can go 'U' with cost 'W'
	}
	
	scanf("%d",&myIndex);
	
}
const int big_value = (int)1e20;
const int max_node = (int)500+10;
int D[ max_node ] ;

inline void bfs(int source){
		int i,j;
		for(i=0;i<n;++i){
			D[i]= big_value;
		}
		
		queue< int > q;
		D[ source ] = 0;
		q.push( source );
		
		while( q.empty()==false ){
			int father = q.front();
			q.pop();
			
			vector< pair<int,int> > cango = E[father];
			
			for(i=0,j=SZ(cango); i<j;++i ){
				int child = cango[i].f;
				int cosst = max( cango[i].s , D[father] );
				if( cosst < D[ child ] ){
					D[ child ] = cosst;
					q.push( child );
				}
			}
		}
	
	
}

inline void Proc(){
	bfs( myIndex );
	int i;
	printf("Case %d:\n",kase);
	for(i=0;i<n;++i){
		int d = D[ i ];
		if( d >= big_value ){
			printf("Impossible\n");
		}
		else{
			printf("%d\n",d);
		}
	}
	
}
int main() {
	/*
	#ifndef ONLINE_JUDGE
		freopen("in", "rt", stdin);
	#endif
	*/
	int cases ;
	kase=1;
	for ( CI(cases) ; cases; --cases,++kase) {
		Read();
		Proc();
	}
	
	return 0;
} 
