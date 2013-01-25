/*
 * Author  : Pallab
 * Program : 1140.cxx
 *
 * 2011-12-20 15:43:38
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
Int lo;
Int hi;
int num[15];
int sz;
Int dp[15][2][2];

inline void Read() {
    scanf("%lld %lld",&lo,&hi);
}
inline void fun(Int var) {
    sz=0;
    while ( var > 0 ) {
        num[sz]=( var%10 );
        var/=10;
        ++sz;
    }
    reverse(num,num+sz);
    return ;
}
inline Int POW(int nn) {
    Int res=1;
    while (nn--) {
        res*=10;
    }
    return res;
}
inline Int calc(int indi, int state) {
    Int total=0;
    if ( state==1 ) {
        total= POW(sz-indi);
    }
    else {
        for (int i=indi;i<sz;++i) {
            total = total*10 + num[i];
        }
        total+=1;
    }
    return total;
}
Int go(int curIndx,int smaller, int flag) {
    if ( curIndx==sz ) {
        return 0;
    }
    Int& total=dp[curIndx][smaller][flag];
    if ( total!=-1 )return total;

    total = 0LL;
    int maxDigit = smaller==0 ? num[curIndx] : 9;
    for (int d=0;d<=maxDigit;++d) {
        int nxtSmaller = smaller|( d < num[curIndx] ? 1 : 0 );
        int nxtFlag = flag|(d!=0 ? 1 : 0);
        Int a = ( flag && d==0 ? calc(curIndx+1,nxtSmaller) : 0 )+ go(curIndx+1,nxtSmaller,nxtFlag);
        total+=a;
    }
    return total;
}
inline Int doit(Int var) {
    if ( var < 0 )return 0LL;

    SET(dp,-1);
    fun(var);
    Int retval = go( 0,0,0 );
    return retval+1;
}
inline void Proc() {
    Int B = doit( hi );
    Int A = doit( lo-1 );
    cout<<B-A<<"\n";
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
