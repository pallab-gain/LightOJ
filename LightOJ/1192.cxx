/*
 * Author  : Pallab
 * Program : 1192
 *
 * 2012-01-27 11:12:30
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

int k;
int g;
int w;
int i;
int XOR;
inline void Read() {
    CI(k);
    k<<=1;
    scanf("%d %d",&g,&w);
    XOR = (w-g)-1;
    for (i=2;i<k;i+=2) {
        scanf("%d %d",&g,&w);
        XOR^= (w-g-1);
    }
}
#define A "Alice"
#define B "Bob"
inline void Proc() {
    puts( XOR ? A : B );
}

int main() {

    int t;
    CI(t);
    foE(k,1,t) {
        Read();
        cout<<"Case "<<k<<": ";
        Proc();
    }

    return 0;
}
// kate: indent-mode cstyle; space-indent on; indent-width 0; 
