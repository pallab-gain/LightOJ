/*
 * Author  : Pallab
 * Program : 1406
 *
 * 2012-02-20 16:48:21
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

const int maxn = (int)20000;
int N;
int e;
vector< int > E[maxn];
inline void Read() {
    fo(i,maxn) {
        E[i].clear();
    }
    scanf("%d %d",&N,&e);
    int u,v;
    fo(i,e) {
        scanf("%d %d",&u,&v);
        --u;
        --v;
        E[u].pb(v);
    }
}


int cnt;
int timer;
int INDEX[maxn];
int LOWLINK[maxn];
int sack[maxn];
int instack[maxn];
int used[maxn];
int ROOT[maxn];
int ID;

inline void mymin(int &a, int &b ) {
    if ( a > b ) {
        a = b;
    }
}

inline void targan(int v ) {
    ++timer;
    INDEX[v]=LOWLINK[v]=timer;
    sack[cnt++]=v;
    used[v]=instack[v]=1;
    fo(i,SZ(E[v])) {
        int w = E[v][i];
        if ( !used[w] ) {
            targan(w);
            mymin(LOWLINK[v],LOWLINK[w]);
        }
        else if ( instack[w] ) {
            mymin( LOWLINK[v],INDEX[w] );
        }
    }
    if ( LOWLINK[v]==INDEX[v] ) {
        int w;
        do {
            w = sack[--cnt];
            instack[w]=0;
            ROOT[w]=ID;
        } while ( w!=v );
        ++ID;
    }
}

inline void SCC() {
    timer=0;
    SET(used,0);
    SET(instack,0);
    cnt=0;
    ID=0;
    fo(i,N) {
        if ( !used[i] ) {
            targan(i);
        }
    }
}
vector< int > g[ maxn ];
int mt[maxn];
int used1[maxn];

int try_kuhn (int v) {
    if (used[v])  return 0;;
    used[v] = 1;
    fo(i,SZ(g[v])) {
        int to = g[v][i];
        if (mt[to] == -1 || try_kuhn (mt[to])) {
            mt[to] = v;
            return 1;
        }
    }
    return 0;
}

inline void Proc() {
    SCC();
    fo(i,ID) {
        g[i].clear();
    }

    fo(u,N) {
        fo(j,SZ(E[u])) {
            int v = E[u][j];
            if ( ROOT[u]!=ROOT[v] ) {
                g[ ROOT[u] ].pb( ROOT[v] );
            }
        }
    }

    SET(mt,-1);
    SET(used1,0);
    for (int i=0; i<ID; ++i) {
        fo(j, SZ(g[i]) ) {
            if (mt[g[i][j]] == -1) {
                mt[g[i][j]] = i;
                used1[i] = 1;
                break;
            }
        }
    }

    for (int i=0; i<ID; ++i) {
        if (used1[i])  continue;
        SET(used,0);
        try_kuhn (i);
    }
    int d=0;
    for (int i=0;i<ID;++i) {
        if ( mt[i]!=-1 ) {
            ++d;
        }
    }
    cout<<ID-d;
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
