/*
 * Author  : Pallab
 * Program : 1064
 *
 * 2012-03-10 13:54:07
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
#include <deque>
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


#define foR(i1,st,ed) for(int i1 = st , j1 = ed ; i1 < j1 ; ++i1 )
#define fo(i1,ed) foR( i1 , 0 , ed )
#define foE(i1,st,ed) foR( i1, st, ed+1 )
#define foit(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define bip system("pause")
#define Int long long
#define pb push_back
#define SZ(X) (int)(X).size()
#define LN(X) (int)(X).length()
#define mk make_pair
#define SET( ARRAY , VALUE ) memset( ARRAY , VALUE , sizeof(ARRAY) )
#define line puts("")
template<class T>
inline void debug(T _x) {
    cout<<_x<<'\n';
}
template<class T1, class T2>
inline void debug(T1 _x,T2 _y) {
    cout<<_x<<' '<<_y<<'\n';
}
template<class T1, class T2, class T3>
inline void debug(T1 _x,T2 _y,T3 _z) {
    cout<<_x<<' '<<_y<<' '<<_z<<'\n';
}
template<class T1, class T2, class T3, class T4>
inline void debug(T1 _x,T2 _y,T3 _z,T4 _zz) {
    cout<<_x<<' '<<_y<<' '<<_z<<' '<<_zz<<'\n';
}
inline bool CI(int &_x) {
    return scanf("%d",&_x)==1;
}
inline bool CI(int &_x, int &_y) {
    return CI(_x)&&CI(_y) ;
}
inline bool CI(int &_x, int &_y, int &_z) {
    return CI(_x)&&CI(_y)&&CI(_z) ;
}
inline bool CI(int &_x, int &_y, int &_z, int &_zz) {
    return CI(_x)&&CI(_y)&&CI(_z)&&CI(_zz) ;
}
template< class T >
inline T gcd(T a, T b) {
    // NEGATIVE VALUE'R GCD HOTE PARBE NA
    assert( (a >=0 && b>=0 ) );
    while ( b > T(0) ) {
        a%=b;
        swap(a,b);
    }
    return a;
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
int n,x;
inline void Read() {
    CI(n,x);
}
Int dp[25][150];
Int go(int at,int sum) {
    if (at==n) {
        return (sum>=x ?1LL:0LL);
    }
    Int& nways=dp[at][sum];
    if (nways!=-1)return nways;

    nways=0;
    for (int i=1;i<=6;++i) {
        Int a=go(at+1,sum+i);
        nways+=a;

    }
    return nways;
}
inline void Proc() {
    SET(dp,-1);
    Int a=go(0,0);
    Int b=fastPow(6LL,(Int)n);
    if (a==0)cout<<0;
    else {
        Int gc=gcd(a,b);
        a/=gc;
        b/=gc;
        if (a==b)cout<<a;
        else {
            cout<<a<<'/'<<b;
        }
    }
    line;
}
int main() {
    int tt;
    CI(tt);
    foE(i,1,tt) {
        Read();
        cout<<"Case "<<i<<": ";
        Proc();
    }
    return 0;
}
