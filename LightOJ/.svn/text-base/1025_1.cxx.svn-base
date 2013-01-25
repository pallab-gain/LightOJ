/*
 * Author  : Pallab
 * Program : 1025
 *
 * 2011-12-03 17:55:34
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
#define foR(i,st,ed) for(int i = st ; i < ed ; ++i )
#define fo(i,ed) foR( i , 0 , ed )
#define foE(i,st,ed) for(int i = st ; i <= ed ; ++i )
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

char line[61];
int len;
Int dp[60][60];
int vis[60][60];

inline void Read() {
    cin>>line;
    len = LN(line);
}

inline Int go(int st,int ed) {
    if ( st > ed ) {
        return 0;
    }

    if ( vis[st][ed]!=-1 ) {
        return dp[st][ed];
    }
    vis[st][ed]=0;
    Int d = 0;
    d+=go(st+1,ed);
    d+=go(st,ed-1);
    d-=go(st+1,ed-1);
    if ( line[st]==line[ed] ) {
        d+= (1+go(st+1,ed-1));
    }
    return dp[st][ed]=d;
}

inline void Proc() {
    SET(vis,-1);
    Int v = go(0,len-1);
    cout<<v<<"\n";
}
int main() {
    int t;
    cin>>t;
    for (int i=1;i<=t;++i) {
        Read();
        cout<<"Case "<<i<<": ";
        Proc();
    }


    return 0;
}

// kate: indent-mode cstyle; space-indent on; indent-width 0; 

