/*
 * Author  : Xerxes
 * Program : 1032.cxx
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
int N;
int sz;
int num[32];
inline void Read() {
    CI(N);
}

inline void toBi() {
    sz=0;
    while ( N > 0 ) {
        num[sz]= ( N&1 ? 1 : 0 ) ;
        ++sz;
        N>>=1;
    }
    return ;
}
inline Int calc(int indi, int state) {
    Int total=0;
    if ( state==1 ) {
        total = 1<<indi;
    }
    else {
        for (int i=0;i<indi;++i) {
            if (num[i]==1) {
                total+=(1<<i);
            }
        }
        total+=1;
    }
    return total;
}

Int dp[32][2][2];

Int go(int curIndx, int smaller, int prev) {
    if ( curIndx==-1 ) {
        return 0;
    }

    Int &total= dp[curIndx][smaller][prev];
    if ( total!=-1 )return total;

    total=0LL;
    int maxDigit = ( smaller==0 ? num[curIndx] : 1 ) ;
    for (int d=0;d<=maxDigit;++d) {
        int nxtSmaller = smaller|( d < num[curIndx] ? 1 : 0  );
        if ( d==0 ) {
            Int a = go( curIndx-1, nxtSmaller, 0);
            total+=a;
        }
        else {
            Int b = (prev==1 ? calc(curIndx,nxtSmaller) : 0 ) + go( curIndx-1, nxtSmaller, 1);
            total+=b;
        }
    }
    return total;
}
inline void Proc() {
    toBi();
    SET(dp,-1);
    Int var = go(sz-1,0,0);
    cout<<var<<"\n";
}

int main() {
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
