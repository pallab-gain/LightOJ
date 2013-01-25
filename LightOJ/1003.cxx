
/*
 * Author  : Pallab
 * Program : 1003
 *
 * 2012-01-24 14:01:34
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

const int MAXN = (10000>>1)+2;
int ID;
vector< int > E[MAXN];
map<string,int> maped;

inline int getId(string &s ) {
    if ( maped.count(s) ) {
        return maped[s];
    }
    ++ID;
    maped[s]=ID;

    return ID;
}
int n;
inline void Read() {

    CI(n);
    maped.clear();
    fo(i,MAXN) {
        E[i].clear();
    }
    ID=0;
    string s1,s2;
    fo(i,n) {
        cin>>s1>>s2;
        E[ getId(s2) ].pb( getId(s1) );
    }
}
int cycle_st;
int cl[MAXN];

bool dfs( int v ) {
    cl[v]=1;
    fo(i,SZ(E[v])) {
        int to = E[v][i];
        if ( cl[to]==0 ) {
            if ( dfs(to) )return true;
        }
        else if ( cl[to]==1 ) {
            cycle_st = to;
            return true;
        }
    }
    cl[v]=2;
    return false;
}
inline void Proc() {
    SET(cl,0);
    cycle_st=-1;

    foE(i,1,ID) {
        if (dfs(i)) {
            break;
        }
    }

    cout<<(cycle_st==-1 ? "Yes":"No" )<<"\n";

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
