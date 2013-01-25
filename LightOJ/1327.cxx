/*
 *       ID : pallab81
 *       PROG : 1327
 *       LANG : C++
 *
 *       2012-06-01 08:36:11
 *       "I have not failed, I have just found 10000 ways that won't work.
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
inline void debug ( T1 _x ) {
    cout<<_x<<'\n';
}
template<class T1, class T2>
inline void debug ( T1 _x,T2 _y ) {
    cout<<_x<<' '<<_y<<'\n';
}
template<class T1, class T2, class T3>
inline void debug ( T1 _x,T2 _y,T3 _z ) {
    cout<<_x<<' '<<_y<<' '<<_z<<'\n';
}
template<class T1, class T2, class T3, class T4>
inline void debug ( T1 _x,T2 _y,T3 _z,T4 _zz ) {
    cout<<_x<<' '<<_y<<' '<<_z<<' '<<_zz<<'\n';
}
template< class T1>
inline void debug ( T1 _array,int _size ) {
    cout<<"[";
    for ( int i=0; i<_size; ++i ) {
        cout<<' '<<_array[i];
    }
    puts ( " ]" );
}

inline void fastRead ( int *a ) {
    register char c=0;
    while ( c<33 ) c=getchar_unlocked();
    *a=0;
    while ( c>33 ) {
        *a=*a*10+c-'0';
        c=getchar_unlocked();
    }
}
inline string fastRead() {
    register char c[33];
    gets ( c );
    return ( string ) c;
}
inline bool CI ( int &_x ) {
    return scanf ( "%d",&_x ) ==1;
}
inline bool CI ( int &_x, int &_y ) {
    return CI ( _x ) &&CI ( _y ) ;
}
inline bool CI ( int &_x, int &_y, int &_z ) {
    return CI ( _x ) &&CI ( _y ) &&CI ( _z ) ;
}
inline bool CI ( int &_x, int &_y, int &_z, int &_zz ) {
    return CI ( _x ) &&CI ( _y ) &&CI ( _z ) &&CI ( _zz ) ;
}
inline void wait ( double seconds ) {
    double endtime = clock() + ( seconds* CLOCKS_PER_SEC );
    while ( clock() < endtime ) {
        ;
    }
}
inline int OR ( int msk,int bit ) {
    return ( msk| ( 1<<bit ) );
}
inline int AND ( int msk, int bit ) {
    return ( msk& ( 1<<bit ) );
}
inline int XOR ( int msk, int bit ) {
    return ( msk& ( ~ ( 1<<bit ) ) );
}
inline bool marked ( int msk, int bit ) {
    return ( AND ( msk,bit ) !=0 );
}

#define no 0
#define yes 1
#define super 2

int N;//number of dresses and pair of shoes
int g[16][16];
inline void Read() {
    fastRead ( &N );
    fo ( i,N ) {
        fo ( j,N ) {
            fastRead ( &g[i][j] );
        }
    }
}
Int dp[1<<15][2][2];
inline Int go ( int at,int msk,int all, int sMatch ) {
    if ( at==N ) {
        return ( all || sMatch ) ? 1 : 0 ;
    }
    Int &nway=dp[msk][all][sMatch];
    if ( nway!=-1 ) return nway;
    nway=0;
    fo ( i,N ) {
        if ( marked ( msk,i ) ==false ) {
            nway+= go ( at+1, OR ( msk,i ), all& ( g[at][i]==yes ) , sMatch| ( g[at][i]==super ) );
        }
    }
    return nway;
}

inline void Solve() {
    Read();
    //without any supermatch
    SET ( dp,-1 );
    Int var = go ( 0,0,1,0 );
    cout<<var;
    line;
}
int main() {

    int tt;
    fastRead ( &tt );
    foE ( i,1,tt ) {
        cout<<"Case "<<i<<": ";
        Solve();
    }

    return 0;
}
// kate: indent-mode cstyle; space-indent on; indent-width 4; 
