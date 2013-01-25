const int N= MXN;
const int LOG_N = 21;
class LCA {
    vector< pair<int,int> >adj[MXN];
    int parent[LOG_N+1][N];
    int min_dist[LOG_N+1][N];
    int max_dist[LOG_N+1][N];
    int depth[N],start[N],end[N];
    int U;
    public:
    LCA() {
        ;
    }
    inline void initGraph ( const int );
    inline void addEdge ( int, int , int );
    inline void initLCA_TABLE();
    void dfs ( int , int , int , int );
    inline void genLCA();
    inline int getLCA ( int , int );
    inline int getMinDist ( int , int );
    inline int getMaxDist ( int , int );
};
inline void LCA::initGraph ( const int upto ) {
    U=1;
    for ( int i=0; i<upto; ++i )
        adj[i].clear();
}
inline void LCA::addEdge ( int u, int v, int w ) {
    adj[u].push_back ( make_pair ( v,w ) );
    adj[v].push_back ( make_pair ( u,w ) );
}
inline void LCA::initLCA_TABLE() {
    for ( int i = 0; i < LOG_N; ++i ) {
        for ( int j = 0; j < N; ++j ) {
            parent[i][j]=-1;
            min_dist[i][j]=+1023456789;
            max_dist[i][j]=-1023456789;
        }
    }
}
void LCA::dfs ( int pos, int prv, int dep, int c ) {
    depth[pos] = dep;
    parent[0][pos] = prv;
    min_dist[0][pos]=max_dist[0][pos]=c;
    start[pos] = U++;
    foit ( it,adj[pos] ) {
        int nxt_pos = ( it->first );
        if ( nxt_pos != prv ) {
            dfs ( nxt_pos, pos, dep + 1, it->second );
        }
    }
    end[pos] = U++;
}
inline void LCA::genLCA() {
    for ( int i = 1; i <= LOG_N; ++i ) {
        for ( int j = 0; j < N; ++j ) {
            if ( parent[i - 1][j] != -1 ) {
                parent[i][j] = parent[i - 1][parent[i - 1][j]];
                min_dist[i][j]=min ( min_dist[i-1][j], min_dist[i-1][ parent[i-1][j] ] );
                max_dist[i][j]=max ( max_dist[i-1][j], max_dist[i-1][ parent[i-1][j] ] );
            }
        }
    }
}
inline int LCA::getLCA ( int x, int y ) {
    if ( depth[x] < depth[y] )
        swap ( x, y );
    for ( int i = LOG_N; i >= 0; --i ) {
        if ( ( depth[x] - depth[y] ) >> i & 1 ) {
            x = parent[i][x];
        }
    }
    if ( x == y )
        return x;
    for ( int i = LOG_N; i >= 0; --i ) {
        if ( parent[i][x] != parent[i][y] ) {
            x = parent[i][x],y=parent[i][y];
        }
    }
    return parent[0][x];
}
inline int LCA::getMinDist ( int x, int y ) {
    if ( depth[x] < depth[y] )
        swap ( x, y );
    int retval=1023456789;
    for ( int i = LOG_N; i >= 0; --i ) {
        if ( ( depth[x] - depth[y] ) >> i & 1 ) {
            retval=min ( retval, min_dist[i][x] );
            x = parent[i][x];
        }
    }
    return retval;
}
inline int LCA::getMaxDist ( int x, int y ) {
    if ( depth[x] < depth[y] )
        swap ( x, y );

    int retval=-1023456789;
    for ( int i = LOG_N; i >= 0; --i ) {
        if ( ( depth[x] - depth[y] ) >> i & 1 ) {
            retval=max ( retval, max_dist[i][x] );
            x = parent[i][x];
        }
    }
    return retval;
}

// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 

