/*
 *      ID : pallab81
 *      PROG : F_1
 *      LANG : C++
 *
 *      2012-06-05 20:54:27
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
namespace in {
Int a,b;
vector<int> vi;
inline void Read() {
    scanf("%lld %lld",&a,&b);
    if (a>b)swap(a,b);
}
inline void Convert(Int n) {
    vi.clear();
    while (n>0) {
        vi.pb( n%10 );
        n/=10;
    }
    reverse(vi.begin(),vi.end());
}
}

Int dp[20][20][2][2];
//left, right , from, smaller, smaller flag
Int go(int l, int r, int f, int s, int ss) {
    if (l>r) {
        if ( ss==1 )return s==1;
        return 1;
    }
    Int& var=dp[l][r][s][ss];
    if (var!=-1)return var;
    var=0;
    //if already smaller
    if (s==1) {
        for (int d=f;d<=9;++d) {
            var+=go(l+1,r-1,0,1,0);
        }
    }
    else {
        //if left and right is equal
        int u = in::vi[l];
        int v = in::vi[r];
        if ( u==v ) {
            for (int d=f;d<u;++d) {
                //all smaller
                var+=go(l+1,r-1,0,1,0);
            }
            var+=go(l+1,r-1,0, (s|0)  ,ss);
        }
        else if (u>v) {
            for (int d=f;d<u;++d) {
                //all smaller
                var+=go(l+1,r-1,0,1,0 );
            }
            var+=go(l+1,r-1,0,0,1 );
        }
        else {
            for (int d=f;d<u;++d) {
                var+=go(l+1,r-1,0,1,0);
            }
            var+=go(l+1,r-1,0,0,0);
        }
    }
    return var;
}
Int dp2[20][20];
inline Int go2(int i, int j,int from) {
    if (i>j) {
        return 1LL;
    }
    Int &nways=dp2[i][j];
    if (nways!=-1)return nways;
    nways=0;
    for (int d=from;d<=9;++d) {
        nways+= go2(i+1,j-1,0);
    }
    return nways;
}
inline Int Count(Int p) {

    if (p<0)return 0;
    in::Convert(p);
    int l = SZ(in::vi);
    SET(dp,-1);
    Int ret =go(0,l-1,l==1?0:1,0,0);
//     fo(i,l) {
//         cout<<in::vi[i]<<' ';
//     }
//     debug("RESULT ",ret,"");
    for (int i=1;i<l;++i) {
        SET(dp2,-1);
        ret+=go2(0,i-1,i==1?0:1);
    }
    return ret;
}
inline void Solve() {
    in::Read();
    Int x = Count(in::a-1);
    Int y = Count(in::b);
    cout<<y-x;
    line;
}
#define showcase
int main() {
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
