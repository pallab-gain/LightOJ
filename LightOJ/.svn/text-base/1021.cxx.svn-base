/*
 * Author  : Pallab
 * Program : 1021.cxx
 *
 * 2011-12-03 15:15:39
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
#define Int unsigned long long
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

int B;
int K;
string num;
int N;
int MSK[ 17 ];
int allend;
Int dp[1<<16][ 20 ];;
inline void pre() {
    for (int i=0;i<17;++i) {
        MSK[ i ] = ( 1<<i );
    }
}
inline void Read() {
    scanf("%d %d",&B,&K);
    cin>>num;
    N = LN( num );
}


inline Int fastPow(Int x, Int y) {
    Int res= (Int)1;
    for ( ; y ; ) {
        if ( (y&1) ) {
            res*= x; 
        }
        x*=x;
        y>>=1;
    }
    return res;
}

inline Int calc(int pos, char digit, int base) {
    int v = digit-'0';
    if ( isupper(digit) ) {
        v-=7;
    }
    Int var = fastPow(base,pos)*( v );
    return var%K;
}
Int go(int pos, int msk, int mod) {
    if ( msk==allend ) {
        if ( mod==0 ) {
            return (Int)1;
        }
        else{
          return 0;
        }
    }
  
    Int& d = dp[msk][mod];
    if( d!=-1 ){
      return d;
    }
    
   d=(Int)0;
    for (int i=0;i<N;++i) {
        if ( (msk&MSK[i]) ==0 ) {
            Int newMod = ( (calc(pos, num[i], B)  )+( mod ) ) % K;
            d+= go(pos+1, (msk|MSK[i] ), newMod );
        }
    }
    return d;
}
inline void Proc() {
    SET(dp,-1);
    allend = (1<<N)-1;
    Int retval = go(0,0,0);
    cout<<retval<<"\n";
}

int main() {
  
    pre();
    int t;
    CI(t);
    
    for (int i=1;i<=t;++i) {
        Read();
        cout<<"Case "<<i<<": ";
        Proc();
    }

    return 0;
}
// kate: indent-mode cstyle; space-indent on; indent-width 0; 
