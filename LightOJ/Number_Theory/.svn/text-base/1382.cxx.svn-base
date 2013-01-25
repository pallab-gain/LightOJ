/*
 *      ID : pallab81
 *      PROG : 1382
 *      LANG : C++
 *
 *      2012-06-08 12:52:53
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
const int maxn = 1005;

namespace READ {
int n;//number of nodes;
int e;
vector<int> E[maxn];
bool isRoot[maxn];
inline void INI(int upto) {
    foE(i,0,upto) {
        E[i].clear();
    }
    SET(isRoot,true);
}
inline void Read() {
    fastRead(&n);
    e=n-1;
    INI(n);
    int u,v;
    fo(i,e) {
        fastRead(&u);
        fastRead(&v);
        --u;
        --v;
        E[u].pb(v);
        isRoot[v]=false;
    }
}
}

namespace COUNT {
int childs[maxn];
int dfs(int u) {
    childs[u]=1;
    foit(it,READ::E[u]) {
        childs[u]+=dfs((*it));
    }
    return childs[u];
}
inline void countChilds() {
    SET(childs,0);
    fo(i,READ::n) {
        if ( READ::isRoot[i]==true ) {
            dfs(i);
        }
    }
}
}
const Int mod = 1000000007;
namespace algo {
Int fact[maxn];
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
inline Int domod(Int var) {
    while (var<mod)var+=mod;
    return var%mod;
}
inline void findFactorials(int upto) {
    fact[0]=fact[1]=1;
    for (int i=2;i<=upto;++i) {
        fact[i]= domod(fact[i-1]*i);
    }
}
inline Int ncr(int n, int r)  {
    return domod( domod(fact[n]*invmod(fact[r],mod))*invmod(fact[n-r],mod) );
}

Int dfs(int node, int remain) {
    Int ret=ncr(remain, COUNT::childs[node]);
    remain = COUNT::childs[node]-1;
    foit(v,READ::E[node]) {
        ret = domod(ret*dfs( *v, remain));
        remain-=COUNT::childs[*v];
    }
    //debug(node+1, remain,ret);
    return ret;
}
}
inline void Solve() {
    READ::Read();
    COUNT::countChilds();

    /*
    fo(i,READ::n) {
        debug("child ",i+1,COUNT::childs[i]);
    }
    line;
    line;
    */
    Int ret=1LL;
    fo(i,READ::n) {
        if (READ::isRoot[i]) {
            ret = algo::domod(ret*algo::dfs(i,READ::n));
        }
    }
    cout<<ret;
    line;
}
#define showcase
int main() {
    algo::findFactorials(1000);
    int tt;
    CI(tt);
    foE(i,1,tt) {
#ifdef showcase
        cout<<"Case "<<i<<": ";
#endif
        Solve();
    }


    return 0;
}
// kate: indent-mode cstyle; space-indent on; indent-width 0; 

