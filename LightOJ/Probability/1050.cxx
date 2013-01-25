/*
 *      ID : pallab81
 *      PROG : 1050
 *      LANG : C++
 *
 *      2012-06-02 21:35:50
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
int r,b;
inline void Read() {
    fastRead(&r);
    fastRead(&b);
}
#define me 0
#define he 1
#define win 1
#define lose 0
double dp[505][505][2];
bool V[505][505][2];

double P(int R, int B,int who) {
    if (V[R][B][who])return dp[R][B][who];
    V[R][B][who]=true;
    double ret=0;

    if (R==0&&B==1)return dp[R][B][who]=ret=(who==me ? win : 0);
    if (B==0&&R==1)return dp[R][B][who]=ret=(who==me ? lose : win) ;

    if (who==me) {
        if (B) {
            double a= (((double)B)/(R+B))*( P(R,B-1,he) );
            //ret=max(ret,a);
            ret+=a;
        }
        if (R) {
            double b = (((double)R)/(R+B))*( P(R-1,B,he) );
            //ret=max(ret,b);
            ret+=b;
        }
        return dp[R][B][who]=ret;
    }
    else {
        if (B) {
            ret = P(R,B-1,me);
        }
        return dp[R][B][who]=ret;
    }
    return dp[R][B][who]=ret;
}
inline void Proc() {
    double ret = P(r,b,me);
    cout<<ret;
    line;
}
inline void Solve() {
    Read();
    Proc();
}
int main() {
    cout<<setprecision(8)<<fixed;
    SET(V,false);
    int tt;
    fastRead(&tt);
    foE(i,1,tt) {
        cout<<"Case "<<i<<": ";
        Solve();
    }

    return 0;
}
// kate: indent-mode cstyle; space-indent on; indent-width 0; 
