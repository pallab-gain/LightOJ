/*
 * Author  : Pallab
 * Program : 1046
 *
 * 2012-03-06 18:05:17
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
int mov[8][2]={ {-2,+1},{-2,-1},{+2,+1},{+2,-1}, {-1,-2},{+1,-2},{-1,+2},{+1,+2} };

char grid[12][12];
int R,C;
inline void Read() {
    CI(R,C);
    fo(i,R) {
        fo(j,C) {
            cin>>grid[i][j];
        }
    }
}
inline void Print() {
    line;
    fo(i,R) {
        fo(j,C) {
            cout<<grid[i][j];
        }
        line;
    }
}
const int inf = (int)1023456789;
int D[15][15];
inline int bfs(int sr,int sc, int dr, int dc) {
    SET(D,63);
    queue< pair<int,int> > q;
    q.push(mk(sr,sc));
    D[sr][sc]=0;

    while (!q.empty()) {
        int r=q.front().first;
        int c=q.front().second;
        int d=D[r][c];
        q.pop();
        if (r==dr&&c==dc)return d;
        fo(i,8) {
            int tr=r+mov[i][0];
            int tc=c+mov[i][1];
            if (tr<0||tc<0||tr>=R||tc>=C)continue;
            if (d+1<D[tr][tc]) {
                D[tr][tc]=d+1;
                q.push(mk(tr,tc));
            }
        }

    }
    return -1;
}
struct NODE {
    int rx;
    int ry;
    int k;
    NODE(int rx=0,int ry=0,int k=0):
            rx(rx),ry(ry),k(k) {
        ;
    }
};
vector< NODE > knights;
inline void Proc() {
    knights.clear();
    fo(i,R) {
        fo(j,C) {
            if (grid[i][j]!='.') {
                knights.pb( NODE(i,j, grid[i][j]-'0') );
            }
        }
    }
    int best=inf;
    fo(i,R) {
        fo(j,C) {
            int sr=i;
            int sc=j;
            int sum=0;
            int bad=false;
            fo(k,SZ(knights)) {
                int var = bfs( sr,sc, knights[k].rx,knights[k].ry);
                if ( var==-1) {
                    bad=true;
                    break;
                }
                else {
                    sum=sum+(var/knights[k].k)+( var%knights[k].k ? 1 : 0 );
                }
            }
            if (!bad &&sum<best)best=sum;
        }
    }

    if (best==inf)cout<<-1;
    else
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

}
