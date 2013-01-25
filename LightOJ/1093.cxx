/*
 * Author  : Xerxes
 * Program : G.cxx
 *
 * 2011-11-11 15:00:31
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

#define LC( x ) ( x )*2
#define RC( x ) ( ( x )*2 ) + 1

const int inf = (int)1e6;
const int maxn = (int)1e5;

struct NODE{
	int lo;
	int hi;
	NODE( int lo=inf,  int hi=-inf)
		: lo(lo),hi(hi){;}
};

NODE tree[ maxn*4 ];
int vi[ maxn ];

void Ini(){
	fill( tree, tree+maxn, NODE() );
}

inline NODE Get(NODE A, NODE B){
	int a = min( A.lo , B.lo );
	int b = max( A.hi , B.hi );
return NODE(a,b);
}

void Build(int f, int l, int r){
	if( l==r ){
		tree[f] = NODE( vi[ l ] , vi[ l ] );
	}
	else{
		int m = (l+r)>>1;
		Build( LC(f) ,  l, m );
		Build( RC(f) , m+1,  r );
		tree[ f ] =  Get( tree[ LC(f) ] , tree[ RC(f) ] );
	}
}
NODE Query(int f, int l, int r, int a, int b){
	if( a > b ){
		return  NODE();
	}
	if( l==a && r==b ){
		return tree[ f ];
	}
	
	int m = ( l+r )>>1;

	NODE lv = Query( LC(f), l  , m , a , min( b , m) );
	NODE rv = Query( RC(f), m+1, r , max(a,m+1), b  );
	
return Get( lv, rv );
}

int n,d;
inline void Read(){
	CI(n);
	CI(d);
	fo(i,n){
		CI(vi[i]);
	}
}
inline void Proc(){
	Ini();
	Build(1,0,n-1);
	int best = 0;
	for(int i=0;i+d-1<n;++i){
		NODE tmp = Query(1,0,n-1,i,i+d-1);
		best = max( best, tmp.hi-tmp.lo );
	}
	cout<<best<<'\n';
}

int main() {
	
	int t;
	CI(t);
	foE(i,1,t){
		Read();
		cout<<"Case "<<i<<": ";
		Proc();
	}
	
	return 0;
} 
 
