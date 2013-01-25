/*
 * Author  : Pallab
 * Program : 1099
 *
 * 2012-02-10 20:18:31
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

const int maxn = 5000;
vector< pair<int,int> > E[ maxn+5 ];

int N,R;

inline void Read() {
    foE(i,1,maxn) {
        E[i].clear();
    }
    scanf("%d %d",&N,&R);
    int u,v,w;
    fo(i,R) {
        scanf("%d %d %d",&u,&v,&w);
        E[u].pb( mk(v,w) );
        E[v].pb( mk(u,w) );
    }
}


// 1 source
// N destination

const int inf = (int)1023456789;
int F[maxn+5];

#define P2 pair<int, int >

inline int dj(int src, int snk) {
    //clear
    SET(F,0);
    set< P2 , less< P2 > >Q;
    Q.insert( mk(0,src) );

    while ( !Q.empty() ) {
        int ccost = Q.begin()->f;
        int father = Q.begin()->s ;

        Q.erase(Q.begin());
        F[father]++;

        if ( F[father] > 2 ) {
            continue;
        }
        if ( F[father]==2 && father==snk ) {
            return ccost;
        }

        foit( it, E[father] ) {
            int child = it->f;
            int ncost = it->s + ccost;
            Q.insert( mk(ncost,child) );
        }
    }
    return -1;
}
inline void Proc() {
    cout<<dj(1,N);
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


