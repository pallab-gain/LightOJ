/*
 * Author  : Pallab
 * Program : 1176.cxx
 *
 * 2012-02-16 22:11:42
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
#include <deque>
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
#define SET( ARRAY , VALUE ) memset( ARRAY , VALUE , sizeof(ARRAY) )

string ts[]= { "XXL", "XL", "L", "M", "S","XS" };
inline int decode( string s ) {
    fo(i,6) {
        if ( s==ts[i] ) {
            return i;
        }
    }
}

int n,m;
// n color
// m people

const int maxn = 60;
int tot;
int _source;
int _sink;
int cap[maxn][maxn];

inline void Read() {
    CI(n);
    CI(m);
    tot = 6+m ;


    _source=tot;
    _sink = _source+1;
    SET(cap,0);

    string a,b;
    fo(i,m) {
        cin>>a>>b;
        int ci = decode(a);
        int cj = decode(b);
        if ( ci==cj ) {
            cap[ci][ 6+i ]+=1;
        }
        else {
            cap[ci][ 6+i ]+=1;
            cap[cj][ 6+i ]+=1;
        }
    }

    fo(i,6) {
        cap[_source][i]+=n;
    }
    fo(i,m) {
        cap[6+i][_sink]+=1;
    }
}

int used[maxn];
int from[maxn];
inline int bfs(int source, int sink) {
    queue< int > Q;
    SET(used,0);
    SET(from,-1);

    used[ source ]=1;
    Q.push( source );

    while ( !Q.empty() ) {
        int where = Q.front();
        Q.pop();
        for (int next=0;next<=sink;++next) {
            if ( cap[ where][ next ]>0 && !used[next] ) {
                used[ next ]=1;
                from[ next ]=where;
                Q.push( next );
                if ( next==sink ) {
                    goto L;
                }
            }
        }

    }
L :
    ;
    if ( from[ sink ]==-1 ) {
        return 0;
    }

    int where = sink, pathcap = (int)1023456789;
    while ( from[ where ] != -1 ) {
        int prev = from[ where ];
        pathcap = min( pathcap, cap[ prev ][ where ] );
        where = prev;
    }
    where = sink;
    while ( from[ where ] != -1 ) {
        int prev = from[ where ];
        cap[ prev ][ where ]-= pathcap;
        cap[ where][ prev  ]+= pathcap;
        where = prev;
    }

    return 1;

}
inline int maxflow(int source, int sink) {
    int maxf=0;
    while (true) {
        int path_cap = bfs(source, sink );
        if ( path_cap==0 ) {
            break;
        }
        maxf+=path_cap;
    }
    return maxf;
}
inline void Proc() {
    int tf = maxflow( _source, _sink );
    //cout<<"TOTAL FLOW : "<<tf<<"\n";
    puts( tf < m ? "NO" : "YES" );
}
int main() {
    int tt;
    CI(tt);
    foE(i,1,tt) {
        Read();
        cout<<"Case "<<i<<": ";
        Proc();
    }
    return 0;
}
// kate: indent-mode cstyle; space-indent on; indent-width 0; 
