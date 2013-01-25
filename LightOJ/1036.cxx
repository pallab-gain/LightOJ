/*
 *      ID : pallab81
 *      PROG : 1036
 *      LANG : C++
 *
 *      2012-06-08 23:45:30
 *      "I have not failed, I have just found 10000 ways that won't work.
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
#define line putchar_unlocked('\n')

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
    for (int i=0; i<_size; ++i) {
        cout<<' '<<_array[i];
    }
    puts(" ]");
}

#define getchar getchar_unlocked
#define putchar putchar_unlocked

inline void fastRead(int *a) {
    register char c=0;
    while (c<33) c=getchar();
    *a=0;
    while (c>33)
    {
        *a=*a*10+c-'0';
        c=getchar();
    }
}
inline string fastRead() {
    register char c[33];
    gets(c);
    return (string)c;
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
inline void wait( double seconds ) {
    double endtime = clock()+( seconds* CLOCKS_PER_SEC );
    while ( clock() < endtime ) {
        ;
    }
}
const int mxn = 505;
namespace Data {
int in1[mxn][mxn];
int in2[mxn][mxn];
int R,C;
inline void Init() {
    SET(in1,0);
    SET(in2,0);
}
inline void read() {
    fastRead(&R);
    fastRead(&C);

    foE(i,1,R) {
        foE(j,1,C) {
            fastRead(&in1[i][j]);
        }
    }
    foE(i,1,R) {
        foE(j,1,C) {
            fastRead(&in2[i][j]);
        }
    }
}
}
namespace Build {
int rowSum[mxn][mxn];
int colSum[mxn][mxn];
inline void proc() {
    foE(i,1,Data::R) {
        int sum=0;
        foE(j,1,Data::C) {
            sum+=Data::in1[i][j];
            rowSum[i][j]=sum;
        }
    }
    foE(i,1,Data::C) {
        int sum=0;
        foE(j,1,Data::R) {
            sum+=Data::in2[j][i];
            colSum[j][i]=sum;
        }
    }
}
}
namespace Run {
int bestOf[mxn][mxn];
inline void dp() {
    SET(bestOf,0);
    foE(i,1,Data::R) {
        foE(j,1,Data::C) {
            int v1 = Build::rowSum[i][j]+bestOf[i-1][j];
            int v2 = Build::colSum[i][j]+bestOf[i][j-1];
            bestOf[i][j]= max(v1,v2);
        }
    }
}
inline int getResult() {
//     foE(i,1,Data::R) {
//         foE(j,1,Data::C) {
//             //printf("%3d",Data::in1[i][j]);
//             //printf("%3d",Build::rowSum[i][j]);
//             printf("%3d",bestOf[i][j]);
//         }
//         line;
//     }
//     line;
//     return 0;
    return bestOf[Data::R][Data::C];
}
}

inline void Solve() {
    Data::read();
    Build::proc();
    Run::dp();
    cout<<Run::getResult();
    line;

}
#define showcase
int main() {
    Data::Init();
    int tt;
    CI(tt);
    foE(i,1,tt) {
#ifdef showcase
        cout<<"Case "<<i<<": ";
#endif
        Solve();
    }


    return 0;
}
// kate: indent-mode cstyle; space-indent on; indent-width 0; 
