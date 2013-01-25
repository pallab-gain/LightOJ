/*
 *  1193.cxx
 *
 * 	Author : Pallab
 * 	Created on: 10:09:43 AM - 2012:12:19
 * 	"I have not failed, I have just found 10000 ways that won't work."
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
#include <numeric>
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

inline void wait ( double seconds ) {
    double endtime = clock() + ( seconds * CLOCKS_PER_SEC );
    while ( clock() < endtime ) {
        ;
    }
}
template<class T>
    inline T fastIn() {
    register char c=0;
    register T a=0;
    bool neg=false;
    while ( c<33 ) c=getchar();
    while ( c>33 ) {
        if ( c=='-' ) {
            neg=true;
        } else {
            a= ( a*10 ) + ( c-'0' );
        }
        c=getchar();
    }
    return neg?-a:a;
}
const int UPTO_X=10005;
const int SIZE_X=105;

int pile_count;
int cell_count[SIZE_X];

int marked[UPTO_X];
int grundy[UPTO_X];
inline void compute_grundy ( int upto ) {
    grundy[0]=0;
    grundy[1]=0;
    grundy[2]=0;

    int p,q,tmp;
    SET ( marked,-1 );
    for ( int i=3; i<=upto; ++i ) {
        p=1,q=i-1;
        while ( q>p ) {
            tmp = grundy[p]^grundy[q];
            marked[tmp]=i;
            ++p,--q;
        }

        for ( tmp=0; ; ++tmp ) {
            if ( marked[tmp]!=i ) {
                grundy[i]=tmp;
                break;
            }
        }
    }
}
inline void read() {
    pile_count=fastIn<int>();
    fo ( i,pile_count )
    cell_count[i]=fastIn<int>();
}
inline void proc() {
    int res;
    fo ( i,pile_count ) {
        if ( i==0 ) {
            res=grundy[ cell_count[i] ];
        } else {
            res=res^grundy[ cell_count[i] ];
        }
    }

    //res = 0 P-position
    //res = 1 N-position
    puts ( ( res?"Alice":"Bob" ) );
}
int main() {
    int kase = 1;
#if defined( xerxes_pc )
    if ( !freopen ( "in1", "r", stdin ) )
        puts ( "error opening file in " ), assert ( 0 );
    kase = 1;
#endif

    compute_grundy ( UPTO_X-1 );

    kase=fastIn<int>();
    foE ( i,1,kase ) {
        read();
        cout<<"Case "<<i<<": ";
        proc();
    }
    return 0;
}
// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
