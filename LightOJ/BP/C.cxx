/*
 * Author  : Pallab
 * Program : C
 *
 * 2012-02-20 23:24:56
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

#define CI( x ) scanf("%d",&x)
#define CL( x ) scanf("%lld",&x)
#define CD( x ) scanf("%lf",&x )
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

const int maxn = (1000+1000)+5;
int n;
int e;
vector< int > g[ maxn ];
inline void Read() {
    CI(n);
    CI(e);
    int u;
    int v;
    fo(i,n) {
        g[i].clear();
    }

    fo(i,e) {
        scanf("%d %d",&u,&v);
        --u;
        --v;
        g[u].pb(n+v);
        g[v].pb(n+u);
    }
}

int used[maxn];
int mt[maxn];
int try_kuhn(int v) {
    if (used[v])return 0;
    used[v]=1;
    fo(i,SZ(g[v])) {
        int to=g[v][i];
        if (mt[to]==-1 || try_kuhn(mt[to])) {
            mt[to]=v;
            return 1;
        }
    }
    return 0;
}

inline int match() {
    SET(mt,-1);
    fo(i,n) {
        SET(used,0);
        try_kuhn(i);
    }
    int d=0;
    fo(i,n+n) {
        if ( mt[i]!=-1 ) {
            ;
        }
        else {
            ++d;
        }
    }
    return d;
}

inline void Proc() {
    cout<<(match()>>1);
    puts("");
}
int main() {
    int tt;
    CI(tt);
    foE(i,1,tt) {
        Read();
        cout<<"Case "<<i<<": ";
        Proc();
    }

}
// kate: indent-mode cstyle; space-indent on; indent-width 0; 





