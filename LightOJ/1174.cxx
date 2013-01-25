/*
 * Author  : Pallab
 * Program : 1174
 *
 * 2012-02-10 17:12:05
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

const int maxn = 100 + 5;
vector< int > E[ maxn ];
int N;
int M;
int source,sink;
inline void Read() {
    fo(i,maxn) {
        E[i].clear();
    }
    CI(N);
    CI(M);
    int u,v;
    fo(i,M) {
        CI(u);
        CI(v);
        E[u].pb(v);
        E[v].pb(u);
    }
    CI(source);
    CI(sink);
}
int D[maxn];
int F[maxn];
const int inf = (int)1023456789;
#define SP2 pair<int,int>
set< SP2, less<SP2> > pq;
inline void dj(int src) {
    pq.clear();
    SET(F,0);
    fo(i,N) {
        D[i]=inf;
    }
    pq.insert( mk(0,src) );
    D[ src ]=0;

    while ( !pq.empty() ) {
        int father = pq.begin()->s;
        pq.erase( pq.begin() );

        if ( F[father] )continue;
        fo(i,SZ(E[father]) ) {
            int child = E[father][i];
            int cost = D[father]+1;

            if ( F[child]==0 && cost < D[child] ) {
                pq.insert(mk(cost,child));
                D[child]=cost;
            }
        }

        F[father]=1;
    }
}
int D1[maxn];
int D2[maxn];
inline void _Update1() {
    fo(i,N) {
        D1[i]= D[i];
    }
}
inline void _Update2() {
    fo(i,N) {
        D2[i]= D[i];
    }
}
inline void solve() {
    int res = -inf;
    fo(i,N) {
        int d = D1[i] + D2[i];
        res = max( res, d );
    }
    cout<<res;
}
inline void Proc() {
    // source to all nodes

    dj(source);
    _Update1();
    dj(sink);
    _Update2();
    solve();

}
int main() {
    int tt;
    CI(tt);
    foE(i,1,tt) {
        Read();
        cout<<"Case "<<i<<": ";
        Proc();
        puts("");
    }
    return 0;
}
// kate: indent-mode cstyle; space-indent on; indent-width 0; 
