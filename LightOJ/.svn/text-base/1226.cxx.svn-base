/*
 *      ID : pallab81
 *      PROG : 1226
 *      LANG : C++
 *
 *      2012-06-04 20:55:22
 *      "I have not failed, I have just found 10000 ways that won't work.
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
#define line putchar_unlocked('\n')

template<class T1>
inline void debug(T1 _x) {
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
template< class T1>
inline void debug(T1 _array,int _size) {
    cout<<"[";
    for (int i=0; i<_size; ++i) {
        cout<<' '<<_array[i];
    }
    puts(" ]");
}

#define getchar getchar_unlocked
#define putchar putchar_unlocked

inline void fastRead(int *a) {
    register char c=0;
    while (c<33) c=getchar();
    *a=0;
    while (c>33)
    {
        *a=*a*10+c-'0';
        c=getchar();
    }
}
inline string fastRead() {
    register char c[33];
    gets(c);
    return (string)c;
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
inline void wait( double seconds ) {
    double endtime = clock()+( seconds* CLOCKS_PER_SEC );
    while ( clock() < endtime ) {
        ;
    }
}
int narray;
int array[1005];
inline void Read() {
    fastRead(&narray);
    fo(i,narray) {
        fastRead(&array[i]);
    }
}

namespace ModuleInverse {
struct Triple {
    Int d;
    Int x;
    Int y;
    Triple(Int d, Int x, Int y):
            d(d),x(x),y(y) {
        ;
    }
};
Triple egcd(Int a, Int b) {
    if (!b)return Triple(a,1,0);
    Triple q=egcd(b,a%b);
    return Triple(q.d, q.y, q.x-a/b*q.y);
}
inline Int invmod(Int a, Int n) {
    Triple t=egcd(a,n);
    if (t.d>1)return 0;
    Int r=t.x%n;
    return (r<0?r+n:r);
}
}
namespace FACT {
const Int mod=1000000007LL;
inline Int domod(Int val) {
    while (val<mod)val+=mod;
    return val%mod;
}
Int fact[1000005];
inline void precalculateFact(int upto) {
    fact[0]=1;
    fact[1]=1;
    for (int i=2;i<=upto;++i) {
        fact[i]= domod(fact[i-1]*i);
    }
}
inline Int ncr(Int n, Int r) {
    return  domod( domod(fact[n]* ModuleInverse::invmod(fact[r],mod) )* ModuleInverse::invmod(fact[n-r],mod) );
}
}

using namespace FACT;

inline void Proc() {
}
inline void Solve() {
    Read();
    Int ways=1LL;
    int Gaps=array[0];
    for (int i=1;i<narray;++i) {
        int curGaps = Gaps+1;
        int N = (array[i]-1)+(curGaps-1);
        int R = curGaps-1;
        //cout<<N<<' '<<R<<"\n";
        ways = domod(ways*ncr(N,R));
        Gaps=Gaps+array[i];
    }
    cout<<ways;
    line;
}
int main() {
    precalculateFact(1000000);
    int tt;
    CI(tt);
    foE(i,1,tt) {
        cout<<"Case "<<i<<": ";
        Solve();
    }


    return 0;
}
// kate: indent-mode cstyle; space-indent on; indent-width 0; 
