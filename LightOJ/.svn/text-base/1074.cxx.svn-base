  /*
  * Author  : Xerxes
  * Program : 1074.cxx
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
 const int max_city = (int)200 ;
 int N; // number of city
 Int D[ max_city+10 ];
 int E; // number of edges
 vector< pair<int, int>  > edges;
 vector< vector< int > > cango;
 
 int Q; //number of query
 
 inline void Read(){
		CI( N );
		edges.clear();
		cango.assign( N, vector< int >() );
		fo(i,N){
			CL( D[i] );
		}
		
		CI(E);
		int u,v;
		fo(i,E){
			CI(u);
			CI(v);
			edges.pb(  mk(u-1,v-1) );
			cango[ u-1 ].pb( v-1 );
		}
 }
 Int dist[ max_city+5 ];
 inline Int calc( int u, int v ){
	 Int D1 = D[ u ];
	 Int D2 = D[ v ] ;
	 return (Int)( D2 - D1 )* (Int)( D2 - D1 )* (Int)( D2 - D1 );
 }
 
 inline void BellmanFord(int source){
	 for( int i=0; i<N; ++i ){
		 dist[i] = (Int)1023456789;
	 }
	 dist[ source ] = 0;
	 
	 for( int i=0; i < N-1; ++i ){
		 for( int j=0;j<E; ++j ){
			 Int pre = dist[ edges[j].s ];
			 Int cur = dist[ edges[j].f ] +calc( edges[j].f, edges[j].s) ;
			 
			 if( cur < pre ){
				 dist[ edges[j].s ] = cur ;
			 }
		 }
	 }
 }
 int vis[ max_city+10 ];
 
 inline void bfs(int source){
	 SET( vis, -1);
	 queue< int > q;
	 vis[ source ] = 0;
	 q.push( source );
	 
	 while( q.empty()==false ){
		 int f = q.front();
		 q.pop();
		 
		 for( int i=0,j=SZ( cango[f] ); i<j; ++i ){
			 int c = cango[f][i];
			 if( vis[c]==-1 ){
				 vis[c]=0;
				 q.push( c );
			 }
		 }
	 }
 }
 Int dd[ max_city+10 ];
 inline void detect(){
	 SET( dd, -1 );
	 
		for( int j=0;j<E; ++j ){
			 Int pre = dist[ edges[j].s ];
			 Int cur = dist[ edges[j].f ] +calc( edges[j].f, edges[j].s) ;
			 
			 //cout<<edges[j].f<<" "<<edges[j].s<<"\n";
			 if( cur < pre ){
				 dd[ edges[j].s ] = 0; // mean negative cycle present
			 }
			 else{
				 dd[ edges[j].s ] = pre;
			 }
		 }
 }

 inline void Proc(){
	 bfs(0);
	 BellmanFord(0);
	 detect();
	 
	 CI(Q);
	 int v;
	 fo(i,Q){
		CI(v); 
		if( dd[v-1] < 3 || vis[ v-1 ]==-1 ){
			cout<<"?\n";
		}
		else {
			cout<<dd[v-1]<<"\n";
		}
	 }
	 
 }
 int main() {
	
	 int cases = 1;
	 int kase = 1;
	 for ( CI(cases) ; cases; --cases,++kase) {
		 Read();
		 cout<<"Case "<<kase<<":\n";
		 Proc();
	 }
	 
	 return 0;
 }