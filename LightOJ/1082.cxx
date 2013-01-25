/*
 * Author  : Xerxes
 * Program : C.cxx
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
#define Int int
#define pb push_back
#define SZ(X) (int)(X).size()
#define LN(X) (int)(X).length()
#define mk make_pair
#define f first
#define s second
#define SET( ARRAY , VALUE ) memset( ARRAY , VALUE , sizeof(ARRAY) )
#define two( x )  ( 1<<(x) )

inline void wait(double seconds) {
	double endtime = clock()+(seconds * CLOCKS_PER_SEC);
	while (clock() < endtime) {
		;
	}
}
int M[ (int)100001 ][ 35 ];
int A[ (int)100001 ];
int N,Q;

inline void Read(){
	CI(N);
	CI(Q);
	fo(i,N){
		CI(A[i]);
	}
}


inline void ST(){
	int i,j;
	for(i=0;i<N;++i){
		M[i][0]=i;
	}
	
	for(j=1; two(j) <= N; ++j ){
		for( i=0; i+two(j)-1 < N; ++i ){
			int v1 = A[ M[i][j-1] ];
			int v2 = A[ M[i+ two(j-1)][j-1] ];
			if( v1 <= v2 ){
				M[i][j] = M[i][ j-1 ];
			}
			else{
				M[i][j] = M[i+ two(j-1)][j-1] ;
			}
		}
	}
}
inline int query( int start, int end){
	int dif = end - start;
	
	dif = 31 - __builtin_clz(dif+1);
	int v1 = A[ M[ start ][ dif ] ] ;
	int v2 = A[ M[ end-two(dif)+1][dif] ];
	if( v1 <= v2 ){
		return M[start][ dif ];
	}
	else{
		return M[end-two(dif)+1][dif];
	}
}

inline void Proc(){
	ST();
	int lo,hi;
	while(Q){
		CI(lo);
		CI(hi);
		--Q;
		int q = query(lo-1,hi-1);
		cout<< A[q]<<"\n";
	}
}
int main() {
	
	
	Int t;
	CI(t);
	for( Int i=1;i<=t; ++i){
		Read();
		cout<<"Case "<<i<<":\n";
		Proc();
	}
	
	return 0;
} 
