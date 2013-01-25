/*
 * Author  : Pallab
 * Program :  1013.cxx
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

int kase=1;
string s1,s2;
int l1, l2;
int dp[ 40 ][ 40 ];
Int cando[ 40 ][ 40 ][ 80 ];



inline void Read(){
    cin>>s1>>s2;
    l1 = LN( s1 );
    l2 = LN( s2 );
}



// give the least possible substring that contains both
// x as current index of s1
// y as current index of s2
int go( int x, int y ){
	// if all first and second string done
	if( x==l1 && y == l2 ){
		return 0;
	}
	
	int &best = dp[ x ][ y ];
	if( best!=-1 ){
		return best;
	}
	
	best = (int)1e9;
	// if first done and second not  done
	if( x==l1 && y!=l2 ){
		int v =  1+go( x, y+1 );
		best = min( best, v );
	}
	// if first now done and second done
	else if( x!=l1 && y==l2 ){
		int v =  1+go( x+1, y );
		best = min( best, v );
	}
	
	else if( s1[x]==s2[y] ){
		int v1 = 1+go( x+1, y+1 );
		int v2 = 1+go( x+1, y );
		int v3 = 1+go( x, y+1 );
		best = min( best, min(v1, min(v2,v3) ) );
	}
	else{
		int v1 = 1+go( x, y+1 );
		int v2 = 1+go( x+1, y );
		best = min( best, min(v1,v2)  );
	}
	
return best;	
}

Int cango(int x, int y, int len){
	if( x==l1 && y==l2 ){
		return ( len==0 ? (Int)1 : (Int)0 ) ;
	}
	
	Int& ways = cando[x][y][len];
	if( ways!=-1 ){
		return ways;
	}
	
	ways=0;
	if( x==l1 && y!=l2 ){
		if( len > 0 ){
			Int v = cango(x, y+1, len-1 );
			ways+=v;
		}
	}
	else if( x!=l1 && y==l2 ){
		if( len > 0 ){
			Int v = cango(x+1, y, len-1 );
			ways+=v;
		}
	}
	else if( s1[x] == s2[y] ){
		if( len > 0 ){
			Int v1 = cango(x+1,y+1,len-1);
			//Int v2 = cango(x+1, y, len-1);
			//Int v3 = cango(x, y+1, len-1);
			ways+= v1;
			//ways+= (v1+v2+v3);
		}
	}
	else{
		if( len > 0 ){
			Int v1 = cango(x, y+1, len-1 );
			Int v2 = cango(x+1, y, len-1 );
			ways+= (v1+v2);
		}
	}
	
return ways;
}

inline void Proc(){
	SET( dp, -1 );
	SET( cando, -1 );
	int var = go( 0, 0 );
	Int res = cango(0,0,var);
	printf("Case %d: %d %lld\n",kase,var,res);
}
int main() {
/*
  #ifndef ONLINE_JUDGE
	freopen("in", "rt", stdin);
  #endif
*/

  int cases = 1;
  for ( CI(cases) ; cases; --cases,++kase) {
	  Read();
	  Proc();
	  
  }
  
  return 0;
} 
