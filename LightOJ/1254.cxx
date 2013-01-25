/*
 * Author  : Pallab
 * Program : 1254
 *
 * 2012-02-11 20:17:54
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

// IO start
inline bool CI(int &x) {
    return (scanf("%d",&x)==1) ;
}
inline bool CI(int &x, int &y) {
    return ( CI(x) && CI(y) ) ;
}
inline bool CI(int &x, int &y, int &z) {
    return ( CI(x) && CI(y) && CI(z) );
}
// IO ends

const int maxn = 100;
int N,M;
int fp[maxn];
struct NODE {
    int v;
    int d;
    NODE(int v=0,int d=0):
            v(v),d(d) {
        ;
    }
};
vector< NODE > E[ maxn ];
inline void Read() {
    CI(N,M);
    SET(fp,0);
    fo(i,N) {
        CI(fp[i]);
        E[i].clear();
    }

    int u,v,w;
    fo(i,M) {
        CI(u,v,w);
        E[u].pb( NODE(v,w) );
        E[v].pb( NODE(u,w) );
    }
}
const int maxncap = 100;
int D[maxn][ maxncap+1 ];
int F[maxn][ maxncap+1 ];
struct DNODE {
    int cost;
    int fuel;
    int u;
    DNODE(int cost=0, int fuel=0,int u=0)
            : cost(cost),fuel(fuel),u(u) {
        ;
    }
    inline bool operator <(const DNODE &r)const {
        return cost < r.cost;
    }
};

const int inf = (int)1023456789;
inline int dijkstra(int src,int snk, int cap) {
    priority_queue< DNODE > pq;
    SET(F,0);
    fo(i,N) {
        fill(D[i],D[i]+cap+1,inf);
    }
    // fuel up
    foE(i,0,cap) {
        D[src][i] = fp[src]*i;
        pq.push( DNODE(-D[src][i], i,src ) );
    }

    while ( !pq.empty() ) {
        int _fuel = pq.top().fuel;
        int _father = pq.top().u;
        pq.pop( );
        if ( _father==snk )return D[_father][_fuel];

        if ( F[_father][_fuel] )continue;


        fo(i,SZ(E[_father])) {
            int child = E[_father][i].v;
            int _dist = E[_father][i].d;

            // can I come here ?
            if ( _fuel >= _dist ) {
                int __fuel = _fuel-_dist;
                //fuel up
                for (int i=__fuel,k=0; i<=cap;++i,++k) {
                    int _nfuel = i;
                    int _ncost = D[ _father ][ _fuel ]+ ( fp[child]*k );

                    if ( F[child][_nfuel]==0 && _ncost < D[ child ][ _nfuel ] ) {
                        D[child][_nfuel]= _ncost;
                        pq.push( DNODE(-_ncost, _nfuel, child) );
                    }
                }
            }
        }
        F[_father][_fuel] =1;
    }
    return inf;
}
inline void solve() {
    int cap,src,snk;
    CI(cap,src,snk);
    int var = dijkstra(src,snk,cap);
    if ( var < inf ) {
        cout<<var;
        puts("");
    }
    else {
        puts("impossible");
    }
}
inline void Proc() {
    int q;
    CI(q);
    while (q--) {
        solve();
    }
}
int main() {
    int tt;
    CI(tt);
    foE(i,1,tt) {
        Read();
        cout<<"Case "<<i<<":\n";
        Proc();
    }
    return 0;
}
// kate: indent-mode cstyle; space-indent on; indent-width 0; 
