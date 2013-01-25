/*
 *      ID : pallab81
 *      PROG : D_1295
 *      LANG : C++
 *
 *      2012-06-02 04:40:23
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
struct Node {
    int v;
    int k;
    int c;
    int l;
    Node(int v=0,int k=0,int c=0,int l=0):
            v(v),k(k),c(c),l(l) {
        ;
    }
    inline bool operator< (const Node &r )const {
        return this->v > r.v;
    }
};
Node vi[1005];
int N;
inline void Read() {
    fastRead(&N);
    fo(i,N) {
        fastRead(&vi[i].v);
        fastRead(&vi[i].k);
        fastRead(&vi[i].c);
        fastRead(&vi[i].l);
    }
    sort(vi,vi+N);
}
const Int inf = 1023456789;
Int dp[1001][11];
Int go(int at, int low) {
    if (at==N)return 0;

    Int& ret=dp[at][low];
    if (ret!=-1)return ret;

    ret=inf;
    //lets no buy this voltage source
    Int a= vi[at].l*low + go(at+1,low);
    ret=min(ret,a);
    //lets buy this voltage source
    Int b= vi[at].k+( vi[at].l* min(low,vi[at].c) )+go(at+1, min(low,vi[at].c) );
    ret=min(ret,b);

    return ret;
}
inline void Proc() {
    SET(dp,-1);
    Int var = vi[0].k+( vi[0].l* vi[0].c) + go(1,vi[0].c);
    cout<<var;
    line;
}
inline void Solve() {
    Read();
    Proc();
//     fo(i,N) {
//         debug(vi[i].v,vi[i].k,vi[i].c,vi[i].l);
//     }
}
int main() {
    int tt;
    CI(tt);
    foE(i,1,tt) {
        cout<<"Case "<<i<<": ";
        Solve();
    }


    return 0;
}
// kate: indent-mode cstyle; space-indent on; indent-width 0; 
