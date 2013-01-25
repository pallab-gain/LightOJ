/*
 * Author  : Pallab
 * Program : 1066
 *
 * 2012-03-06 20:05:43
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
    mx=11+5,
    inf=1023456789
};
char grid[mx][mx];
int N;

inline void Read() {
    CI(N);
    fo(i,N) {
        fo(j,N) {
            cin>>grid[i][j];
        }
    }
}

struct NODE {
    int r;
    int c;
    int d;
    int nxt;
    NODE(int r=0,int c=0,int d=0, int nxt=0):
            r(r),c(c),d(d),nxt(nxt) {
        ;
    }
};
int rr[]={-1,+1,+0,+0};
int cc[]={+0,+0,-1,+1};
vector<char>all;
int D[mx][mx][28];
int K;

inline int bfs(int sr, int sc) {
    fo(i,mx) {
        fo(j,mx) {
            fo(k,28) {
                D[i][j][k]=inf;
            }
        }
    }
    queue<NODE>q;
    q.push( NODE(sr,sc,1,1) );
    D[sr][sc][1]=0;
    while (!q.empty()) {
        int r=q.front().r;
        int c=q.front().c;
        int d = q.front().d;
        int nxt=q.front().nxt;
        q.pop();
        fo(i,4) {
            int tr=r+rr[i];
            int tc=c+cc[i];
            int w=D[r][c][d]+1;
            if (tr<0||tc<0||tr>=N||tc>=N||grid[tr][tc]=='#')continue;
            if (grid[tr][tc]=='.') {
                if (w<D[tr][tc][d]) {
                    D[tr][tc][d]=w;
                    q.push( NODE(tr,tc,d,nxt) );
                }
            }
            else {
                if ( grid[tr][tc]==all[nxt] ) {
                    if ( w<D[tr][tc][d+1]) {
                        D[tr][tc][d+1]=w;
                        q.push( NODE(tr,tc,d+1,nxt+1) );
                    }
                }
                else if ( grid[tr][tc]<all[nxt] ) {
                    if ( w<D[tr][tc][d]) {
                        D[tr][tc][d]=w;
                        q.push( NODE(tr,tc,d,nxt) );
                    }
                }
            }
        }
    }
    fo(i,N) {
        fo(j,N) {
            if (grid[i][j]==all[K-1]) {
                return D[i][j][K];
            }
            //cout<<D[i][j][3]<<' ';
        }
    }
    return (int)inf;
}
inline void Proc() {
    all.clear();
    int sr,sc;
    fo(i,N) {
        fo(j,N) {
            if (grid[i][j]>='A'&&grid[i][j]<='Z') {
                all.pb(grid[i][j]);
            }
        }
    }
    K=SZ(all);
    sort(all.begin(),all.end(),less<char>());
    all.pb('z');
    fo(i,N) {
        fo(j,N) {
            if (grid[i][j]==all[0]) {
                int var=bfs(i,j);
                if (var<(int)inf) {
                    cout<<var;
                    line;
                }
                else {
                    puts("Impossible");
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

}