/*
 *      ID : pallab81
 *      PROG : 1394
 *      LANG : C++
 *
 *      2012-06-08 14:54:36
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

namespace CONVERT {
inline vector<int> toBin(Int num) {
    vector<int> vi;
    while ( num>0 ) {
        int tmp = num&1 ? 1 : 0 ;
        vi.pb(tmp);
        num>>=1;
    }
    reverse(vi.begin(),vi.end());
    return vi;
}
}

namespace IN {
Int start,end;
Int maxone;
Int idealnum;
Int k;
inline void read() {
    cin>>start>>end>>maxone>>idealnum>>k;
    maxone=min(maxone,33LL);
    k = min(k,33LL);
}
}
namespace CALC {
inline Int give(int at, int mxlen) {
    int times = mxlen-(at+1);
    Int ret=1LL;
    for (int i=1;i<=times;++i) {
        ret<<=1;
    }
    return ret;
}
}
namespace Bucket {
vector<int> idealBin;
vector<int> num;
int mxlen;
inline void fit() {
    while ( SZ(idealBin) < SZ(num) ) {
        idealBin.insert( idealBin.begin(),0 );
    }
    while ( SZ(num) < SZ(idealBin) ) {
        num.insert( num.begin(),0);
    }
    mxlen=SZ(num);
}
}

pair<Int,Int> dp[34][2][34][34][3][7];
bool vis[34][2][34][34][3][7];
pair<Int,Int> go(int at, int smaller, int numone,int k,int mod3, int mod7) {
    if (at==Bucket::mxlen) {
        return (mod3==0&&mod7!=0) ? mk(0,1) : mk(0,0) ;
    }
    if (vis[at][smaller][numone][k][mod3][mod7])return dp[at][smaller][numone][k][mod3][mod7];
    vis[at][smaller][numone][k][mod3][mod7]=true;
    int upto = smaller ? 1 : Bucket::num[at];
    pair<Int,Int> ret=mk(0,0);

    for (int d=0;d<=upto;++d) {
        int nxtsmaller=smaller|(d<Bucket::num[at]?1:0);
        int nxtnumone = numone-d ;
        int nxtk = k-(Bucket::idealBin[at]==d ? 0 : 1);
        if ( nxtnumone >=0 && nxtk>=0 ) {
            Int tmp = CALC::give(at,Bucket::mxlen);
            pair<Int,Int> v = go(at+1,nxtsmaller, nxtnumone, nxtk, (tmp*d+mod3)%3 , (tmp*d+mod7)%7 );
            ret.first+= v.first+tmp*d*v.second;
            ret.second+=v.second;
        }
    }
    dp[at][smaller][numone][k][mod3][mod7]=ret;
    return ret;
}
inline Int Proc(Int curNum) {
    if (curNum<=0)return 0LL;
    SET(vis,false);
    Bucket::num = CONVERT::toBin(curNum);
    Bucket::fit();
//     debug( Bucket::num, Bucket::mxlen );
//     debug( Bucket::idealBin, Bucket::mxlen );
    Int res = go(0,0,IN::maxone,IN::k,0,0).first;
    return res;
}
inline void Solve() {
    IN::read();
    Bucket::idealBin = CONVERT::toBin(IN::idealnum);

    /*
    cout<<IN::start<<" "<<IN::end<<" "<<IN::maxone<<" "<<IN::idealnum<<" "<<IN::k<<" ";
    vector<int> num = CONVERT::toBin(IN::idealnum);
    debug(num,SZ(num));
    */
    Int x = Proc(IN::start-1);
    Int y = Proc(IN::end);
    //debug(y,x,"");
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
