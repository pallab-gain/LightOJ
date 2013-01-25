/*
 * Author  : Pallab
 * Program : 1156
 *
 * 2012-02-19 14:57:44
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

int N;
int D;
struct node {
    int type;
    int d;
    node(int type=0,int d=0):
            type(type),d(d) {
        ;
    }
};
vector< node > vi;
inline void Read() {
    scanf("%d %d",&N,&D);
    vi.clear();
    char ch1;
    char ch2;
    int d;
    fo(i,N) {
        cin>>ch1>>ch2>>d;
        vi.pb( node( (ch1=='S' ? 0 : 1) , d) );
        //cout<<vi[i].type<<" "<<vi[i].d<<"\n";
    }
}
const int inf = (int)1023456789;
const int maxn = (100*2)+10;
int cap[maxn][maxn];
int flow[maxn][maxn];
vector< int > adj[maxn];
inline void build_flow_network(int dist) {
    SET(cap,0);
    fo(i,maxn) {
        adj[i].clear();
    }

    // split the nodes
    for (int i=0;i<N;++i) {
        cap[i][i+N] = (vi[i].type==1 ? inf : 1 );
        adj[i].pb( i+N );
        adj[i+N].pb(i);
        //cout<<i<<" "<<i+N<<" "<<cap[i][i+N]<<"\n";
    }

    // among the nodes
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) {
            if (i==j)continue;
            if ( abs( vi[i].d-vi[j].d )<=dist ) {
                cap[i+N][j] = inf;
                //cout<<i+N<<" "<<j<<" "<<cap[i+N][j]<<"\n";
                adj[i+N].pb(j);
                adj[j].pb(i+N);
            }
        }
    }

    int source = (N+N)+1;
    int sink = (N+N)+2;

    // take care of source
    for (int i=0;i<N;++i) {
        if ( abs(0-vi[i].d) <= dist ) {
            cap[source][i] = inf;
            cap[i+N][source] = inf;

            //cout<<source<<" "<<i<<" "<<cap[source][i]<<"\n";
            //cout<<i+N<<" "<<source<<" "<<cap[i+N][source]<<"\n";
            adj[source].pb(i);
            adj[i].pb(source);

            adj[i+N].pb(source);
            adj[source].pb(i+N);
        }
    }

    // take care of sink
    for (int i=0;i<N;++i) {
        if ( abs(D-vi[i].d) <= dist ) {
            cap[sink][i] = inf;
            cap[i+N][sink] = inf;

            //cout<<sink<<" "<<i<<" "<<cap[sink][i]<<"\n";
            //cout<<i+N<<" "<<sink<<" "<<cap[i+N][sink]<<"\n";
            adj[sink].pb(i);
            adj[i].pb(sink);

            adj[i+N].pb(sink);
            adj[sink].pb(i+N);
        }
    }
    if ( D<=dist ) {
        cap[source][sink] = inf;
        cap[sink][source] = inf;
        adj[source].pb(sink);
        adj[sink].pb(source);
    }

}
int used[maxn];
int from[maxn];
#define debug cout<<__LINE__<<"\n"
inline int bfs(int src, int snk) {
    SET(used,0);
    SET(from,-1);
    queue< int > q;
    q.push(src);
    used[src]=1;
    //debug;
    while ( q.empty()==false ) {
        int u = q.front();
        q.pop();
        //debug;
        fo(i,SZ(adj[u])) {
            int v = adj[u][i];
            if ( used[v]==0 && cap[u][v]-flow[u][v] >0) {
                used[v]=1;
                from[v]=u;
                q.push(v);
                if (v==snk) {
                    goto L;
                }
            }
        }
    }
L:
    ;
    if (from[snk]==-1)return 0;
    int v=snk;
    int mnc=inf;
    while (from[v]!=-1) {
        int u = from[v];
        mnc = min(mnc, cap[u][v]-flow[u][v]);
        v = u;
    }
    v=snk;
    while (from[v]!=-1) {
        int u=from[v];
        flow[u][v]+=mnc;
        flow[v][u]-=mnc;
        v=u;
    }
    return mnc;
}
inline bool maxflow(int src, int snk) {
    SET(flow,0);
    int tf=0;
    while (1) {
        int cf = bfs(src,snk);
        if (cf==0)break;
        tf+=cf;
        if ( tf >=2 )break;
    }
    return tf>=2;
}
inline void Proc() {
    int source = (N+N)+1;
    int sink = (N+N)+2;

    int lo=0;
    int hi= (int)D;
    int best = hi;
    while ( hi>lo) {
        int mid = (lo+hi)>>1;
        build_flow_network(mid);
        if ( maxflow(source,sink) ) {
            hi=mid;
            best =  min( best, hi );
        }
        else {
            lo=mid+1;
        }
    }
    cout<<best<<"\n";

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
