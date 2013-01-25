/*
 * Author  : Pallab
 * Program : 1417
 *
 * 2012-03-09 15:52:20
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
enum {
    MAXN=50005
};
int N;
vector<int>g[MAXN];
inline void Read() {
    CI(N);
    fo(i,N)g[i].clear();
    int u,v;
    fo(i,N) {
        CI(u,v);
        --u;
        --v;
        g[u].pb(v);
    }
}
int ID;
int ROOT[MAXN];

int INDEX[MAXN];
int LOWLINK[MAXN];
bitset< MAXN > instack;
int sack[MAXN];
int cnt;
int timer;

void tarjan(int v) {
    ++timer;
    INDEX[v]=LOWLINK[v]=timer;
    sack[cnt++]=v;
    instack[v]=1;
    fo(i,SZ(g[v])) {
        int w = g[v][i];
        if ( INDEX[w]==0 ) {
            tarjan(w);
            LOWLINK[v]=min(LOWLINK[v],LOWLINK[w]);
        }
        else if ( instack[w] ) {
            LOWLINK[v]=min(LOWLINK[v],INDEX[w]);
        }
    }
    if ( LOWLINK[v]==INDEX[v] ) {
        int w ;
        do {
            w = sack[--cnt];
            instack[w]=0;
            ROOT[w]=ID;
        } while (w!=v);
        ++ID;
    }
}

inline void SCC() {
    timer=0;
    instack=0;
    cnt=0;
    SET(INDEX,0);
    ID=0;
    fo(v,N) {
        if (INDEX[v]==0 ) {
            tarjan(v);
        }
    }

}
vector<int>G[MAXN];
int minindex[MAXN];
int howmany[MAXN];

bitset<MAXN> used;
int cango;
void dfs(int u) {
    if (!used[u]) {
        used[u]=1;
        cango+=howmany[u];
        fo(i,SZ(G[u])) {
            int v=G[u][i];
            dfs(v);
        }
    }
}

inline void Proc() {
    SCC();
    SET(minindex,63);
    SET(howmany,0);

    fo(i,ID) {
        G[i].clear();
    }
    fo(i,N) {
        int u=i;
        minindex[ ROOT[u] ]=min(minindex[ ROOT[u] ],u);
        howmany[ROOT[u]]++;

        fo(j,SZ(g[u])) {
            int v=g[u][j];
            if (ROOT[u]!=ROOT[v]) {
                G[ROOT[u]].pb(ROOT[v]);
            }
        }
    }
    int maxgo=0;
    int indx=0;
    fo(i,ID) {
        used=0;
        cango=0;
        dfs(i);
        if (cango>maxgo) {
            maxgo=cango;
            indx=minindex[i];
        }
        else if (cango==maxgo) {
            indx=min(indx,minindex[i]);
        }
    }
    cout<<indx+1;
    line;
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
