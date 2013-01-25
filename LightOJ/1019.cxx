/*
 * Author  : Pallab
 * Program : 1019.cxx
 *
 * 2012-02-10 15:07:09
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


const int maxn = 100+5;
int N;
int M;
struct NODE {
    int cango;
    int price;
    NODE(int cango=0,int price=0)
            :cango(cango),price(price) {
        ;
    }
};
vector< NODE > E[ maxn ];
inline void Read() {
    foE(i,1,N) {
        E[i].clear();
    }
    scanf("%d %d",&N,&M);
    int u,v,w;
    foE(i,1,M) {
        scanf("%d %d %d",&u,&v,&w);
        E[u].pb( NODE(v,w) );
        E[v].pb( NODE(u,w) );
    }
}
int D[ maxn];
int F[ maxn ];
const int inf = (int)1023456789;

#define P2 pair<int,int>
inline int dj(int src) {
    SET(F,0);
    fill(D,D+N+1,inf);

    set< P2, less<P2> > pq;
    pq.insert( mk(0,src) );
    D[src]=0;

    while (!pq.empty()) {
        int father = pq.begin()->s;
        pq.erase(pq.begin());
        if ( father==N ) {
            return D[father];
        }

        if ( F[father] )continue;
        fo(i,SZ(E[father]) ) {
            int child = E[father][i].cango;
            int price = E[father][i].price;
            if ( !F[child] && price+D[father] < D[child] ) {
                D[child] = price+D[father];
                pq.insert( mk(D[child],child) );
            }
        }

        F[father]=1;
    }

    return inf;
}
inline void Proc() {
    int RET = dj(1);
    if ( RET<inf ) {
        cout<<RET<<"\n";
    }
    else {
        puts("Impossible");
    }
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




