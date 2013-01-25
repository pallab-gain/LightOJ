/*
 * Author  : Pallab
 * Program : 1081
 *
 * 2012-05-12 19:15:22
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
const int SIZE = 512;
int a[SIZE][SIZE];
int mx[SIZE<<1][SIZE<<1];
int n,m,q;

inline void Add(int x,int y,int v) {
    int a = x+n-1;
    int b = y+m-1;

    mx[a][b]=v;
    for (int j = (b - 1) >> 1; j >= 0; --j >>= 1) {
        mx[a][j] = max(mx[a][(j << 1) | 1], mx[a][(j + 1) << 1]);
    }

    for (int i = (a - 1) >> 1; i >= 0; --i >>= 1) {
        for (int j = b; j >= 0; --j >>= 1) {
            mx[i][j] = max(mx[(i << 1) | 1][j], mx[(i + 1) << 1][j]);
        }
    }
}
inline int MaxY(int i, int x1, int x2) {
    int a, b, t;
    int lmax = mx[i][a = x1 + m - 1], rmax = mx[i][b = x2 + m - 1];
    for (int l = a, r = b; l < r - 1; --l >>= 1, --r >>= 1) {
        if ((l & 1)&& lmax < mx[i][t = l + 1]) lmax = mx[i][t];
        if (!(r & 1) && rmax < mx[i][t = r - 1]) rmax = mx[i][t];
    }
    return max(lmax, rmax);
}
inline int Max(int x1, int y1, int x2, int y2) {
    int a, b, t;
    int lmax = MaxY(a = x1 + n - 1, y1, y2), rmax = MaxY(b = x2 + n - 1, y1, y2);
    for (int lx = a, rx = b; lx < rx - 1; --lx >>= 1, --rx >>= 1) {
        if ((lx & 1) && lmax < (t = MaxY(lx + 1, y1, y2))) lmax = t;
        if (!(rx & 1) && rmax < (t = MaxY(rx - 1, y1, y2))) rmax = t;
    }
    return max(lmax, rmax);
}


inline void Proc() {
    int R;
    CI(R,q);
    m=n=R;
    int am = m, an = n;
    n--, m--;
    while (n & (n + 1)) {
        n |= n + 1;
    }
    n++;
    while (m & (m + 1)) {
        m |= m + 1;
    }
    m++;

    for (int i = 0; i < am; i++) {
        for (int j = 0; j < an; j++) {
            CI(a[i][j]);
            Add(i, j, a[i][j]);
        }
    }
    int r1,c1,r2,c2;
    int S;
    line;
    while (q--) {
        CI(r1,c1,S);
        r2=r1+S-1;
        c2=c1+S-1;
        cout<<Max(--r1,--c1,--r2,--c2);
        line;
    }
}
int main() {
    int tt;
    CI(tt);
    foE(i,1,tt) {
        cout<<"Case "<<i<<":";
        Proc();
    }
    return 0;
}




