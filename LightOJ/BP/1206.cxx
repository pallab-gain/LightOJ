/*
 * Author  : Pallab
 * Program : 1206
 *
 * 2012-02-27 21:20:10
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
inline void debug(int _x,int _y,int _z,int _zz,int _zzz) {
    cout<<_x<<' '<<_y<<' '<<_z<<' '<<_zz<<' '<<_zzz<<'\n';
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

struct node {
    int t;
    int x1;
    int y1;
    int x2;
    int y2;
    node(int t,int x1,int y1,int x2,int y2):
            t(t),x1(x1),y1(y1),x2(x2),y2(y2) {
        ;
    }
};
vector<node>vi;
int M;
inline void Read() {
    vi.clear();
    CI(M);
    int h1,m1;
    char ch;
    int x1,y1,x2,y2;
    fo(i,M) {
        scanf("%d:%d %d %d %d %d",&h1,&m1,&x1,&y1,&x2,&y2);
        int t=(h1*60)+m1;
        vi.pb( node(t,x1,y1,x2,y2) );
    }
}
const int maxn=500;
vector<int>g[maxn];
inline void build_bpnetwork() {
    fo(i,maxn)g[i].clear();
    fo(i,M) {
        for (int j=i+1;j<M;++j) {
            int xdist=abs(vi[i].x1-vi[i].x2);
            int ydist=abs(vi[i].y1-vi[i].y2);

            int _xdist=abs(vi[i].x2-vi[j].x1);
            int _ydist=abs(vi[i].y2-vi[j].y1);
            int total=xdist+ydist+_xdist+_ydist;
            if (vi[i].t+total<vi[j].t) {
                g[i].pb(j);
            }
        }
    }
}
static int used[maxn];
static int mt[maxn];

int try_kuhn(int v) {
    if (used[v])return 0;
    used[v]=1;
    fo(i,SZ(g[v])) {
        int to=g[v][i];
        if (mt[to]==-1||try_kuhn(mt[to])) {
            mt[to]=v;
            return 1;
        }
    }
    return 0;
}
inline int match() {
    build_bpnetwork();
    SET(mt,-1);
    fo(i,M) {
        SET(used,0);
        try_kuhn(i);
    }
    int d=0;
    fo(i,M) {
        if (mt[i]!=-1) {
            ++d;
        }
    }
    return d;
}
inline void Proc() {
    int var=match();
    //debug(M,var,M-var);
    cout<<M-var;
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

