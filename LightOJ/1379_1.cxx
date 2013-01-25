/*
 * Author  : Pallab
 * Program : 1379_1
 *
 * 2012-03-07 13:32:57
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
inline bool CI(int &_x, int &_y, int &_z, int &_zz, int &_kk) {
    return CI(_x)&&CI(_y)&&CI(_z)&&CI(_zz)&&CI(_kk) ;
}
enum {
    mx=10005,
    inf=1023456789
};
struct node {
    int v;
    int c;
    node(int v=0,int c=0):
            v(v),c(c) {
        ;
    }
};
struct edge {
    int u;
    int v;
    int w;
    edge(int u=0,int v=0,int w=0):
            u(u),v(v),w(w) {
        ;
    }
};

vector<node>E[2][mx];
vector<edge>edges;
int N,M,source,sink,high;
inline void Read() {
    CI(N,M,source,sink,high);
    --source;
    --sink;
    //clear
    fo(i,N) {
        E[0][i].clear();
        E[1][i].clear();
    }
    edges.clear();

    int u,v,c;
    fo(i,M) {
        CI(u,v,c);
        --u;
        --v;
        E[0][u].pb(node(v,c));
        E[1][v].pb(node(u,c));
        edges.pb(edge(u,v,c));
    }
}
struct NODE {
    int v;
    int c;
    NODE(int v=0,int c=0)
            :v(v),c(c) {
        ;
    }
    bool operator<(const NODE &r)const {
        return c<r.c;
    }
};

int F[2][mx];
int D[2][mx];
inline void dj(int src, int id) {
    priority_queue< NODE > pq;

    pq.push(NODE(src,0));
    D[id][src]=0;
    while (!pq.empty()) {
        int u=pq.top().v;
        int d=D[id][u];
        pq.pop();

        if (F[id][u])continue;
        fo(i,SZ(E[id][u])) {
            int v=E[id][u][i].v;
            int ld=E[id][u][i].c+d;
            if ( F[id][v]==0&&ld<D[id][v]) {
                D[id][v]=ld;
                pq.push( NODE(v,-D[id][v]) );
            }
        }
        F[id][u]=1;
    }
}
inline void Proc() {
    SET(D,63);
    SET(F,0);
    dj(source,0);
    dj(sink,1);
//     line;
//     fo(i,N) {
//         debug(i, D[0][i],D[1][i]);
//     }
//     line;

    int best=-1;
    fo(i,M) {
        int u=edges[i].u;
        int v=edges[i].v;
        int w=edges[i].w;

        int localhigh = D[0][u]+D[1][v]+w;
        //debug(localhigh,high,w);
        if (localhigh<=high)best=max(best,w);
    }
    cout<<best;
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
