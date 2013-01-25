/*  KDevelop 4.3.1
 *  1344.cxx
 *
 * 	Author : Pallab
 * 	Created on: 8:20:12 PM - 2012:12:26
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
int N;
vector<int> perls[55];
inline void read() {
    for ( int i=0; i<55; ++i ) perls[i].clear();
    N=fastIn<int>();
    for ( int i=0; i<N; ++i ) {
        for ( int j=0,k=fastIn<int>(); j<k; ++j ) {
            perls[i].push_back ( fastIn<int>() );
        }
    }

}
int dp[55][55][55];
int go ( int at, int l, int r ) {
    if ( l>r ) return 0;
    if ( l==r ) return 1;
    int &bst=dp[at][l][r],L,R;
    if ( bst!=-1 ) return bst;
    set<int>mex;
    for ( int i=l; i<=r; ++i ) {
        L=l;
        int xOR=0;
        for ( int j=l; j<=r; ++j ) {
            if ( perls[at][j]>=perls[at][i] ) {
                xOR^=go ( at, L,j-1 );
                L=j+1;
            } else if ( j==r ) {
                xOR^=go ( at,L,j );
                L=j+1;
            }
        }
        //line;
        mex.insert ( xOR );
    }
    bst=0;
    while ( mex.count ( bst ) >0 ) ++bst;
    return bst;
}
pair<int,int> vi[51*51];
int cnt;
inline void proc() {
    SET ( dp,-1 );
    cnt=0;
    for ( int i=0; i<N; ++i ) {
        set<int> result;
        for ( int j=0,_j=SZ ( perls[i] )-1; j<=_j; ++j ) {
            if ( result.count ( perls[i][j] ) >0 ) continue;
            int l=0,nimvalue=0;
            for ( int k=0; k<=_j; ++k ) {
                if ( perls[i][k]>=perls[i][j] ) {
                    nimvalue^=go ( i,l,k-1 );
                    l=k+1;
                } else if ( k==_j ) {
                    nimvalue^=go ( i,l,k );
                    l=k+1;
                }
            }
            for ( int k=0; k<N; ++k ) {
                if ( i!=k ) nimvalue^=go ( k,0, SZ ( perls[k] )-1 );
            }
            if ( nimvalue==0 ) result.insert ( perls[i][j] );
        }
        for ( set<int> :: iterator it = result.begin() ; it != result.end(); ++it ) {
            vi[cnt++]= make_pair ( i+1,*it ) ;
        }
    }
    if ( cnt==0 ) puts ( "Genie" );
    else {
        puts ( "Aladdin" );
        for ( int i=0; i<cnt; ++i ) cout<<'('<<vi[i].first<<' '<<vi[i].second<<')';
        line;
    }
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



