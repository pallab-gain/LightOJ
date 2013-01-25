/*
 * Author  : Pallab
 * Program : 1291.cxx
 *
 * 2012-01-20 14:56:28
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
#include <deque>

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

inline void wait(double seconds) {
    double endtime = clock()+(seconds * CLOCKS_PER_SEC);
    while (clock() < endtime) {
        ;
    }
}


const int MAXN = 10000;
int N;
int E;
vector< int > g[ MAXN ];

inline void Read() {
    CI(N);
    CI(E);
    fo(i,N) {
        g[i].clear();
    }

    int u,v;
    fo(i,E) {
        CI(u);
        CI(v);

        g[u].pb(v);
        g[v].pb(u);

    }
}

int timer;
int low[MAXN],pre[MAXN],vis[MAXN],deg[MAXN];

void dfs( int u,int v ) {
    vis[u]=1; //white
    pre[u]= low[u]= timer++;
    fo(i,SZ(g[u])) {
        int w = g[u][i];
        if ( w==v )continue;
        if ( !vis[w] ) {
            dfs( w,u );
        }
        if ( low[w] < low[u] ) {
            low[u]=low[w];
        }
    }
    vis[u]=2; // gray
}
inline void Proc() {
    timer=0;
    SET(vis,0);
    dfs(0,0);

    SET(deg,0);
    fo(u,N) {
        fo(i,SZ(g[u])) {
            int v = g[u][i];
            if ( low[u] != low[v] )
                deg[ low[u] ]++;
        }
    }
    int nleaf=0;
    fo(i,N) {
        //cout<<i<<" "<<deg[i]<<"\n";
        if ( deg[i]==1 )
            ++nleaf;
    }
    int RET = (nleaf>>1)+( nleaf&1 ? 1 : 0);
    cout<< RET <<"\n";

}

int main() {
    int kase;
    CI(kase);
    foE(i,1,kase) {
        Read();
        cout<<"Case "<<i<<": ";
        Proc();
    }

    return 0;
}

// kate: indent-mode cstyle; space-indent on; indent-width 0; 
