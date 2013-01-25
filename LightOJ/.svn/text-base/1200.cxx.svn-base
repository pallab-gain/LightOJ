/*
 * Author  : Pallab
 * Program : 1200
 *
 * 2012-03-16 16:28:11
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
const int maxn=110;// maximum number of iteams
const int maxw=10010; //maximum weights
struct NODE {
    int p;
    int c;
    int w;
    NODE(int p=0,int c=0,int w=0):
            p(p),c(c),w(w) {
        ;
    }
};
int N,W;
NODE iteams[maxn];
inline void Read() {
    CI(N,W);
    fo(i,N) {
        CI(iteams[i].p,iteams[i].c,iteams[i].w);
    }
}

int res[maxw];
bool can[maxw];
inline void knapsack(int w) {
    SET(can,false);
    SET(res,0);
    can[0]=true;
    fo(i,N) {
        for (int j=0,k=w-iteams[i].w;j<=k;++j) {
            if (can[j]) {
                can[j+iteams[i].w]=true;
                res[j+iteams[i].w]=max(res[j+iteams[i].w],
                                       res[j]+iteams[i].p);
            }
        }
    }
    int best=0;
    for (int j=0;j<=w;++j) {
        best=max(best, res[j]);
    }
    cout<<best;
    line;
}
inline void Proc() {
    int w=0;
    fo(i,N) {
        w+=(iteams[i].c*iteams[i].w);
    }
    if (w>W)puts("Impossible");
    else {
        knapsack(W-w);
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
