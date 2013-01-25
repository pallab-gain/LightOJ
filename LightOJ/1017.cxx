/*
 * Author  : Xerxes
 * Program : 1017.cxx
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
const int max_case  = (int)100+5;
const int max_point = (int)100+5;
const int max_taken = (int)100+5;
int kase=1;
int npoint;
int w;
int k;
pair<int,int> point[ max_point ];
int dp[ max_point ][ max_taken ][ max_case ];

inline void Read(){
	scanf("%d %d %d",&npoint,&w,&k);
	int i;
	for(i=0;i<npoint;++i){
		scanf("%d %d",&point[i].f,&point[i].s);
	}
}

inline bool cmp( pair<int,int> A, pair<int,int> B ){
	return A.s > B.s ;
}

int go( int cp, int can_take){
	if( cp==npoint || can_take==0 ){
		return 0;
	}
		
	int& best = dp[ cp ][ can_take ][ kase ];
	if ( best!=-1 ){
		return best;
	}
	
	best = 0;
	// current ta na use kore
	int var1 = go( cp+1, can_take );
	if( var1 > best ){
		best = var1;
	}
	
	// current ta use kore
	int hii_y = point[cp].s;
	int low_y = hii_y-w;
	
	// went throught all points now
	int i,total=0;
	for(i=cp; i<npoint; ++i){
		if( point[i].s >= low_y && point[i].s <= hii_y ){
			++total;
		}
		else{
			break;
		}
	}
	int var2 = total+go(i,can_take-1);
	if( var2 > best ){
		best = var2;
	}
	
	
return best;
}
inline void Proc(){
		
		sort(point, point+npoint, cmp);
		int var = go( 0, k );
		cout<<"Case "<<kase<<": "<<var<<"\n";
}
int main() {
	/*
	#ifndef ONLINE_JUDGE
		freopen("in", "rt", stdin);
	#endif
	*/
	SET( dp, -1 );
	int cases = 1;
	for ( CI(cases) ; cases; --cases,++kase) {
			Read();
			Proc();
	}
	
	return 0;
} 
