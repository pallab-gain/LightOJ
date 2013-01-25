/*  KDevelop 4.3.1
 *  1101.cxx
 *
 * 	Author : Pallab
 * 	Created on: 9:14:42 PM - 2013:1:10
 * 	"I have not failed, I have just found 10000 ways that won't work."
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
#include <numeric>
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


#define foR(i,frm,upto) for( int i=(frm),_i=(upto);(i) < (_i) ; ++i )
#define foD(i,frm,upto) for( int i=(frm),_i=(upto);(i) >= (_i) ; --i )
#define Int long long
#define pb push_back
#define SZ(X) (int)(X).size()
#define LN(X) (int)(X).length()
#define mk make_pair
#define SET( ARRAY , VALUE ) memset( ARRAY , VALUE , sizeof(ARRAY) )
#define line puts("")

inline void wait ( double seconds ) {
    double endtime = clock() + ( seconds * CLOCKS_PER_SEC );
    while ( clock() < endtime ) {
        ;
    }
}
template<class T>
    inline T fastIn() {
    register char c=0;
    register T a=0;
    bool neg=false;
    while ( c<33 ) c=getchar();
    while ( c>33 ) {
        if ( c=='-' ) {
            neg=true;
        } else {
            a= ( a*10 ) + ( c-'0' );
        }
        c=getchar();
    }
    return neg?-a:a;
}
const int MX=50005;
class DSU {
    private:
    int root[MX];
    int rank[MX];
    public:
    DSU() {
        ;
    }
    inline void Set ( const int upto ) {
        for ( int i=0; i<=upto; ++i ) {
            root[i]=i;
            rank[i]=0;
        }
    }
    inline int Find ( const int x ) {
        if ( x!= root[x] ) {
            root[x] = Find ( root[x] );
        }
        return root[x];
    }
    inline void Marge ( const int x, const int y ) {
        int rx = Find ( x );
        int ry = Find ( y );

        if ( rank[rx] > rank[ry] ) {
            root[ry] = rx;
        } else {
            root[rx] = ry;
        }
        if ( rank[rx]==rank[ry] ) {
            rank[ry]+=1;
        }
    }
};
class Node {
    public:
    int u;
    int v;
    int c;
    Node() {
        u=fastIn<int>()-1,v=fastIn<int>()-1,c=fastIn<int>();
    }
    Node ( int u_,int v_,int c_ ) {
        u=u_,v=v_,c=c_;
    }
    inline bool operator< ( const Node &r ) const {
        return this->c < r.c;
    }
    friend ostream &operator<< ( ostream &output, const Node &r ) {
        output<<"[ "<<r.u<<" "<<r.v<<" "<<r.c<<" ]";
    }
};

DSU dsu;
multiset< Node > edges;
int nodeCount,edgeCount;
inline void read() {
    nodeCount=fastIn<int>(),edgeCount=fastIn<int>();
    edges.clear();

    foR ( i,0,edgeCount ) {
        edges.insert ( Node() );
    }
}
#define N (50005)
#define LOG_N (17)

int depth[N];
bool vis[N];
int parent[LOG_N+1][N];
int dist[LOG_N+1][N];
int U;
vector< pair<int,int> >adj[MX];
inline void initLCATABLE() {
    SET ( vis,false );

    //-----------------------------------------
    for ( int i = 0; i < LOG_N; ++i ) {
        for ( int j = 0; j < N; ++j ) {
            dist[i][j]=0;
            parent[i][j]=-1;
        }
    }
}
void dfs ( int u,int dep ) {
    vis[u]=true;
    depth[u]=dep;
    foR ( i,0,SZ ( adj[u] ) ) {
        int to=adj[u][i].first,cst=adj[u][i].second;
        if ( vis[to]==false ) {
            parent[0][to]=u;
            dist[0][to]=cst;
            dfs ( to,dep+1 );
        }
    }
}
inline void genLCA() {
    for ( int i = 1; i <= LOG_N; ++i ) {
        for ( int j = 0; j < N; ++j ) {
            if ( parent[i - 1][j] != -1 ) {
                parent[i][j] = parent[i - 1][parent[i - 1][j]];
                dist[i][j] = max ( dist[i-1][j], dist[i - 1][parent[i - 1][j]] );
            }
        }
    }
}
inline int getLCA ( int x, int y ) {
    if ( depth[x] < depth[y] )
        swap ( x, y );

    int mxDist=0;
    for ( int i = LOG_N; i >= 0; --i ) {
        if ( ( depth[x] - depth[y] ) >> i & 1 ) {
            mxDist=max ( mxDist, dist[i][x] );
            x = parent[i][x];
        }
    }
    if ( x == y ) {
        return mxDist;
    }
    for ( int i = LOG_N; i >= 0; --i ) {
        if ( parent[i][x] != parent[i][y] ) {
            mxDist=max ( mxDist, max ( dist[i][x],dist[i][y] ) );
            x = parent[i][x],y=parent[i][y];
        }
    }
    mxDist=max ( mxDist, max ( dist[0][x],dist[0][y] ) );

    return mxDist;
}

inline void proc() {
    int u,v,c;
    dsu.Set ( nodeCount );
    foR ( i,0,nodeCount ) adj[i].clear();

    for ( multiset<Node> :: iterator it = edges.begin() ; it != edges.end(); ++it ) {
        u= dsu.Find ( it->u ),v= dsu.Find ( it->v ),c=it->c;
        if ( u != v ) {
            adj[u].pb ( mk ( v,c ) );
            adj[v].pb ( mk ( u,c ) );
            dsu.Marge ( u,v );
        }
    }
    //------------------------------------
    initLCATABLE();
    dfs ( 0,0 );
    genLCA();
    //------------------------------------
    foR ( i,0, fastIn<int>() ) {
        u=fastIn<int>()-1,v=fastIn<int>()-1;
        int result = getLCA ( u,v );
        cout<<result<<"\n";
    }
}
int main() {
    int kase = 1;
#if defined( xerxes_pc )
    freopen ( "in1", "r", stdin );
    kase = 1;
#endif
    kase=fastIn<int>();
    for ( int i=1; i<=kase; ++i ) {
        read();
        cout<<"Case "<<i<<":\n";
        proc();
    }
    return 0;
}

// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 









