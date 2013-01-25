/*
 * Author  : Pallab
 * Program : 1135
 *
 * 2012-02-08 14:17:24
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



struct MaxFlow {
#define maxn 100
#define inf 1023456789

    int n,source,sink;
    int used[ maxn ];
    int from[ maxn ];
    int cap[ maxn ][ maxn ];
    vector< int > E[ maxn ];


    inline void INI(int _n, int _source, int _sink) {
        n=_n;
        source = _source;
        sink = _sink;
        fo(i,_n) {
            E[i].clear();
        }
        SET(cap,0);
    }
    inline void addedge(int u, int v, int c) {
        E[u].pb(v);
        cap[u][v]+=c;
    }
    inline int bfs() {
        // initialization
        deque<int> q;
        SET(used,0);
        SET(from,-1);
        // ends
        q.push_back(source);
        used[ source ] = 1;

        while ( !q.empty() ) {
            int where = q.front();
            q.pop_front();

            fo(i,SZ(E[where])) {
                int next = E[where][i];
                if ( !used[next] && cap[ where ][ next ]>0 ) {
                    q.push_back(next);
                    used[ next ]= 1;
                    from[ next ]= where;
                    if ( next==sink ) {
                        goto done;
                    }
                }
            }

        }
done:
        ;
        if ( from[ sink ]==-1 ) {
            return 0;
        }
        int cur = sink, pathcap= inf;
        while ( from[ cur ] !=-1 ) {
            int prv = from[cur];
            pathcap = min( pathcap, cap[ prv ][ cur ] );
            cur = prv;
        }

        cur = sink;
        while ( from[ cur ] !=-1 ) {
            int prv = from[ cur ];
            cap[ prv ][ cur ]-=pathcap;
            cap[ cur ][ prv ]+=pathcap;
            cur = prv;
        }

        return pathcap;
    }
    inline int maxflow() {
        int totalflow=0;
        while (1) {
            int pathcap = bfs();
            if ( pathcap==0 ) {
                break;
            }
            totalflow+=pathcap;
        }
        return totalflow;
    }
};


MaxFlow flow;

inline void Read() {
    int n,src,sink,e;
    CI(n);
    CI(src);
    CI(sink);
    CI(e);


    flow.INI(n,src-1,sink-1);
    int u,v,c;
    fo(i,e) {
        CI(u);
        CI(v);
        CI(c);
        --u;
        --v;
        flow.addedge(u,v,c);
        flow.addedge(v,u,c);
    }

}
inline void Proc() {
    int res = flow.maxflow();
    cout<<res;
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
    return 0;
}
// kate: indent-mode cstyle; space-indent on; indent-width 0; 
