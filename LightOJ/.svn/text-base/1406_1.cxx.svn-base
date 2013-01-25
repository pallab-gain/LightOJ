/*
 * Author  : Pallab
 * Program : 1406
 *
 * 2012-02-20 16:48:21
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
#define SET( ARRAY , VALUE ) memset( ARRAY , VALUE , sizeof(ARRAY) )

inline int OR(int msk,int bit) {
    return ( msk|(1<<bit) );
}
inline int AND(int msk, int bit) {
    return ( msk&(1<<bit) );
}
inline int XOR(int msk, int bit) {
    return ( msk&(~(1<<bit)));
}
inline bool marked(int msk, int bit) {
    return ( AND(msk,bit)!=0 );
}
const int maxn = (int)20000;
int N;
int e;
vector< int > E[maxn];
inline void Read() {
    fo(i,maxn) {
        E[i].clear();
    }
    scanf("%d %d",&N,&e);
    int u,v;
    fo(i,e) {
        scanf("%d %d",&u,&v);
        --u;
        --v;
        E[u].pb(v);
    }
}


int cnt;
int timer;
int INDEX[maxn];
int LOWLINK[maxn];
int sack[maxn];
int instack[maxn];
int used[maxn];
int ROOT[maxn];
int ID;

inline void mymin(int &a, int &b ) {
    if ( a > b ) {
        a = b;
    }
}

inline void targan(int v ) {
    ++timer;
    INDEX[v]=LOWLINK[v]=timer;
    sack[cnt++]=v;
    used[v]=instack[v]=1;
    fo(i,SZ(E[v])) {
        int w = E[v][i];
        if ( !used[w] ) {
            targan(w);
            mymin(LOWLINK[v],LOWLINK[w]);
        }
        else if ( instack[w] ) {
            mymin( LOWLINK[v],INDEX[w] );
        }
    }
    if ( LOWLINK[v]==INDEX[v] ) {
        int w;
        do {
            w = sack[--cnt];
            instack[w]=0;
            ROOT[w]=ID;
        } while ( w!=v );
        ++ID;
    }
}

inline void SCC() {
    timer=0;
    SET(used,0);
    SET(instack,0);
    cnt=0;
    ID=0;
    fo(i,N) {
        if ( !used[i] ) {
            targan(i);
        }
    }
}
vector< int > g[ maxn ];
int dp[1<<16][16];

inline int bc(int msk) {
    return __builtin_popcount(msk);
}
const int inf=(int)1023456789;
int go(int msk, int prv) {
    if (bc(msk)==ID)return 0;

    int& best=dp[msk][prv];
    if (best!=-1)return best;
    best=inf;
    // choose any new index that I have not taken before
    fo(i,ID) {
        if ( !marked(msk,i) ) {
            int a=1+go( OR(msk,i), i);
            best=min(best,a);
        }
    }
    // go where I can go from prv
    fo(i,SZ(g[prv])) {
        int v=g[prv][i];
        int a=go(OR(msk,v),v);
        best=min(best,a);
    }
    return best;
}
inline void Proc() {
    SCC();
    fo(i,ID) {
        g[i].clear();
    }

    fo(u,N) {
        fo(j,SZ(E[u])) {
            int v = E[u][j];
            if ( ROOT[u]!=ROOT[v] ) {
                g[ ROOT[u] ].pb( ROOT[v] );
            }
        }
    }


    SET(dp,-1);
    int best=inf;
    fo(i,ID) {
        int var=1+go( OR(0,i), i) ;
        best=min(best,var);
    }

    cout<<best;
    puts("");
}
int main() {
    int tt;
    CI(tt);
    foE(i,1,tt) {
        Read();
        cout<<"Case "<<i<<": ";
        Proc();
    }

}
// kate: indent-mode cstyle; space-indent on; indent-width 0;

