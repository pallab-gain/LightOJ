/*
 * Author  : Pallab
 * Program : 1218
 *
 * 2012-02-28 14:52:06
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

inline void debug(int _x) {
    cout<<_x<<'\n';
}
inline void debug(int _x,int _y) {
    cout<<_x<<' '<<_y<<'\n';
}
inline void debug(int _x,int _y,int _z) {
    cout<<_x<<' '<<_y<<' '<<_z<<'\n';
}
inline void debug(int _x,int _y,int _z,int _zz) {
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

int N;
set<int>st;
int num[101];
inline void Read() {
    st.clear();
    CI(N);
    fo(i,N) {
        CI(num[i]);
        st.insert(num[i]);
    }
    N=SZ(st);
    int k=0;
    foit(it,st) {
        num[k]=(*it);
        ++k;
    }
}
enum {
    maxn=(100<<1)+5,
    inf=(int)1023456789
};
int flow[maxn][maxn];
int cap[maxn][maxn];
vector<int>E[maxn];
int source,sink;

inline void build() {
    SET(cap,0);
    fo(i,maxn)E[i].clear();

    fo(i,N) {
        for (int j=i+1;j<N;++j) {
            if ( num[j]%num[i]==0 ) {
                cap[i][N+j]=1;
                E[i].pb(N+j);
                E[N+j].pb(i);
                //debug(i,j,N+j);
            }
        }
    }
    //source => all
    source=N+N;
    sink = source+1;
    fo(i,N) {
        cap[source][i]=1;
        E[source].pb(i);
        E[i].pb(source);
        // debug(source,i);
    }
    fo(i,N) {
        cap[i+N][sink]=1;
        E[i+N].pb(sink);
        E[sink].pb(i);
    }
}
int from[maxn];
int used[maxn];
inline void bfs(int src,int snk) {
    SET(used,0);
    SET(from,-1);
    queue<int>q;
    q.push(src);
    used[src]=1;
    while (!q.empty()) {
        int u=q.front();
        q.pop();
        fo(i,SZ(E[u])) {
            int v=E[u][i];
            if ( used[v]==0&&cap[u][v]-flow[u][v]>0) {
                used[v]=1;
                from[v]=u;
                q.push(v);
                if (v==snk)return ;
            }
        }
    }
}
inline int augument(int src,int snk) {
    bfs(src,snk);
    if (from[snk]==-1)return 0;
    int v=snk,mc=inf;
    while (from[v]!=-1) {
        int u=from[v];
        mc=min(mc,cap[u][v]-flow[u][v]);
        v=u;
    }
    v=snk;
    while (from[v]!=-1) {
        int u=from[v];
        flow[u][v]+=mc;
        flow[v][u]-=mc;
        v=u;
    }
    return mc;
}
inline int maxflow() {
    SET(flow,0);
    int tf=0;
    while (1) {
        int tc=augument(source,sink);
        if (tc==0)break;
        tf+=tc;
    }
    return tf;
}
inline void Print() {
    fo(i,N) {
        for (int j=i+1;j<N;++j) {
            if (flow[i][N+j]>0) {
                debug(num[i],num[j]);
            }
        }
    }
    //sleep(1);
    puts("");
}
int kill[100];
inline void Proc() {
    SET(kill,0);
    build();
    int mxpair=maxflow();
    for (int i=N-1;i>=0;--i) {
        cap[source][i]=0;
        cap[i+N][sink]=0;
        int tmp = maxflow();
        //debug(num[i],tmp,mxpair);
        if (tmp<mxpair) {
            mxpair=tmp;
            //cout<<"PARMANENTLY ELEINAE : "<<num[i]<<"\n";
            kill[i]=1;
        }
        else {
            //cout<<"STAY "<<num[i]<<"\n";
            cap[source][i]=1;
            cap[i+N][sink]=1;
        }
        //Print();
    }
    fo(i,N) {
        if (!kill[i]) {
            cout<<' '<<num[i];
        }
    }
    puts("");
}
int main() {
    int tt;
    CI(tt);
    foE(i,1,tt) {
        Read();
        cout<<"Case "<<i<<":";
        Proc();
    }

}
// kate: indent-mode cstyle; space-indent on; indent-width 0;
