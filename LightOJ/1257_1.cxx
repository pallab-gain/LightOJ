/*
 * Author  : Pallab
 * Program : 1257_1
 *
 * 2012-03-18 22:54:45
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

template<class T1>
inline void debug(T1 _x) {
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
template< class T1>
inline void debug(T1 _array,int _size) {
    cout<<"[";
    for (int i=0;i<_size;++i) {
        cout<<' '<<_array[i];
    }
    puts(" ]");
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

struct NODE {
    int v;
    int w;
    NODE(int v=0,int w=0):
            v(v),w(w) {
        ;
    }
};
const int maxn=30005;
int N;
vector< NODE > E[maxn];
bitset<maxn >in1;
inline void Read() {
    CI(N);
    fo(i,N) {
        E[i].clear();
    }

    int u,v,w;
    in1=0;
    fo(i,N-1) {
        CI(u,v,w);
        in1[v]=1;
        E[u].pb(NODE(v,w));
        E[v].pb(NODE(u,w));
    }
}
int D1[maxn];
inline void bfs1(int node) {
    SET(D1,-1);
    queue<int>q;
    q.push(node);
    D1[node]=0;
    while (!q.empty()) {
        int u=q.front();
        q.pop();
        fo(i,SZ(E[u])) {
            int v=E[u][i].v;
            int w=E[u][i].w+D1[u];
            if (D1[v]==-1) {
                D1[v]=w;
                q.push(v);
            }
        }
    }
}
int D2[maxn];
inline void bfs2(int node) {
    SET(D2,-1);
    queue<int>q;
    q.push(node);
    D2[node]=0;
    while (!q.empty()) {
        int u=q.front();
        q.pop();
        fo(i,SZ(E[u])) {
            int v=E[u][i].v;
            int w=E[u][i].w+D2[u];
            if (D2[v]==-1) {
                D2[v]=w;
                q.push(v);
            }
        }
    }
}
int D3[maxn];
inline void bfs3(int node) {
    SET(D3,-1);
    queue<int>q;
    q.push(node);
    D3[node]=0;
    while (!q.empty()) {
        int u=q.front();
        q.pop();
        fo(i,SZ(E[u])) {
            int v=E[u][i].v;
            int w=E[u][i].w+D3[u];
            if (D3[v]==-1) {
                D3[v]=w;
                q.push(v);
            }
        }
    }
}
inline void Proc() {
    fo(i,N) {
        if (!in1[i]) {
            bfs1(i);
            goto L1;
        }
    }
L1:
    int d=-1;
    int a=0;
    fo(i,N) {
        if (D1[i]>d) {
            d=D1[i];
            a=i;
        }
    }
    bfs2(a);
    d=-1;
    a=0;
    fo(i,N) {
        if (D2[i]>d) {
            d=D2[i];
            a=i;
        }
    }
    bfs3(a);
//     debug(D1,N);
//     debug(D2,N);
//     debug(D3,N);

    fo(i,N) {
        cout<<max(D1[i],max(D2[i],D3[i]));
        line;
    }
}
int main() {
    int tt;
    CI(tt);
    foE(i,1,tt) {
        Read();
        cout<<"Case "<<i<<":";
        line;
        Proc();
    }
    return 0;
}
