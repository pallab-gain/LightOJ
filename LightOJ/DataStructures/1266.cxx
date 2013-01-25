/*
 * Author  : Pallab
 * Program : 1266
 *
 * 2012-05-12 15:24:59
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
const int maxn=1002;
int Tree[maxn][maxn];
bool Present[maxn][maxn];

inline void Update(int x, int y, int delta) {
    int y2 = y;
    while (x <= maxn) {
        y = y2;
        while ( y <= maxn ) {
            Tree[x][y] += delta;
            y +=(y & -y);
        }
        x += (x & -x);
    }
}

inline int Query(int x, int y) {
    int y2 = y;
    int ret = 0;
    while (x > 0) {
        y = y2;
        while ( y > 0 ) {
            ret += Tree[x][y];
            y -= (y & -y);
        }
        x -= (x & -x);
    }
    return ret;
}

inline void Solve() {
    SET(Tree,0);
    SET(Present,false);
    int q,sign;
    int x,y;
    int x1,y1,x2,y2;
    CI(q);
    while (q) {
        CI(sign);
        if (!sign) {
            CI(x,y);
            ++x;
            ++y;
            //update this point
            //if already not present
            if (Present[x][y]==false) {
                Present[x][y]=true;
                Update(x,y,1);
            }
        }
        else {
            CI(x1,y1,x2,y2);
            ++x1;
            ++y1;
            ++x2;
            ++y2;
            int total =Query(x2, y2) - Query(x1-1, y2) - Query(x2, y1-1) + Query(x1-1 ,y1-1);
            cout<<total;
            line;
        }
        --q;
    }
}
int main() {
    int tt;
    CI(tt);
    foE(i,1,tt) {
        cout<<"Case "<<i<<":\n";
        Solve();
    }
    return 0;
}
