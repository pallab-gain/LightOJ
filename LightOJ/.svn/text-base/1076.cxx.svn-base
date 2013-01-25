/*
*	ID : pallab81
* 	PROG : 1076
* 	LANG : C++
* 	2012-05-01-07.11.00 Tuesday
*
* 	"I have not failed, I have just found 10000 ways that won't work.
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
    for (int i=0; i<_size; ++i) {
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
inline void wait( double seconds ) {
    double endtime = clock()+( seconds* CLOCKS_PER_SEC );
    while ( clock() < endtime ) {
        ;
    }
}
int N,M;
Int numbers[1010];
Int mn;
inline void Read() {
    CI(N,M);
    mn=-1;
    fo(i,N) {
        int x;
        CI(x);
        numbers[i]= (Int)x;
        mn=max(mn,numbers[i]);
    }
}
inline bool Possible(int var) {
    if (var<mn)return false;
    int tcal=0;
    for (int i=0;i<N; ) {
        Int cur=0;
        int called=0;
        for ( ; i<N ; ) {
            called=1;
            if ( cur+numbers[i] <=var ) {
                cur+=numbers[i];
                ++i;
            }
            else {
                break;
            }
        }
        tcal+=called;
    }
    return tcal<=M;
}
inline void Proc() {
    
    Int lo=mn;
    Int best,hi=4000000000LL;
    best=hi;
    while(lo+1<hi){
        Int mid = (lo+hi)/2 ;
        if ( Possible(mid)) {
            hi=mid;
            best=min(best,mid);
        }
        else {
            lo=mid;
        }
    }
    for(Int i=lo;i<=hi;++i){
      if(Possible(i))best=min(best,i);
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
    return 0;
}

