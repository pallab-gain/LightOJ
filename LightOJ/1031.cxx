/*
 * Author  : Xerxes
 * Program : 1031.cxx
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
const int inf =  (int)1e9;
const int big_value = (int)100;
int N,kase=1;
int vi[ big_value+1 ];

int dp[ big_value ][ big_value ] ;

inline void Read(){
	CI( N );
	fo(i,N){
		CI( vi[i] );
	}
}
int go( int st, int ed ){
	if( st > ed ){
		return 0;
	}
	
	int& best = dp[st][ed];
	if( best==-1 ){
		best = -inf;
		int sum1=0;
		for(int i=st; i<=ed; ++i){
			sum1 = sum1+vi[i];
			int var = sum1-go(  i+1, ed );
			best = max( best,  var  );
		}
		int sum2=0;
		for(int i=ed; i>=st; --i){
			sum2 = sum2+vi[i];
			int var = sum2  - go( st,  i-1);
			best = max( best, var );
		}
	}
return best; 
}
inline void Proc(){
	SET(dp,-1);
	int var = go( 0, N-1  );
	cout<<"Case "<<kase<<": "<<var<<'\n';
	
}

int main() {
	
	int cases = 1;
	for ( CI(cases) ; cases; --cases,++kase) {
		Read();
		Proc();
	}
	
	return 0;
} 
