/*
 *  1315.cxx
 *
 * 	Author : Pallab
 * 	Created on: 11:22:31 AM - 2012:12:19
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
const int MX_N=1005;
const int MX_RC=505;
struct node {
    int r,c;
    node() {
        r=c=0;
    }
    node ( int r_,int c_ ) {
        r=r_,c=c_;
    }
    inline void read() {
        r=fastIn<int>(),c=fastIn<int>();
    }
};


int rr[]= {+1,-1,-1,-2,-2,-3};
int cc[]= {-2,-2,-3,-1,+1,-1};

bool memo[MX_RC][MX_RC];
int grundy[MX_RC][MX_RC];

int go ( int r, int c ) {
    if ( memo[r][c] ) return grundy[r][c];

    memo[r][c]=true;
    bitset<10> mex;
    fo ( i,6 ) {
        int tr=r+rr[i],tc=c+cc[i];
        if ( tr<0||tc<0||tr>MX_RC||tc>MX_RC ) continue;
        int tmp=go ( tr,tc );
        mex[ tmp ]=true;
    }

    int retval;
    for ( retval=0; ; ++retval ) {
        if ( mex[retval]==0 ) break;
    }
    grundy[r][c]=retval;
    return retval;
}
int knight_count;
node knights[MX_N];
inline void read() {
    knight_count=fastIn<int>();
    fo ( i,knight_count ) knights[i].read();
}

inline void proc() {
    int retval=0;
    fo ( i,knight_count ) {
        if ( i==0 ) {
            retval=go(knights[i].r,knights[i].c);
        } else {
            retval^=go(knights[i].r,knights[i].c);
        }
    }//cout<<retval<<"\n";
    puts ( ( retval?"Alice":"Bob" ) );
}
int main() {
    SET ( memo,false );
    int kase = 1;
#if defined( xerxes_pc )
    if ( !freopen ( "in1", "r", stdin ) )
        puts ( "error opening file in " ), assert ( 0 );
    kase = 1;
#endif
    
    kase=fastIn<int>();
    foE ( i,1,kase ) {
        read();
        cout<<"Case "<<i<<": ";
        proc();
    }
    return 0;
}

// kate: indent-mode cstyle; indent-width 4; replace-tabs on;
