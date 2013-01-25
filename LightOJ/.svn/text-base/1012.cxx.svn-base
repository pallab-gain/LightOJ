/*
 * Author  : Pallab
 * Program :
 *
 *
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
enum {
    mx=25
};
int R,C;
char G[mx][mx];
inline void Read() {
    CI(C,R);
    fo(i,R) {
        fo(j,C) {
            cin>>G[i][j];
        }
    }
}
int rr[]={-1,+1,+0,+0};
int cc[]={+0,+0,-1,+1};
int used[mx][mx];
inline int bfs(int sx, int sy) {
    queue<pair<int,int> >q;
    SET(used,0);
    q.push(mk(sx,sy));
    used[sx][sy]=1;
    while (!q.empty()) {
        sx=q.front().first;
        sy=q.front().second;
        q.pop();
        fo(i,4) {
            int tr=sx+rr[i],tc=sy+cc[i];
            if (tr<0||tc<0||tr>=R||tc>=C||G[tr][tc]!='.'||used[tr][tc])continue;
            q.push(mk(tr,tc));
            used[tr][tc]=1;
        }
    }
    int d=0;
    fo(i,R) {
        fo(j,C) {
            if (used[i][j])++d;
        }
    }

    return d;
}
inline void Proc() {
    fo(i,R) {
        fo(j,C) {
            if (G[i][j]=='@') {
                cout<<bfs(i,j);
                puts("");
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

