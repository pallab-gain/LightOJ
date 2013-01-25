/*  KDevelop 4.3.1
 *  1348.cxx
 *
 *      Author : Pallab
 *      Created on: 11:23:34 AM - 2013:1:12
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


#define foR(i,frm,upto) for( int i=(frm),_i=(upto);(i) < (_i) ; ++i )
#define foD(i,frm,upto) for( int i=(frm),_i=(upto);(i) >= (_i) ; --i )
#define foit(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
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
const int MX=30005;
vector< int> adj[MX];
int value[MX];
int nodeCount;
#include "LCA.h"
#include "BIT.h"


LCA lca;
BIT<Int> bit;
inline void read() {
    nodeCount=fastIn<int>();
    foR ( i,0,nodeCount ) adj[i].clear();
    foR ( i,0,nodeCount ) {
        value[i]=fastIn<int>();
    }
    foR ( i,1,nodeCount ) {
        int u=fastIn<int>(),v=fastIn<int>();
        adj[u].pb ( v );
        adj[v].pb ( u );
    }
}
inline void proc() {
    lca.initLCA_TABLE();
    lca.dfs ( 0,-1,0,value[0] );
    lca.genLCA();
    bit.init ( lca.getLimit() );

    foR ( i,0,nodeCount ) {
        //lca.printInterval ( i );
        bit.add ( lca.getStart ( i ), lca.getValue ( i ) );
        bit.add ( lca.getEnd ( i ), -lca.getValue ( i ) );
    }
    foR ( i,0,fastIn<int>() ) {
        int t=fastIn<int>(),u=fastIn<int>(),v=fastIn<int>();
        if ( t==0 ) {
            int par = lca.getLCA ( u,v );
            Int v1= bit.get ( lca.getStart ( u ) );
            Int v2= bit.get ( lca.getStart ( v ) );
            Int v3= bit.get ( lca.getStart ( par ) );
            int v4= lca.getValue ( par );
            Int retval = v1+v2 - ( v3*2 ) + v4;
            cout<<retval<<'\n';
        } else {
            bit.add ( lca.getStart ( u ), v- lca.getValue ( u ) );
            bit.add ( lca.getEnd ( u ), lca.getValue ( u )-v );
            lca.setValue ( u,v );
        }
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
        cout<<"Case "<<i<<":\n";
        proc();
    }
    return 0;
}
// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 



