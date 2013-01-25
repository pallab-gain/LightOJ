/*
 * Author  : Pallab
 * Program : 1253.cxx
 *
 * 2012-01-27 01:35:39
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


int n;
int p;
int one;
int jor;
inline void Read() {
    CI(n);
    CI(p);
    jor = p;
    one = p==1 ? 1 : 0 ;

    foR(i,1,n) {
        CI(p);
        jor ^= p ;
        if (p==1)++one;
    }
}
inline void Proc() {

    if ( one==n ) {
        puts( jor==1 ? "Bob" : "Alice" );
    }
    else {
        puts( jor==0 ? "Bob" : "Alice" ) ;
    }
}
int main() {
    int T;
    CI(T);
    foE(i,1,T) {
        Read();
        cout<<"Case "<<i<<": ";
        Proc();
    }

    return 0;
}
// kate: indent-mode cstyle; space-indent on; indent-width 0; 



