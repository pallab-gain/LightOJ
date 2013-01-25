/*
 * Author  : Pallab
 * Program : 1138
 *
 * 2012-05-02 12:02:14
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

//number of tailing zero in (number!)
//all numbers are in decimal base
template<class T>
inline T tailingZero(T number) {
    T zero=(T)0;
    for (T i=(T)5; i<=number; i*= (T)5 ) {
        zero+= (T)(number/i);
    }
    return zero;
}

inline bool long_overflow(long long a , long long b, string com) {
    unsigned long long max_value = (1ULL<<63)-1;
    if (com=="plus") {
        return ( a > (max_value-b) ) ;
    }
    else {
        assert(b!=0);
        return ( a > (max_value/b) );
    }
}

inline void Proc(int kaseno) {
    Int x;
    scanf("%lld",&x);
    cout<<"Case "<<kaseno<<": ";
    Int lo=0;
    Int hi=(Int)1e30;
    Int ret=0;
    bool found=false;
    while (lo+100<hi) {
        Int pivot = (lo+hi)>>1;
        assert( long_overflow(hi,lo,"plus")==false );
        Int zero= tailingZero<Int>(pivot);
        if (  zero >= x ) {
            hi=pivot;
            if (zero==x) {
                if (found==false) {
                    found=true;
                    ret=hi;
                }
                else {
                    ret=min(ret,hi);
                }
            }
        }
        else {
            lo=pivot;
        }
    }
    for (Int i=lo;i<=hi;++i) {
        if ( tailingZero<Int>(i)==x) {
            if (!found) {
                found=true;
                ret=i;
            }
            else {
                ret=min(ret,i);
            }
        }
    }
    if (!found) {
        cout<<"impossible";
        line;
    }
    else {
        cout<<ret;
        line;
    }
}
int main() {
    int tt;
    CI(tt);
    foE(i,1,tt) {
        Proc(i);
    }
    return 0;
}
