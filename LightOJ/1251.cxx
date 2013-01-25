/*
 * Author  : Pallab
 * Program : 1251
 *
 * 2012-01-23 16:04:51
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


const int MAXN = (8000*2)+5 ; // MAXIMUM NUMBER OF VERTEX / CANDIDATES

// first N YES, last N NO
vector < vector<int> > g, gt;
int candidates,cows;

inline void Read() {
    CI(cows);
    CI(candidates);
    int a,b;
    int u,v;
    int uu,vv;

    // clear
    g.assign( (candidates*2)  ,vector<int>());
    gt.assign( (candidates*2) ,vector<int>());

    fo(i,cows) {
        CI(a);
        CI(b);
        u = abs( a )-1;
        v = abs( b )-1;

        if ( a > 0 ) {
            u = u*2;
            uu = u+1;
        }
        else {
            u = 2*u +1;
            uu= u-1;
        }

        if ( b > 0 ) {
            v = v*2;
            vv= v+1;
        }
        else {
            v = 2*v +1;
            vv= v-1;
        }
        g[u].pb(vv);
        gt[vv].pb(u);

        g[v].pb(uu);
        gt[uu].pb(v);
    }

}

int used[MAXN];
int order[MAXN];
int id[MAXN];
int cnt;
int ID;
void dfs1(int u) {
    used[u]=1;
    fo(i,SZ(g[u])) {
        int v = g[u][i];
        if (!used[v] ) {
            dfs1( v );
        }
    }
    order[cnt++]=u;
}
void dfs2(int u) {
    used[u]=true;
    id[u] = ID;
    fo(i,SZ(gt[u])) {
        int v = gt[u][i];
        if (!used[v])
            dfs2(v);
    }
}
inline void SCC() {
    SET(used,0);
    cnt=0;
    fo(i,2*candidates) {
        if (!used[i])
            dfs1(i);
    }
    SET(used,0);
    ID=0;
    for (int i=cnt-1;i>=0;--i) {
        if (!used[ order[i] ] ) {
            ++ID;
            dfs2( order[i] );
        }
    }
}

inline bool SAT_JUDGE() {
    for (int i=0,j=2*candidates;i<j;i+=2) {
        if ( id[i]==id[i+1] )
            return false;
    }
    return true;
}

inline void Proc() {

    SCC();
    if (!SAT_JUDGE()) {
        cout<<"No\n";
        return ;
    }
    int tot=0;
    for (int i=0,j=2*candidates;i<j;i+=2) {
        if ( id[i] > id[i+1] ) {
            //cout<<'?';
        }
        else {
            //cout<<'Y';
            ++tot;
        }

    }
    cout<<"Yes\n"<<tot;
    if (tot) {
        for ( int i=0,j=2*candidates,k=1;i<j;i+=2,++k) {
            if (id[i]<=id[i+1])
                cout<<' '<<k;
        }
    }
    cout<<'\n';
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







