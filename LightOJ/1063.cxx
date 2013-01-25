/*
 * Author  : Pallab
 * Program : 1063.cxx
 *
 * 2012-01-20 12:19:31
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
int N; // number of nodes;
int E; // number of edges
vector< vector<int> > g;
bool used[ MAXN ];
int timer, tin[ MAXN ], fup [ MAXN];
int hills[MAXN];
int cnt;

void dfs (int v, int p = -1) {
    used[v] = true;
    tin[v] = fup[v] = timer++;
    int children = 0;
    fo(i,SZ(g[v])) {
        int to = g[v][i];
        if (to == p)  continue;
        if (used[to])
            fup[v] = min (fup[v], tin[to]);
        else {
            dfs (to, v);
            fup[v] = min (fup[v], fup[to]);
            if (fup[to] >= tin[v] && p != -1) {
                if ( !hills[v] ) {
                    ++cnt;
                    hills[v]=1;
                }
            }
            ++children;
        }
    }
    if (p == -1 && children > 1) {
        if ( !hills[v] ) {
            ++cnt;
            hills[v]=1;
        }
    }
}

inline void Read() {
    CI( N );
    CI( E );
    g.assign( N, vector<int>() );
    int u,v;
    fo(i,E) {
        CI(u);
        CI(v);
        --u;
        --v;
        g[u].pb( v );
        g[v].pb( u );
    }
}

inline void Proc() {
    cnt=timer=0;
    SET(used,0);
    SET(hills,0);
    dfs(0);
}
int main() {
    int kase;
    CI(kase);
    foE(i,1,kase) {
        Read();
        Proc();
        cout<<"Case "<<i<<": "<<cnt<<"\n";
    }

    return 0;
}
// kate: indent-mode cstyle; space-indent on; indent-width 0; 





