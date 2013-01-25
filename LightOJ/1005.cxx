//	 ID : pallab81
// 	PROG : 1005
// 	LANG : C++
// 	2011-10-13-13.48.47 Thursday
//
// 	"I have not failed, I have just found 10000 ways that won't work.
//


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

#include <ctime>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cstring>

using namespace std;

#define fo(i,ed) for(int i = 0 ; i < ed ; ++i )
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

inline void wait( double seconds ){
    double endtime = clock()+( seconds* CLOCKS_PER_SEC );
    while( clock() < endtime ){
        ;
    }
}


int N,K;
Int dp[31][31*31];

inline Int go(int c, int k, Int m){
    if( k==0 ){
        return (Int)1;
    }
    if( c==N ){
        return (Int)0;
    }


    Int &ncount=dp[c][k];
    if( ncount!=-1 ){
        return ncount;
    }
    ncount=0;
    //bosaiye
    fo(i,N){
        if( ( m&(1<<i) ) == 0 ){
                Int var = go(c+1, k-1, ( m|(1<<i) ) );
                ncount+=var;
        }
    }
    //na bosaiye
    Int var = go(c+1,k,m);
    ncount+=var;
return ncount;
}
int main(){
//	#ifndef ONLINE_JUDGE
//		freopen("in","rt",stdin);
//	#endif

    int cases=1,kase=1;
    for( scanf("%d",&cases) ; cases ; --cases,++kase ){
            scanf("%d %d",&N,&K);
            SET(dp,-1);
            Int var = go(0,K,0);
            printf("Case %d: %lld\n",kase,var);
    }
return 0;
}
