/*
 * Author  : Pallab
 * Program : 1412_1.cxx
 *
 * 2012-03-21 16:30:05
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

const int maxn=100001;
vector<int> E[maxn];
int N;
int M;
int Q;
inline void Read() {
    int u,v;
    CI(N,M);

    fo(i,N) {
        E[i].clear();
    }
    fo(i,M) {
        CI(u,v);
        --u;
        --v;
        E[u].pb(v);
        E[v].pb(u);
    }
}

struct NODE {
    int nodes;
    int len;
    NODE(int nodes=0,int len=0):
            nodes(nodes),len(len) {
        ;
    }
};
inline bool cmp(NODE a, NODE b) {
    if (a.len!=b.len)return a.len>b.len;
    return a.nodes>b.nodes;
}

bitset<maxn>used2;
deque<NODE>q1,q2;
inline int bfs2(int src) {
    used2=0;
    q2.clear();

    q2.pb(NODE(src,1));
    used2[src]=1;

    int fardist=1;
    while (!q2.empty()) {
        int u=q2.front().nodes;
        int d=q2.front().len;
        q2.pop_front();

        fardist=max(fardist,d);
        fo(i,SZ(E[u])) {
            int v=E[u][i];
            if (!used2[v]) {
                used2[v]=1;
                q2.pb(NODE(v,d+1));
            }
        }
    }
    return fardist;
}

bitset<maxn>used;
inline NODE bfs1(int src) {
    q1.clear();
    q1.pb(NODE(src,1));

    int tot=1;
    used[src]=1;
    int farnode=src;
    int fardist=1;
    while (!q1.empty()) {
        int u=q1.front().nodes;
        int d=q1.front().len;
        q1.pop_front();

        if (d>fardist) {
            fardist=d;
            farnode=u;
        }
        fo(i, SZ(E[u])) {
            int v=E[u][i];
            if (!used[v]) {
                q1.pb(NODE(v,d+1));
                used[v]=1;
                ++tot;
            }
        }
    }
    //debug(used,N);
    int maxlen= bfs2(farnode);
    return NODE(tot,maxlen);
}
NODE vi[maxn];
int cnt;
int have[maxn];
inline void Proc() {
    line;
    used=0;
    SET(have,-1);

    cnt=0;
    fo(i,N) {
        if (!used[i]) {
            NODE tmp=bfs1(i);
            if (have[tmp.nodes]!=-1) {
                vi[ have[tmp.nodes] ].len = ( vi[ have[tmp.nodes] ].len, tmp.len );
            }
            else {
                vi[cnt]=tmp;
                have[tmp.nodes]=cnt;
                ++cnt;
            }
        }
    }
    sort(vi,vi+cnt,cmp);

    int k;
    CI(Q);
    fo(i,Q) {
        CI(k);
        fo(i,cnt) {
            int nodes=vi[i].nodes;
            int len=vi[i].len;
            if (nodes>=k) {
                int res=0;
                if (k<=len) {
                    res=k-1;
                }
                else {
                    res=len-1+((k-len)<<1);
                }
                cout<<res;
                line;
                goto L;
            }
        }
        puts("impossible");
L:
        ;
    }
}
int main() {
    int tt;
    CI(tt);
    foE(i,1,tt) {
        Read();
        cout<<"Case "<<i<<":";
        Proc();
    }
    return 0;
}
