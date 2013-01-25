/*
 * Author  : Pallab
 * Program : E_again.cxx
 *
 * 2012-01-09 22:06:45
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

inline void wait(double seconds) {
    double endtime = clock()+(seconds * CLOCKS_PER_SEC);
    while (clock() < endtime) {
        ;
    }
}
const Int big = 1000000000000LL;
Int lucky[8190];
set< Int > very;
vector< Int > luckies;
int nlucky;
// generate all lucky numbers
void dfs1(Int num ) {
    if ( num > big )return ;

    lucky[nlucky]= num ;
    ++nlucky;

    dfs1( (num*10 )+4 );
    dfs1( (num*10 )+7 );
}
// generate all very lucky
void dfs2(Int num, int at ) {
    if ( num > 1 ) {
        int sz = SZ( very );
        very.insert( num );
        if ( SZ( very )==sz )return ;
    }
    Int lim = big/num;
    for (int i = at; lucky[i] <= lim && i<nlucky; ++i ) {
        dfs2( num*lucky[i], i );
    }
}
inline void pre() {
    nlucky=0;
    dfs1(4);
    dfs1(7);
    sort( lucky, lucky+nlucky);
    dfs2(1,0);
    foit(it,very) {
        luckies.pb( (*it) );
    }
}
Int lo,hi;
inline void Read() {
    scanf("%lld %lld",&lo,&hi);
}
inline void Proc() {
    int var = upper_bound(luckies.begin(), luckies.end(), hi )-lower_bound(luckies.begin(),luckies.end(), lo);
    cout<<var<<"\n";
}
int main() {
    pre();
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
