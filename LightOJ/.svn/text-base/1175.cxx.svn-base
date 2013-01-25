/*
 * Author  : Pallab
 * Program : 1175
 *
 * 2012-03-17 10:17:33
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
const int maxn=201;
int R,C;
char G[maxn][maxn];
inline void Read() {
    CI(R,C);
    fo(i,R) {
        fo(j,C) {
            cin>>G[i][j];
        }
    }
}
const int rr[]={-1,+1,+0,+0, -1,-1,+1,+1};
const int cc[]={+0,+0,-1,+1, -1,+1,+1,-1};

int D1[maxn][maxn];
inline void bfs1(int sr, int sc) {
    queue< pair<int,int> > q;

    q.push(mk(sr,sc));
    D1[sr][sc]=0;
    while (!q.empty()) {
        int r=q.front().first;
        int c=q.front().second;
        q.pop();
        fo(i,4) {
            int tr=r+rr[i];
            int tc=c+cc[i];
            if (tr<0||tc<0||tr>=R||tc>=C||G[tr][tc]=='#')continue;
            if (D1[r][c]+1<D1[tr][tc]) {
                q.push(mk(tr,tc));
                D1[tr][tc]=D1[r][c]+1;
            }
        }
    }

}
int D2[maxn][maxn];
inline int bfs2(int sr,int sc) {
    queue< pair<int,int> > q;
    SET(D2,63);

    D2[sr][sc]=0;
    q.push(mk(sr,sc));
    while (!q.empty()) {
        int r=q.front().first;
        int c=q.front().second;
        if (r==0||c==0||r+1==R||c+1==C) {
            return D2[r][c]+1;
        }
        q.pop();
        fo(i,4) {
            int tr=r+rr[i];
            int tc=c+cc[i];
            if (tr<0||tc<0||tr>=R||tc>=C||G[tr][tc]=='#')continue;
            int d=D2[r][c]+1;
            if (d<D1[tr][tc] && d<D2[tr][tc]) {
                q.push(mk(tr,tc));
                D2[tr][tc]=d;
            }
        }

    }
    return -1;
}
inline void Proc() {
    SET(D1,63);
    fo(i,R) {
        fo(j,C) {
            if (G[i][j]=='F') {
                bfs1(i,j);
            }
        }
    }
L1:
    fo(i,R) {
        fo(j,C) {
            if (G[i][j]=='J') {
                int var=bfs2(i,j);
                if (var==-1) {
                    puts("IMPOSSIBLE");
                } else {
                    cout<<var;
                    line;
                }
                return ;
            }
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
