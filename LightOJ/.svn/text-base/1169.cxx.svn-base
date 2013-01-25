/*
 * Author  : Pallab
 * Program : 1169
 *
 * 2012-03-17 10:37:09
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
    int eattime;
    int jumptime;
    NODE(int eattime=0,int jumptime=0):
            eattime(eattime),jumptime(jumptime) {
        ;
    }
};
NODE house[2][1005];
int N;
inline void Read() {
    CI(N);
    fo(i,N) {
        CI(house[0][i].eattime);
    }
    fo(i,N) {
        CI(house[1][i].eattime);
    }
    house[0][0].jumptime=house[1][0].jumptime=0;
    foR(i,1,N) {
        CI(house[0][i].jumptime);
    }
    foR(i,1,N) {
        CI(house[1][i].jumptime);
    }
}
int dp[1000][1000][2];
const int inf=(int)1023456789;
int go(int at, int n, int side) {
    if (n==0)return 0;

    int &best=dp[at][n][side];
    if (best!=-1)return best;
    best=inf;
    best=min(best, house[side][at].eattime+go(at+1,n-1,side));
    best=min(best, house[side][at].jumptime+go(at,n,side?0:1));

    return best;
}
inline void Proc() {
    SET(dp,-1);
    int a=min(go(0,N,0),go(0,N,1));
    cout<<a;
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
