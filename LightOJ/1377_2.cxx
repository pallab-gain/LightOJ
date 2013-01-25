/*
 * Author  : Pallab
 * Program : 1377_2
 *
 * 2012-03-14 19:53:46
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
const int maxn=200+5;
int R,C;
char G[maxn][maxn];
const int rr[]={-1,+1,+0,+0, -1,-1,+1,+1};
const int cc[]={+0,+0,-1,+1, -1,+1,+1,-1};
struct NODE {
    int r;
    int c;
    NODE(int r=0,int c=0):
            r(r),c(c) {
        ;
    }
};
vector<NODE> ports;
inline void Read() {
    scanf("%d %d\n",&R,&C);
    ports.clear();
    fo(i,R) {
        gets(G[i]);
        fo(j,C) {
            if (G[i][j]=='*')ports.pb(NODE(i,j));
        }
    }

}
int D[2][maxn][maxn];
inline void bfs(int sr, int sc, int id) {
    queue<NODE>q;
    q.push(NODE(sr,sc));
    D[id][sr][sc]=0;
    while (!q.empty()) {
        int r=q.front().r,c=q.front().c;
        q.pop();
        fo(i,4) {
            int tr=r+rr[i],tc=c+cc[i];
            if (tr<0||tc<0||tr>=R||tc>=C||G[tr][tc]=='#')continue;
            if (D[id][r][c]+1<D[id][tr][tc]) {
                D[id][tr][tc]=D[id][r][c]+1;
                if (G[tr][tc]!='*')
                    q.push(NODE(tr,tc));
            }
        }
    }

}

struct node {
    int d1;
    int d2;
    int id;
    node(int d1,int d2,int id):
            d1(d1),d2(d2),id(id) {
        ;
    }
};
inline bool cmp1(node A, node B) {
    return A.d1<B.d1;
}
inline bool cmp2(node A,node B) {
    return A.d2<B.d2;
}
vector<node> v1,v2;
inline void Proc() {
    NODE source,sink;
    SET(D,63);
    int inf=D[0][0][0];
    fo(i,R) {
        fo(j,C) {
            if (G[i][j]=='P') {
                source=NODE(i,j);
                goto L1;
            }
        }
    }
L1:
    fo(i,R) {
        fo(j,C) {
            if (G[i][j]=='D') {
                sink=NODE(i,j);
                goto L2;
            }
        }
    }
L2:
    ;
    bfs(source.r,source.c,0);
    bfs(sink.r,sink.c,1);
    int sz=SZ(ports);
    if (sz<=1) {
        int v=D[0][sink.r][sink.c];
        if (v<inf) {
            cout<<v;
            line;
        }
        else {
            puts("impossible");
        }
    }
    else {
        int best=D[0][sink.r][sink.c];
        v1.clear();
        v2.clear();
        fo(i,sz) {
            int r=ports[i].r;
            int c=ports[i].c;
            int d1=D[0][r][c];
            int d2=D[1][r][c];
            v1.pb(node(d1,d2,i));
            v2.pb(node(d1,d2,i));
        }

        fo(i,sz) {
            int d=v1[i].d1+v1[i].d2+2;
            best=min(best,d);
        }
        sort(v1.begin(),v1.end(),cmp1);
        sort(v2.begin(),v2.end(),cmp2);
        fo(i,sz) {
            fo(j,sz) {
                if (v1[i].id!=v2[j].id) {
                    int d=v1[i].d1+v2[j].d2+1;
                    best=min(best,d);
                    goto L3;
                }
            }
        }
L3:
        fo(i,sz) {
            fo(j,sz) {
                if (v2[i].id!=v1[j].id) {
                    int d=v2[i].d2+v1[j].d1+1;
                    best=min(best,d);
                    goto L4;
                }
            }
        }
L4:
        if (best<inf) {
            cout<<best;
            line;
        }
        else {
            puts("impossible");
        }
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
