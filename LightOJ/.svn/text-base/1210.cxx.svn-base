/*
 * Author  : Pallab
 * Program : 1210
 *
 * 2012-01-24 15:33:38
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
#include <deque>
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

const int MAXN = 20000+1;
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
        --u;
        --v;
        g[u].pb(v);
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

void tarjan(int v) {
    ++timer;
    INDEX[v]=LOWLINK[v]=timer;
    sack[cnt++]=v;
    instack[v]=1;
    fo(i,SZ(g[v])) {
        int w = g[v][i];
        if ( INDEX[w]==0 ) {
            tarjan(w);
            LOWLINK[v]=min(LOWLINK[v],LOWLINK[w]);
        }
        else if ( instack[w] ) {
            LOWLINK[v]=min(LOWLINK[v],INDEX[w]);
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
    instack=0;
    cnt=0;
    SET(INDEX,0);
    ID=0;
    fo(v,N) {
        if (INDEX[v]==0 ) {
            tarjan(v);
        }
    }

}
int IN[MAXN];
int OUT[MAXN];
bitset< MAXN > used;
int root;

void dfs(int u) {
    used[u]=1;
    fo(i,SZ(g[u])) {
        int v = g[u][i];
        if ( ROOT[v]!=root ) {
            OUT[ root ]++;
            IN[ ROOT[v] ]++;
        }
        if ( !used[v] && root==ROOT[v] )
            dfs(v);
    }

}
void solve() {
    used=0;
    SET(IN,0);
    SET(OUT,0);
    fo(u,N) {
        if (!used[u]) {
            root = ROOT[u];
            dfs(u);
        }
    }
    int a,b;
    a=b=0;
    if (ID>1) {
        fo(i,ID) {
            if (!IN[ i ])++a;
            if (!OUT[ i ])++b;
        }
        cout<< ( a > b ? a : b ) <<"\n";
    }
    else {
        cout<<"0\n";
    }

}
inline void Proc() {
    SCC();
    solve();
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


