/*
 *      ID : pallab81
 *      PROG : 1180
 *      LANG : C++
 *
 *      2012-06-09 18:33:12
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

namespace In {
int npeople;
int msegment;
int timetake[101][2];
inline void read() {
    fastRead(&npeople);
    fastRead(&msegment);
    fo(i,npeople) {
        fo(j,2) {
            fastRead(&timetake[i][j]);
        }
    }
}
}
int dp[101][101][101];
int alocatedTime;
int go(int at, int seg1, int seg2) {
    if (at==In::npeople) {
        return (seg1<=0&&seg2<=0)?1:0;
    }
    int &flag=dp[at][seg1][seg2];
    if (flag!=-1)return flag;
    flag=0;
    for (int i=0;i<=seg1;++i) {
        int nxtSeg1 = seg1-i;
        int timeTake = In::timetake[at][0]*i;
        if (timeTake<=alocatedTime) {
            int timeLeft = alocatedTime-timeTake;
            int nxtSeg2 = seg2- (timeLeft/In::timetake[at][1]);
            if (go(at+1, max(nxtSeg1,0),max(nxtSeg2,0) )) {
                return flag=1;
            }
        }

    }
    return flag=0;
}

inline void Solve() {
    In::read();
    int lo=0;
    int hi=50000;
    int best=hi;
    while (lo<hi) {
        int mid=(lo+hi)>>1;
        alocatedTime=mid;
        SET(dp,-1);
        //debug(In::npeople,totalTime,In::msegment,In::msegment);
        if ( go(0,In::msegment,In::msegment)==1 ) {
            best=min(best,mid);
            hi=mid;
        }
        else {
            lo=mid+1;
        }
    }
    cout<<best;
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
