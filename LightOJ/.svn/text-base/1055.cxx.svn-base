/*
 * Author  : Pallab
 * Program : 1055
 *
 * 2012-02-12 19:40:13
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
#define f first
#define s second
#define SET( ARRAY , VALUE ) memset( ARRAY , VALUE , sizeof(ARRAY) )

const int maxn = 10;
char g[maxn][maxn];
int n;

inline void Read() {
    scanf("%d\n",&n);
    fo(i,n) {
        gets( g[i] );
    }
}
struct NODE {
    int ar;
    int ac;
    int br;
    int bc;
    int cr;
    int cc;
    NODE( int ar=0,int ac=0,int br=0,int bc=0,int cr=0,int cc=0)
            : ar(ar),ac(ac),br(br),bc(bc),cr(cr),cc(cc) {
        ;
    }

};
inline NODE _Find() {
    NODE rt;
    fo(i,n) {
        fo(j,n) {
            if ( g[i][j]=='A' ) {
                rt.ar=i;
                rt.ac=j;
            }
            else if ( g[i][j]=='B' ) {
                rt.br = i;
                rt.bc = j;
            }
            else if ( g[i][j]=='C' ) {
                rt.cr = i;
                rt.cc = j;
            }
        }
    }
    return rt;
}
inline vector< pair<int,int> > _Find2() {
    vector< pair<int,int> > vi;
    fo(i,10) {
        fo(j,10) {
            if ( g[i][j]=='X' ) {
                vi.pb( mk(i,j) );
            }
        }
    }
    return vi;
}

const int rr[]={-1,+0,+1,+0};
const int cc[]={+0,+1,+0,-1};
int D[10][10] [10][10] [10][10];
deque< NODE > q;
int inf;

inline void Compile() {
    q.clear();
    SET(D,63);
    inf = D[0][0][0][0][0][0];
    return ;
}

inline bool Nice(int R, int C) {
    if ( R<0 || C<0 || R>=n || C>=n ) {
        return false;
    }
    if ( g[R][C]=='#' )return false;

    return true;
}

inline bool Conflict(int ar, int ac, int br, int bc) {
    return ( ar==br && ac==bc );
}
inline void MOVE( NODE &V, NODE U) {
    if ( !Nice(V.ar,V.ac) ) {
        V.ar=U.ar, V.ac=U.ac ;
    }
    if ( !Nice(V.br,V.bc) ) {
        V.br=U.br, V.bc=U.bc ;
    }
    if ( !Nice(V.cr,V.cc) ) {
        V.cr=U.cr, V.cc=U.cc ;
    }
    if ( Conflict(V.ar,V.ac,V.br,V.bc) ) {
        V.ar=U.ar;
        V.ac=U.ac;
        V.br=U.br;
        V.bc=U.bc ;
    }
    if ( Conflict(V.ar,V.ac,V.cr,V.cc) ) {
        V.ar=U.ar;
        V.ac=U.ac;
        V.cr=U.cr;
        V.cc=U.cc ;
    }
    if ( Conflict(V.br,V.bc,V.cr,V.cc) ) {
        V.br=U.br;
        V.bc=U.bc ;
        V.cr=U.cr;
        V.cc=U.cc ;
    }
}
inline void bfs(NODE P) {
    Compile();
    q.pb( P );
    D[P.ar][P.ac][P.br][P.bc][P.cr][P.cc]=0;

    while ( !q.empty() ) {
        P = q.front();
        q.pop_front();
        fo(i,4) {
            NODE V = NODE( P.ar+rr[i],P.ac+cc[i], P.br+rr[i],P.bc+cc[i],P.cr+rr[i],P.cc+cc[i] );
            MOVE(V,P);
            int _cost = D[P.ar][P.ac][P.br][P.bc][P.cr][P.cc]+1;
            if ( _cost < D[V.ar][V.ac][V.br][V.bc][V.cr][V.cc] ) {
                D[V.ar][V.ac][V.br][V.bc][V.cr][V.cc] = _cost;
                q.push_back( V );
            }
        }
    }
    return ;
}
inline void Proc() {
    NODE P = _Find();
    vector< pair<int,int> > vi = _Find2();
    bfs(P);
    int p[3]={0,1,2};
    int best = inf;
    do {
        int v = D[ vi[p[0]].f ][vi[p[0]].s][vi[p[1]].f][vi[p[1]].s][vi[p[2]].f][vi[p[2]].s];
        best = min( best, v );
    } while ( next_permutation(p,p+3) );

    if ( best<inf ) {
        cout<<best;
        puts("");
    }
    else {
        puts("trapped");
    }

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
