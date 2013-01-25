/*
 * Author  : Pallab
 * Program : 1168.cxx
 *
 * 2012-01-25 22:26:24
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
#define f first
#define s second
#define SET( ARRAY , VALUE ) memset( ARRAY , VALUE , sizeof(ARRAY) )

const int MAXN = 1000;
int nchild;
int nwish;
vector< int > g[ MAXN ];
bitset< MAXN > used;
int nodes[MAXN];
int nnodes;

inline void Read() {
    fo(i,MAXN) {
        g[i].clear();
    }

    used=0;
    nnodes=0;

    int u,v;
    CI(nchild);
    fo(i,nchild) {
        CI(nwish);
        fo(j,nwish) {
            CI(u);
            CI(v);
            g[u].pb(v);
            if ( !used[u] ) {
                used[u]=1;
                nodes[nnodes++]=u;
            }
            if ( !used[v] ) {
                used[v]=1;
                nodes[nnodes++]=v;
            }

        }
    }

}
int ID;
int ROOT[MAXN];

int INDEX[MAXN];
int LOWLINK[MAXN];
bitset< MAXN > instack;
int sack[MAXN];
int cnt;
int timer;

inline void mymin(int &a, int &b ) {
    if ( a > b )
        a = b;
}
void tarjan(int v) {
    ++timer;
    INDEX[v]=LOWLINK[v]=timer;
    sack[cnt++]=v;
    used[v]=instack[v]=1;
    fo(i,SZ(g[v])) {
        int w = g[v][i];
        if ( !used[w] ) {
            tarjan(w);
            mymin(LOWLINK[v],LOWLINK[w]);
        }
        else if ( instack[w] ) {
            mymin(LOWLINK[v],INDEX[w]);
        }
    }
    if ( LOWLINK[v]==INDEX[v] ) {
        int w ;
        do {
            w = sack[--cnt];
            instack[w]=0;
            ROOT[w]=ID;
        } while (w!=v);
        ++ID;
    }
}

inline void SCC() {
    timer=0;
    used = instack=0;
    cnt=0;
    ID=0;
    fo(v,nnodes) {
        if ( !used[ nodes[v] ] ) {
            tarjan( nodes[v] );
        }
    }

}
int IN[MAXN];
int OUT[MAXN];

bool solve() {
    SET(IN,0);
    SET(OUT,0);

    // calculates number of in degreee and out degree
    fo(i,nnodes) {
        int u = nodes[i];
        fo(j,SZ(g[u])) {
            int v = g[u][j];
            if ( ROOT[u]!=ROOT[v] ) {
                ++OUT[ ROOT[u] ];
                ++IN[ ROOT[v] ];
            }
        }
    }
    if ( ID<=1 ) {
        return true;
    }
    int source = ROOT[0];
    if ( (IN[source]!=0 || OUT[source]!=1) ) {
        return false;
    }

    int sink=0;

    for (int i=0;i<ID; ++i ) {
        if ( i==source )continue;
        if ( IN[i]==1 && OUT[i]==0 ) {
            ++sink;
            if ( sink>1 )return false;
        }
        else {
            if ( IN[i]==1 && OUT[i]==1 )continue;
            return false;
        }
    }
    return true;
}
inline void Proc() {
    if ( !used[0] ) {
        cout<<"NO\n";
    }
    else {
        SCC();
        cout<< ( solve() ? "YES\n" : "NO\n"  );
    }
}
int main() {
    int t;
    CI(t);
    foE(i,1,t) {
        Read();
        cout<<"Case "<<i<<": ";
        Proc();
    }

    return 0;
}

// kate: indent-mode cstyle; space-indent on; indent-width 0; 






