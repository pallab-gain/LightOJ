/*  KDevelop 4.3.1
 *  1393.cxx
 *
 * 	Author : Pallab
 * 	Created on: 10:41:49 AM - 2012:12:31
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
    while ( c<33 ) c=getchar();
    while ( c>33 ) {
        a= ( a*10 ) + ( c-'0' );
        c=getchar();
    }
    return a;
}
inline void read() {}
int R,C;
inline void proc() {
    bool nimValue=0;
    R=fastIn<int>(),C=fastIn<int>();
    int total = R+C,i,j,k,v;
    for ( i=1; i <= R; ++i ) {
        k=(--total);
        for ( j=1; j <= C; ++j) {
            --k;
            v=fastIn<int>();
            if ( k & 1 ) {
                nimValue^= (v?true :false);
            }
        }
    }
    puts ( ( nimValue ? "win":"lose" ) );
}
int main() {
    int kase = 1;
#if defined( xerxes_pc )
    freopen ( "in1", "r", stdin );
    kase = 1;
#endif
    kase=fastIn<int>();
    for ( int i=1; i<=kase; ++i ) {
        read();
        cout<<"Case "<<i<<": ";
        proc();
    }
    return 0;
}

// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
