/*
 * Author  : Xerxes
 * Program : C.cxx
 *
 * 2011-11-10 03:13:57
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
#define CI( x ) scanf("%lld",&x)
#define CD( x ) scanf("%lf",&x )
#define foR(i,st,ed) for(int i = st ; i < ed ; ++i )
#define fo(i,ed) foR( i , 0 , ed )
#define foE(i,st,ed) for(int i = st ; i <= ed ; ++i )
#define foit(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define bip system("pause")
#define Int long long
#define pb push_back
#define SZ(X) (int)(X).size()
#define LN(X) (Int)(X).length()
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
Int n;
Int e; // edges that clear have
Int ne; // new proposed edges
Int dd; // can't be used more than d new edges
const Int maxn = 10005;
#define tp pair< Int , pair<Int,Int > > 
#define mmk( x, y , z ) mk( x, mk( y , z ) )

vector< vector< tp > > E;

inline void Read(){
	scanf("%lld %lld %lld %lld",&n,&e,&ne,&dd);
	E.assign(n, vector< tp >() );
	
	Int u,v,w;
	fo(i,e){
		scanf("%lld %lld %lld",&u,&v,&w);
		E[u].pb( mmk( v,w,0 ) );
		//E[v].pb( mmk( u,w,0 ) );
	}
	fo(i,ne){
		scanf("%lld %lld %lld",&u,&v,&w);
		E[u].pb( mmk( v,w,1 ) );
		//E[v].pb( mmk( u,w,1 ) );
	}
}

Int F[ maxn ][ 20 ];
Int D[ maxn ][ 20 ];
inline Int dj(Int sc, Int ds){
	// cost, koto gula use korchi, node number
	set< tp, less< tp > > pq;
	SET(F,-1);
	fo(i,maxn){
		fo(j,20){
			D[i][j]=(Int)1023456789;
		}
	}
	
	
	D[sc][0]=0;
	pq.insert( mmk(0,0,sc) );
	
	while( pq.empty()==false ){
		Int f = pq.begin()->s.s; // now father
		Int d = pq.begin()->s.f; // now used
		pq.erase(pq.begin());
		if( f==ds ){
			return  D[f][d] ;
		}
		if( F[ f ][d] !=-1 )continue;
		
		vector< tp > cango = E[ f ];
		
		for(Int i=0,j=SZ(cango); i<j; ++i ){
			Int c = cango[i].f; // kothay jete parbo
			Int cost = D[f][d] + cango[i].s.f; // koto cost a jete pari
			
			Int _d = d+cango[i].s.s; 
			
			
			if( F[ c ][ _d ]!=-1 )continue;
			if( _d > dd )continue;
			
			if( cost < D[ c ][ _d ] ){
				D[ c ][ _d ] = cost;
				pq.insert( mmk(cost,_d,c) );
			}
			
		}
		
		F[ f ][d] = 1;
	}
	
	
return -1;
}
inline void Proc(){
	Int var = dj(0,n-1);
	if( var==-1 ){
		cout<<"Impossible\n";
	}
	else{
		cout<<var<<"\n";
	}
	
}
int main() {

	Int t;
	CI(t);
	foE(i,1,t){
		Read();
		cout<<"Case "<<i<<": ";
		Proc();
	}
	
	return 0;
} 
