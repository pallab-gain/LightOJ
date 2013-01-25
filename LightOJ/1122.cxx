/*
 * Author  : Pallab
 * Program : 1122
 *
 * 2011-12-20 14:40:31
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
int N;
int K;
int msk;
inline int OR(int msk, int bit) {
    return msk|(1<<bit);
}
inline int AND(int msk, int bit) {
    return msk&(1<<bit);
}
inline void Read() {
    scanf("%d %d",&N,&K);
    int x;
    msk = 0;
    fo(i,N) {
        CI(x);
        msk = OR(msk,x);
    }
}
Int dp[11][10];

Int go(int k,int pre) {
    Int& total= dp[k][pre];
    if (total!=-1 ) {
        return total;
    }
    if ( k==0 ) {
        total=1LL;
        return total;
    }

    total=0LL;
    for (int i=1;i<=9;++i) {
        if ( AND(msk,i)!=0 ) {
            if ( pre==0 || ( abs(pre-i)<=2 ) ) {
                Int a = go(k-1,i);
                total+=a;
            }
        }
    }
    return total;
}
inline void Proc() {
    SET(dp,-1);
    Int retval = go(K,0);
    cout<<retval<<"\n";
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
