/*
*	ID : pallab81
* 	PROG : 1406_2
* 	LANG : C++
* 	2012-09-12-11.35.23 Wednesday
*
* 	"I have not failed, I have just found 10000 ways that won't work.
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
#define line puts("")

template<class T1>
inline void debug(T1 _x) {
    cout<<_x<<'\n';
}
template<class T1, class T2>
inline void debug(T1 _x,T2 _y) {
    cout<<_x<<' '<<_y<<'\n';
}
template<class T1, class T2, class T3>
inline void debug(T1 _x,T2 _y,T3 _z) {
    cout<<_x<<' '<<_y<<' '<<_z<<'\n';
}
template<class T1, class T2, class T3, class T4>
inline void debug(T1 _x,T2 _y,T3 _z,T4 _zz) {
    cout<<_x<<' '<<_y<<' '<<_z<<' '<<_zz<<'\n';
}
template< class T1>
inline void debug(T1 _array,int _size) {
    cout<<"[";
    for (int i=0; i<_size; ++i) {
        cout<<' '<<_array[i];
    }
    puts(" ]");
}
inline bool CI(int &_x) {
    return scanf("%d",&_x)==1;
}
inline bool CI(int &_x, int &_y) {
    return CI(_x)&&CI(_y) ;
}
inline bool CI(int &_x, int &_y, int &_z) {
    return CI(_x)&&CI(_y)&&CI(_z) ;
}
inline bool CI(int &_x, int &_y, int &_z, int &_zz) {
    return CI(_x)&&CI(_y)&&CI(_z)&&CI(_zz) ;
}
inline void wait( double seconds ) {
    double endtime = clock()+( seconds* CLOCKS_PER_SEC );
    while( clock() < endtime ) {
        ;
    }
}
#if !defined( ONLINE_JUDGE )
#define debug
#endif
const int mxn=15;
vector<int> adj[mxn];
int node_count;
int edges_count;

inline void init() {
    fo(i,mxn)adj[i].clear();
}
inline void read() {
    int u,v;
    init();
    CI(node_count, edges_count);
    fo(i,edges_count) {
        CI(u,v);
        --u;
        --v;
        adj[u].pb(v);
    }
}
int vis[mxn][1<<15];
int marked[1<<15];
void dfs(int u,int msk) {
    if( vis[u][msk] )return ;
    vis[u][msk]=true;
    if( !marked[msk])marked[msk]=true;
    foit(it,adj[u]) {
        int v= (*it);
        dfs(v, msk|(1<<v) );
    }
}
inline void make_graph() {
    SET(vis,false);
    SET(marked,false);
    fo(i,node_count)
    dfs(i,1<<i);
}
const int inf=1023456789;
bool memo[1<<15];
int dp[1<<15];
int go(int msk) {
    if(msk==0)return 0;
    if( !memo[msk]) {
        memo[msk]=true;
        int bst=inf;
        for(int _msk=msk; _msk>0; --_msk){
            _msk&=msk;
            if( marked[ _msk ]){
                int v = go(msk^_msk)+1;
                if(v<bst)bst=v;
            }
        }
        return dp[msk]=bst;
    }
    return dp[msk];
}
inline void proc() {
    make_graph();
    SET(memo,false);
    int ret=go( (1<<node_count)-1 );
    cout<<ret;
    line;
}
int main() {
    int kase=1;
#if !defined ( ONLINE_JUDGE )
    freopen("in","r",stdin);
    kase=1;
#endif
    scanf("%d",&kase);
    foE(i,1,kase) {
        read();
        cout<<"Case "<<i<<": ";
        proc();
    }
    return 0;
}


