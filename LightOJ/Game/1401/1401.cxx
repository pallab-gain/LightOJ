/*  KDevelop 4.3.1
 *  1401.cxx
 *
 *      Author : Pallab
 *      Created on: 6:24:58 PM - 2012:12:26
 *      "I have not failed, I have just found 10000 ways that won't work."
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
char grid[105];
int gridLen;
inline void read() {
    gets ( grid );
    gridLen=strlen ( grid );
}
int grundy[3][3][105];
inline int get_grundy ( int p,int len,int nx ) {
    int &retval = grundy[p][nx][len];
    if ( retval!=-1 ) return retval;
    if ( len==0 ) return retval=0;

    set<int>mex;
    for ( int k=1; k<=len; ++k ) {
        if ( ! ( ( k==1&&p==1 ) || ( k==len&&nx==1 ) ) ) {
            int v1=get_grundy ( p,k-1,1 );
            int v2=get_grundy ( 1,len-k,nx );
            mex.insert ( v1^v2 );
        }
        if ( ! ( ( k==1&&p==2 ) || ( k==len&&nx==2 ) ) ) {
            int v1=get_grundy ( p,k-1,2 );
            int v2=get_grundy ( 2,len-k,nx );
            mex.insert ( v1^v2 );
        }
    }
    retval=0;
    while ( mex.count ( retval ) >0 ) ++retval;
    return retval;
}
inline void proc() {
    int p1=0;
    for ( int i=0; i<gridLen; ++i ) {
        if ( grid[i]!='.' ) p1^=1;
    }
    int p2=0;
    for ( int i=0; i<gridLen; ++i ) {
        if ( grid[i]!='.' ) continue;

        int p= ( i-1<0?0:( grid[i-1]=='X'?1:2 ) );
        int j=i;
        while ( j<gridLen&&grid[j]=='.' ) ++j;
        int nx= ( j>=gridLen?0: ( grid[j]=='X'?1:2 ) );
        int len = j-i;
        i=j;
        p2^= get_grundy(p,len,nx);
    }
    if( (!p1 && p2)||(p1&&!p2) )puts("Yes");
    else puts("No");
}
int main() {
    SET ( grundy,-1 );
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
