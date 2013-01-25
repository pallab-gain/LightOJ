/*  KDevelop 4.3.1
 *  1162.cxx
 *
 * 	Author : Pallab
 * 	Created on: 4:02:32 PM - 2013:1:11
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
const int MXN= ( int ) 1e5+5;
int nodeCount;
#include "LCA.h"
//FOR submitting in online_judge 
//add LCA class here
LCA lca;
inline void read() {
    nodeCount=fastIn<int>();
    lca.initGraph ( nodeCount );
    int u,v,w;
    foR ( i,1,nodeCount ) {
        u=fastIn<int>()-1,v=fastIn<int>()-1,w=fastIn<int>();
        lca.addEdge ( u,v,w );
    }
}
inline void proc() {
    lca.initLCA_TABLE();
    lca.dfs ( 0,-1,0,0 );

    lca.genLCA();
    int queryCount=fastIn<int>(),u,v,root,Mval,mval;
    foR ( i,0,queryCount ) {
        u=fastIn<int>()-1,v=fastIn<int>()-1;
        root=lca.getLCA ( u,v );
        Mval = max ( lca.getMaxDist ( u,root ), lca.getMaxDist ( v,root ) );
        mval = min ( lca.getMinDist ( u,root ), lca.getMinDist ( v,root ) );

        cout<<mval<<' '<<Mval<<'\n';
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



