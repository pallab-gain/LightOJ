/*
 * Author  : Pallab
 * Program : 1316_4
 *
 * 2012-03-08 21:20:34
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
template<class T>
inline void debug(T _x) {
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
enum {
    mx=505,
    inf=1023456789
};
int bc[1<<16];
vector< pair<int,int> > E[mx];
int shops[20];
int N,M,S;
inline void pre() {
    fo(i,(1<<16)) {
        bc[i]=__builtin_popcount(i);
    }
}
inline void Read() {

    CI(N,M,S);
    fo(i,S) {
        CI(shops[i]);
    }
    //
    shops[S]=0;
    shops[S+1]=N-1;
    //
    fo(i,N) {
        E[i].clear();
    }
    int u,v,w;
    fo(i,M) {
        CI(u,v,w);
        E[u].pb(mk(v,w));
    }
}
//shortest path from each shops to shops
int D[mx];
int F[mx];
struct NODE {
    int v;
    int w;
    NODE(int v=0,int w=0):
            v(v),w(w) {
        ;
    }
    bool operator<(const NODE &r)const {
        return w<r.w;
    }
};
inline int dj(int src, int snk) {
    priority_queue< NODE >pq;
    SET(F,0);
    SET(D,63);
    pq.push(NODE(src,0));
    D[src]=0;
    while (!pq.empty()) {
        int u=pq.top().v;
        int w=D[u];
        pq.pop();

        if (u==snk)return w;
        if (F[u])continue;
        fo(i,SZ(E[u])) {
            int v=E[u][i].first;
            int d=E[u][i].second+w;
            if (F[v]==0&&d<D[v]) {
                D[v]=d;
                pq.push(NODE(v,-D[v]));
            }
        }
        F[u]=1;
    }

    return (int)inf;
}

int cost[20][20];
inline void apsf() {
    fo(i,S+2) {
        fo(j,S+2) {
            cost[i][j]=dj(shops[i],shops[j]);
        }
    }
}
int dp[16][1<<16];
int go(int at, int msk) {
    if (msk==0) {
        return cost[at][S+1];
    }
    int &best=dp[at][msk];
    if (best!=-1)return best;
    best=(int)inf;
    fo(i,S) {
        if (marked(msk,i)) {
            int var=go(i, XOR(msk,i))+cost[at][i];
            best=min(best,var);
        }
    }
    return best;
}
inline void Proc() {
    apsf();
    int best=(int)inf;
    int maxpick=0;
    SET(dp,-1);
    fo(i,(1<<S)) {
        int localpick=bc[i];
        int localbest=go(S,i);
        if (localbest<inf) {
            if (localpick>maxpick) {
                maxpick=localpick;
                best=localbest;
            }
            else if (localpick==maxpick) {
                best=min(best,localbest);
            }
        }
    }
    if (best<inf) {
        cout<<maxpick<<' '<<best;
        line;
    }
    else puts("Impossible");
}
int main() {
    pre();
    int tt;
    CI(tt);
    foE(i,1,tt) {
        Read();
        cout<<"Case "<<i<<": ";
        Proc();
    }
    return 0;
}
