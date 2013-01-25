/*
 * Author  : Pallab
 * Program : 1154
 *
 * 2012-02-18 17:23:25
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

struct node {
    int r;
    int c;
    int ni; // number of penguins initially
    int mi; // number of jump it can handle
    node ( int r=0,int c=0,int ni=0, int mi=0 )
            :r ( r ),c ( c ),ni ( ni ),mi ( mi ) {
        ;
    }
};
inline Int dist ( int r1,int c1, int r2, int c2 ) {
    Int R = r1-r2;
    Int C = c1-c2;
    return ( R*R + C*C ) ;
}

int n; // number of penguins
vector< node > vi; // penguins
Int maxd; // maximum distance
inline void Read() {
    node t;
    double td;
    scanf ( "%d %lf",&n,&td );
    maxd = (td*td);
    vi.clear();
    fo ( i,n ) {
        CI ( t.r );
        CI ( t.c );
        CI ( t.ni );
        CI ( t.mi );
        vi.pb ( t );
    }
}


int totalpenguins;
int good[100][100];

inline void _build() {
    totalpenguins=0;
    SET(good,0);
    for ( int i=0;i<n;++i ) {
        totalpenguins+= vi[i].ni;
    }
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            if ( dist( vi[i].r, vi[i].c, vi[j].r, vi[j].c) <= maxd ) {
                good[i][j]=1;
            }
        }
    }
}
const int maxn = (100*2)+10;
int cap[ maxn ][ maxn ];
vector< int > adj[maxn];
const int inf = (int)1023456789;
inline void _build_flownetwork() {
    SET(cap,0);
    fo(i,maxn) {
        adj[i].clear();
    }
    for (int i=0;i<n;++i) {
        for (int j=0;j<n;++j) {
            if (i==j)continue;
            if (good[i][j]==1) {
                cap[i+n][j] = inf;
                adj[i+n].pb(j);
                adj[j].pb(i+n);
            }
        }
    }
    int source= (2*n) +1;
    for (int i=0;i<n;++i) {
        cap[source][i] = vi[i].ni; // number of penguins initially in it
        adj[source].pb(i);
        adj[i].pb(source);
    }
    for (int i=0;i<n;++i) {
        cap[i][i+n] = vi[i].mi; // maximum jump off it can made
        adj[i].pb(i+n);
        adj[i+n].pb(i);
    }
}

int flow[maxn][maxn];
int used[maxn];
int from[maxn];

inline int bfs(int src,int snk) {
    SET(from,-1);
    SET(used,0);
    queue<int>q;

    q.push( src );
    used[src]=1;

    while ( q.empty()==false ) {
        int u = q.front();
        q.pop();

        fo(i,SZ(adj[u])) {
            int v = adj[u][i];
            if ( used[v]==0 && cap[u][v]-flow[u][v]>0 ) {
                from[v]=u;
                used[v]=1;
                q.push(v);
                if ( v==snk )goto L;
            }
        }
    }
L:
    ;
    if (from[snk]==-1)return 0;
    int v=snk;
    int mnc = (int)inf;
    while ( from[v]!=-1 ) {
        int u = from[v];
        mnc = min( mnc, cap[u][v]-flow[u][v]);
        v = u;
    }
    v = snk;
    while ( from[v]!=-1 ) {
        int u = from[v];
        flow[u][v]+=mnc;
        flow[v][u]-=mnc;
        v=u;
    }
    return mnc;
}
inline int maxflow(int src, int snk) {
    int tf=0;
    int pc=0;
    SET(flow,0);
    do {
        pc = bfs(src,snk);
        tf+=pc;
    } while (pc!=0);
    return tf;
}

inline void Proc() {
    _build();
    _build_flownetwork();
    string ss="";
    //puts("");
    for (int i=0;i<n;++i) {
        int canreach = maxflow( (2*n)+1,i);
        if (canreach==totalpenguins) {
            cout<<ss<<i;
            ss=" ";
        }
    }
    if ( ss!=" " ) {
        cout<<-1;
    }
    puts("");
}
int main() {
    int tt;
    CI ( tt );
    foE ( i,1,tt ) {
        Read();
        cout<<"Case "<<i<<": ";
        Proc();
    }

}
// kate: indent-mode cstyle; space-indent on; indent-width 0; 

