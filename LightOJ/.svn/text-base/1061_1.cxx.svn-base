#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <list>
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


const int map[92][8]={
    {0,4,7,5,2,6,1,3},
    {0,5,7,2,6,3,1,4},
    {0,6,3,5,7,1,4,2},
    {0,6,4,7,1,3,5,2},
    {1,3,5,7,2,0,6,4},
    {1,4,6,0,2,7,5,3},
    {1,4,6,3,0,7,5,2},
    {1,5,0,6,3,7,2,4},
    {1,5,7,2,0,3,6,4},
    {1,6,2,5,7,4,0,3},
    {1,6,4,7,0,3,5,2},
    {1,7,5,0,2,4,6,3},
    {2,0,6,4,7,1,3,5},
    {2,4,1,7,0,6,3,5},
    {2,4,1,7,5,3,6,0},
    {2,4,6,0,3,1,7,5},
    {2,4,7,3,0,6,1,5},
    {2,5,1,4,7,0,6,3},
    {2,5,1,6,0,3,7,4},
    {2,5,1,6,4,0,7,3},
    {2,5,3,0,7,4,6,1},
    {2,5,3,1,7,4,6,0},
    {2,5,7,0,3,6,4,1},
    {2,5,7,0,4,6,1,3},
    {2,5,7,1,3,0,6,4},
    {2,6,1,7,4,0,3,5},
    {2,6,1,7,5,3,0,4},
    {2,7,3,6,0,5,1,4},
    {3,0,4,7,1,6,2,5},
    {3,0,4,7,5,2,6,1},
    {3,1,4,7,5,0,2,6},
    {3,1,6,2,5,7,0,4},
    {3,1,6,2,5,7,4,0},
    {3,1,6,4,0,7,5,2},
    {3,1,7,4,6,0,2,5},
    {3,1,7,5,0,2,4,6},
    {3,5,0,4,1,7,2,6},
    {3,5,7,1,6,0,2,4},
    {3,5,7,2,0,6,4,1},
    {3,6,0,7,4,1,5,2},
    {3,6,2,7,1,4,0,5},
    {3,6,4,1,5,0,2,7},
    {3,6,4,2,0,5,7,1},
    {3,7,0,2,5,1,6,4},
    {3,7,0,4,6,1,5,2},
    {3,7,4,2,0,6,1,5},
    {4,0,3,5,7,1,6,2},
    {4,0,7,3,1,6,2,5},
    {4,0,7,5,2,6,1,3},
    {4,1,3,5,7,2,0,6},
    {4,1,3,6,2,7,5,0},
    {4,1,5,0,6,3,7,2},
    {4,1,7,0,3,6,2,5},
    {4,2,0,5,7,1,3,6},
    {4,2,0,6,1,7,5,3},
    {4,2,7,3,6,0,5,1},
    {4,6,0,2,7,5,3,1},
    {4,6,0,3,1,7,5,2},
    {4,6,1,3,7,0,2,5},
    {4,6,1,5,2,0,3,7},
    {4,6,1,5,2,0,7,3},
    {4,6,3,0,2,7,5,1},
    {4,7,3,0,2,5,1,6},
    {4,7,3,0,6,1,5,2},
    {5,0,4,1,7,2,6,3},
    {5,1,6,0,2,4,7,3},
    {5,1,6,0,3,7,4,2},
    {5,2,0,6,4,7,1,3},
    {5,2,0,7,3,1,6,4},
    {5,2,0,7,4,1,3,6},
    {5,2,4,6,0,3,1,7},
    {5,2,4,7,0,3,1,6},
    {5,2,6,1,3,7,0,4},
    {5,2,6,1,7,4,0,3},
    {5,2,6,3,0,7,1,4},
    {5,3,0,4,7,1,6,2},
    {5,3,1,7,4,6,0,2},
    {5,3,6,0,2,4,1,7},
    {5,3,6,0,7,1,4,2},
    {5,7,1,3,0,6,4,2},
    {6,0,2,7,5,3,1,4},
    {6,1,3,0,7,4,2,5},
    {6,1,5,2,0,3,7,4},
    {6,2,0,5,7,4,1,3},
    {6,2,7,1,4,0,5,3},
    {6,3,1,4,7,0,2,5},
    {6,3,1,7,5,0,2,4},
    {6,4,2,0,5,7,1,3},
    {7,1,3,0,6,4,2,5},
    {7,1,4,2,0,6,3,5},
    {7,2,0,5,1,4,6,3},
    {7,3,0,2,5,1,6,4}
};
const int R=(int)8;
const int C=(int)8;
int x[8];
int y[8];
int cnt;

inline int fun(int r1, int c1, int r2, int c2) {
    if (r1==r2&&c1==c2)return 0;
    if (r1==r2||c1==c2)return 1;
    if (abs(r1-r2)==abs(c1-c2))return 1;
    return 2;
}

bool grid[8][8];
inline void printgrid(int indi) {
    SET(grid,false);
    fo(i,8) {
        grid[i][ map[indi][i] ]=1;
    }
    fo(i,8) {
        fo(j,8) {
            cout<<( grid[i][j] ? 'q' : '.' );
        }
        line;
    }
}
const int inf=(int)1023456789;
int cur;
int dp[8][(1<<8)];
int go(int at, int msk) {
    if (at==8)return 0;

    int &best=dp[at][msk];
    if (best!=-1)return best;
    best=inf;
    fo(i,8) {
        if ( !( msk&(1<<i) ) ) {
            int v= fun(i,map[cur][i],x[at],y[at]);
            best=min( best, v+go(at+1, (msk|(1<<i)) ) );
        }
    }
    return best;
}
inline void Read() {
    char ch;
    cnt=0;
    fo(i,R) {
        fo(j,C) {
            cin>>ch;
            if (ch=='q') {
                x[cnt]=i;
                y[cnt]=j;
                ++cnt;
            }

        }
    }
}
inline void Proc() {
    int best=inf;

//    line;
//     debug(x,8);
//     debug(y,8);

    for (cur=0;cur<92;++cur) {
        SET(dp,-1);
        int localbest=go(0,0);
        best=min(best,localbest);
//         printgrid(cur);
//         debug(localbest);
    }

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




