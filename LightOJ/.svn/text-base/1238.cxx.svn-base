/*
 * Author  : Pallab
 * Program : 1238
 *
 * 2012-03-22 13:44:55
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
char grid[25][25];
int R,C;
int hr,hc;

int x[3];
int y[3];
int cnt;
inline void Read() {
    CI(R,C);
    cnt=0;
    fo(i,R) {
        fo(j,C) {
            cin>>grid[i][j];
            if (grid[i][j]=='a'||grid[i][j]=='b'||grid[i][j]=='c') {
                x[cnt]=i;
                y[cnt++]=j;
            }
            else if (grid[i][j]=='h') {
                hr=i;
                hc=j;
            }
        }
    }
}
const int rr[]={-1,+1,+0,+0, -1,-1,+1,+1};
const int cc[]={+0,+0,-1,+1, -1,+1,+1,-1};

struct NODE {
    int r;
    int c;
    int d;
    NODE(int r=0,int c=0,int d=0):
            r(r),c(c),d(d) {
        ;
    }
};
int D[25][25][3];
deque< NODE > q;
inline int bfs(int sr, int sc, int id) {
    q.clear();
    q.pb( NODE(sr,sc,0) );
    D[sr][sc][id]=1;
    while (!q.empty()) {
        int fr=q.front().r;
        int fc=q.front().c;
        int d=q.front().d;
        q.pop_front();
        if (fr==hr&&fc==hc)return d;
        fo(i,4) {
            int tr=fr+rr[i];
            int tc=fc+cc[i];
            if (tr<0||tc<0||tr>=R||tc>=C||grid[tr][tc]=='m'||grid[tr][tc]=='#')continue;
            if (!D[tr][tc][id]) {
                D[tr][tc][id]=1;
                q.pb(NODE(tr,tc,d+1));
            }
        }
    }
    return -1;//kill

}
inline void Proc() {
    int ret=0;
    SET(D,0);
    fo(i,cnt) {
        ret=max(ret, bfs(x[i],y[i],i));
    }
    cout<<ret;
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
