/*
 * Author  : Xerxes
 * Program : E.cxx
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
const int inf = (int)1023456789;
const int MAXN = 105;
int n;
int vi[ MAXN+10 ];
int dp[ MAXN+10 ][ MAXN+10 ] [ MAXN+10 ];
inline void Read(){
    CI(n);
    for(int i=1;i<=n;++i){
        CI(vi[i]);
    }
    vi[0]=-inf;
    vi[n+1] = inf;
}
/*
int go( int  cur , int lo, int hi ){
    if(  cur == n ){
        return 0;
    }
   
    int ret=0;
    // left a place kore
    if( vi[cur] > lo && vi[cur] < hi ){
        int v1 = 1+go( cur+1, vi[cur], hi );
        ret = max( ret, v1 );
    }
    // right a place kore
    if( vi[cur] > lo && vi[cur] < hi ){
        int v2 = 1+go( cur+1, lo, vi[cur] );
        ret = max( ret, v2 );
    }
    // kothao place na kore
    int v3 = go( cur+1, lo, hi );
    ret = max( ret, v3 );
   
return ret;
}
*/
int go( int  cur , int lo, int hi ){
    if(  cur > n ){
        return 0;
    }
   
    int& ret= dp[cur][lo][hi];
    if( ret!=-1 ){
        return ret;
    }
   
    // left a place kore
    if( vi[cur] >= vi[lo] && vi[cur] <= vi[hi] ){
        int v1 = 1+go( cur+1, cur, hi );
        ret = max( ret, v1 );
    }
    // right a place kore
    if( vi[cur] >= vi[lo] && vi[cur] <= vi[hi] ){
        int v2 = 1+go( cur+1, lo, cur );
        ret = max( ret, v2 );
    }
    // kothao place na kore
    int v3 = go( cur+1, lo, hi );
    ret = max( ret, v3 );
   
return ret;
}
inline void Proc(){
    // start with 0, -inf, +inf
    SET(dp,-1);
    int var = go( 1, 0 , n+1 );
    cout<<var<<"\n";
   
}
 
int main() {
    int t;
    CI(t);
    for(int i=1;i<=t;++i){
        Read();
        cout<<"Case "<<i<<": ";
        Proc();
    }
    return 0;
}
 