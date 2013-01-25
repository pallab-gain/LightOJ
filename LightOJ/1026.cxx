/*
 * Author  : Pallab
 * Program : 1026
 *
 * 2012-01-20 10:26:51
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

inline void wait(double seconds) {
    double endtime = clock()+(seconds * CLOCKS_PER_SEC);
    while (clock() < endtime) {
        ;
    }
}
const int MAXN = 10000;
int N; // number of nodes

vector< vector<int> > g;
bool used[ MAXN+2 ];
int timer, tin[ MAXN+2], fup[ MAXN+2 ];
struct NODE {
    int u;
    int v;
    NODE( int u=0,int v=0 )
            : u(u),v(v) {
        ;
    }
};
inline bool cmp( NODE A, NODE B ) {
    if ( A.u != B.u )
        return A.u < B.u;
    return A.v < B.v;
}
NODE cutpoints[ MAXN+2 ];
int cnt;

inline void Read() {
    CI(N);
    g.assign( N,vector<int>() );
    int u,v,e;
    fo(i,N) {
        scanf("%d (%d)",&u,&e);
        fo(i,e) {
            CI(v);
            g[ u ].pb( v );
            g[ v ].pb( u );
        }
    }
}

void dfs(  int v, int p=-1 ) {
    used[ v ] = true;
    tin [ v ] = fup [ v ] = timer++;

    fo(i,SZ(g[v])) {
        int to = g[v][i];
        if ( to==p )continue;
        if ( used[to] ) {
            fup[ v ] = min( fup[v], tin[to] );
        }
        else {
            dfs(to,v);
            fup[v] = min( fup[v],fup[to] );
            if ( fup[to] > tin[v] ) {
                int a = v;
                int b = to;
                if ( a > b )swap(a,b);

                cutpoints[ cnt++ ] = NODE( a,b );
            }
        }
    }
}

inline void Proc() {
    cnt=timer = 0;
    SET(used,0);
    for (int i=0;i<N;++i) {
        if ( !used[i] ) {
            dfs(i);
        }
    }
    sort( cutpoints, cutpoints+cnt , cmp);
    cout<<cnt<<" critical links\n";
    fo(i,cnt) {
        cout<<cutpoints[i].u<<" - "<<cutpoints[i].v<<"\n";
    }
}
int main() {
    int kase;
    CI(kase);
    foE(i,1,kase) {
        Read();
        cout<<"Case "<<i<<":\n";
        Proc();
    }

    return 0;
}
// kate: indent-mode cstyle; space-indent on; indent-width 0; 
