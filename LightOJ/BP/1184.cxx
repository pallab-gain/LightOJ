/*
 * Author  : Pallab
 * Program : 1184
 *
 * 2012-02-25 19:01:10
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

struct T {
    int height;
    int age;
    int div;
    T(int height,int age,int div):
            height(height),age(age),div(div) {
        ;
    }
};

vector< T > male,female;
int N,M;
inline void Read() {
    male.clear();
    female.clear();
    CI(N);
    CI(M);
    fo(i,N) {
        int h,a,d;
        CI(h);
        CI(a);
        CI(d);
        male.pb(T(h,a,d));
    }
    fo(i,M) {
        int h,a,d;
        CI(h);
        CI(a);
        CI(d);
        female.pb(T(h,a,d));
    }
}
inline bool goodMatch(T a, T b) {
    if ( abs(a.height-b.height)>12 )return false;
    if ( abs(a.age-b.age)>5 )return false;
    if ( a.div!=b.div )return false;
    return true;
}
const int maxn=50+50+2;
vector<int>g[maxn];
inline void build_bpnetwork() {
    fo(i,N+M) {
        g[i].clear();
    }
    fo(i,N) {
        fo(j,M) {
            if (goodMatch(male[i],female[j])) {
                g[i].pb(N+j);
            }
        }
    }
}
int used[maxn];
int mt[maxn];

int try_kuhn(int v) {
    if (used[v])return 0;
    used[v]=1;
    fo(i,SZ(g[v])) {
        int to=g[v][i];
        if (mt[to]==-1||try_kuhn(mt[to])) {
            mt[to]=v;
            return 1;
        }
    }
    return 0;
}
inline int match() {
    build_bpnetwork();
    SET(mt,-1);
    fo(i,N+M) {
        SET(used,0);
        try_kuhn(i);
    }
    int d=0;
    fo(i,N+M) {
        if (mt[i]!=-1)++d;
    }
    return d;
}
inline void Proc() {
    cout<<match();
    puts("");
}
int main() {
    int tt;
    CI(tt);
    foE(i,1,tt) {
        Read();
        cout<<"Case "<<i<<": ";
        Proc();
    }

}
// kate: indent-mode cstyle; space-indent on; indent-width 0; 
