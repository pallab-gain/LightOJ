
const int N=30005;
const int LOG_N=17;
class LCA {
    private:
    int parent[LOG_N+1][N];
    int depth[N];
    int start[N];
    int end[N];
    int dist[N];
    int U;
    public:
    LCA() {
        ;
    }
    inline void initLCA_TABLE();
    inline void dfs ( int , int , int , int );
    inline void genLCA();
    inline int getLCA ( int , int );
    inline int getLimit() {
        return U;
    }
    inline int getStart ( int at ) {
        return start[at];
    }
    inline int getEnd ( int at ) {
        return end[at];
    }
    inline int getValue ( int at ) {
        return dist[at];
    }
    inline int setValue ( int at,int value ) {
        dist[at]=value;
    }
    inline int printInterval ( int );
};
inline void LCA::initLCA_TABLE() {
    U=1;
    foR ( i,0,LOG_N ) {
        foR ( j,0,N ) {
            parent[i][j]=-1;
        }
    }
}
inline void LCA::dfs ( int pos, int par, int dep, int c ) {
    depth[pos]=dep;
    start[pos]=U++;
    parent[0][pos]=par;
    dist[pos]=c;
    foR ( i,0,SZ ( adj[pos] ) ) {
        int nxt_pos=adj[pos][i];
        if ( nxt_pos!=par ) {
            dfs ( nxt_pos,pos,dep+1, value[nxt_pos] );
        }
    }

    end[pos]=U++;
}
inline void LCA::genLCA() {
    for ( int i = 1; i <= LOG_N; ++i ) {
        for ( int j = 0; j < N; ++j ) {
            if ( parent[i - 1][j] != -1 ) {
                parent[i][j] = parent[i - 1][parent[i - 1][j]];
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
        if ( parent[i][x] != parent[i][y] )
            x = parent[i][x],y=parent[i][y];
    }
    return parent[0][x];
}
inline int LCA::printInterval ( int at ) {
    cout<<"[ "<<start[at]<<" "<<end[at]<<" value = "<<dist[at]<<" ]\n";
}


// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
