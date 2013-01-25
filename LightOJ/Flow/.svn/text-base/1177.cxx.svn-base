/*
 * Author  : Pallab
 * Program : 1177
 *
 * 2012-02-17 19:41:13
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


const int maxn = 50*2+5;
int M,W;
int cap[maxn][ maxn ];
int source;
int sink;

inline void Read() {
    CI(M);
    CI(W);

    source = 1;
    sink = (M);
    SET(cap,0);

    cap[source][source+M]=(int)1023456789;
    cap[sink][sink+M]=(int)1023456789;
    // cap[source+M][source]=(int)1023456789;
    // cap[sink+M][sink]=(int)1023456789;

    int u,v,c;
    foE(i,2,M-1) {
        CI(c);
        cap[i][i+M]+=c;
        cap[i+M][i]+=c;
    }
    foE(i,1,W) {
        CI(u);
        CI(v);
        CI(c);
        cap[u+M][v]+=c;
        cap[v+M][u]+=c;
    }

}
int used[maxn];
int from[maxn];
inline int bfs(int src, int snk) {
    queue< int > Q;
    SET(used,0);
    SET(from,-1);

    used[ src ]=1;
    Q.push( src );

    while ( !Q.empty() ) {
        int where = Q.front();
        Q.pop();
        for (int next=0;next<=snk;++next) {
            if ( cap[ where][ next ]>0 && !used[next] ) {
                used[ next ]=1;
                from[ next ]=where;
                Q.push( next );
                if ( next==snk ) {
                    goto L;
                }
            }
        }

    }
L :
    ;
    if ( from[ snk ]==-1 ) {
        return 0;
    }

    int where = snk, pathcap = (int)1023456789;
    while ( from[ where ] != -1 ) {
        int prev = from[ where ];
        pathcap = min( pathcap, cap[ prev ][ where ] );
        where = prev;
    }
    where = snk;
    while ( from[ where ] != -1 ) {
        int prev = from[ where ];
        cap[ prev ][ where ]-= pathcap;
        cap[ where][ prev  ]+= pathcap;
        where = prev;
    }

    return pathcap;

}
inline int maxflow(int src, int snk) {
    int maxf=0;
    while (true) {
        int path_cap = bfs(src, snk );
        if ( path_cap==0 ) {
            break;
        }
        maxf+=path_cap;
    }
    return maxf;
}

inline void Proc() {
    int res = maxflow(source,sink+M);
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

}
// kate: indent-mode cstyle; space-indent on; indent-width 0; 
