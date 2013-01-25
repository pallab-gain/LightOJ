/*
 * Author  : Pallab
 * Program : 1152
 *
 * 2012-02-26 10:06:13
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

int R,C;
char grid[20][20];
int maper[20][20];
int id;
int cnt;
inline void Read() {
    CI(R);
    CI(C);
    cnt=0;
    fo(i,R) {
        fo(j,C) {
            cin>>grid[i][j];
        }
    }

    SET(maper,0);
    id=0;
    fo(i,R) {
        fo(j,C) {
            maper[i][j]=id++;
        }
    }
}

int rr[]={-1,+1,+0,+0};
int cc[]={+0,+0,-1,+1};
const int maxn=(20*20);
vector<int>g[maxn];

inline void build_bpnetwork() {
    fo(i,id)g[i].clear();
    fo(i,R) {
        fo(j,C) {
            if (grid[i][j]=='*') {
                ++cnt;
                fo(k,4) {
                    int tr=i+rr[k];
                    int tc=j+cc[k];
                    if (tr<0||tc<0||tr>=R||tc>=C)continue;
                    if (grid[tr][tc]=='*') {
                        int u=maper[i][j];
                        int v=maper[tr][tc];
                        g[u].pb(v);
                    }
                }
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
    fo(i,id) {
        SET(used,0);
        try_kuhn(i);
    }
    int d=0;

    fo(i,id) {
        if (mt[i]!=-1) {
            ++d;
        }
    }
    //cout<<d<<' '<<cnt<<'\n';
    return (cnt-(d>>1));
}
inline void Proc() {
    int ret=match();
    cout<<ret;
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

