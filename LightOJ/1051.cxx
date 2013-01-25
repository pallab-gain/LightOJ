/*
 * Author  : Pallab
 * Program : 1051.cxx
 *
 * 2012-02-05 19:38:08
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

#define CI( x ) scanf("%d",&x)
#define CL( x ) scanf("%lld",&x)
#define CD( x ) scanf("%lf",&x )
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
#define f first
#define s second
#define SET( ARRAY , VALUE ) memset( ARRAY , VALUE , sizeof(ARRAY) )

string line;
inline void Read() {
    cin>>line;
}
int dp[50][5][3][2];


inline int decode(char ch) {
    if ( ch=='?' )return 2;
    return (int)( ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U' );
}

// 2 = '?'
// 1 = vowel
// 0 = consonant

#define _mixed 2
#define _good 1
#define _bad 0

int go(int at, int nc, int nv, int used ) {
    if ( nc==5 || nv==3 ) {
        return _bad;
    }
    if ( at==-1 ) {
        return _good;
    }

    int& ret= dp[at][nc][nv][used];
    if ( ret!=-1 ) {
        return ret;
    }
    if ( decode(line[at])==2 ) {
        // ?
        int a = go( at-1, 0, nv+1, 1 );
        int b = go( at-1, nc+1, 0, 0 );
        if ( a==_good && b==_good ) {
            ret=_good;
            return ret;
        }
        else if ( a==_bad && b==_bad ) {
            ret=_bad;
            return ret;
        }
        else {
            ret = _mixed;
            return ret;
        }
    }
    else if ( decode(line[at]) ==1) {
        int a = go( at-1, 0, nv+1, 1 );
        ret = a;
        return ret ;
    }
    else {
        int a = go( at-1, nc+1, 0, 0 );
        ret = a;
        return ret;
    }
}

inline void Proc() {
    SET(dp,-1);
    int var = go( LN(line)-1, 0, 0 , 0 );
    puts( ( var==_good ? "GOOD" : var==_bad ? "BAD" : "MIXED" ) );
}
int main() {
    int t;
    CI(t);
    foE(i,1,t) {
        Read();
        cout<<"Case "<<i<<": ";
        Proc();
    }
    return 0;
}
// kate: indent-mode cstyle; space-indent on; indent-width 0; 


