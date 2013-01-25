/*
 * Author  : Pallab
 * Program : L
 *
 * 2012-02-21 13:20:18
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

const int MAXN = (50+50)+5;
int cap[MAXN][MAXN], flow[MAXN][MAXN], cost[MAXN][MAXN];
int n, sink, source, total_cost;

inline int cf(int i, int j) {
    if (flow[j][i]) return flow[j][i];
    else return cap[i][j] - flow[i][j];
}

inline int costf(int i, int j) {
    if (flow[j][i]) return -cost[j][i];
    else return cost[i][j];
}

inline void pushf(int i, int j, int x) {
    total_cost += costf(i, j) * x;
    if (flow[j][i]) flow[j][i] -= x;
    else flow[i][j] += x;
}
int dist[MAXN], prev[MAXN];
bool reach[MAXN];
inline int augment(void) {
    bool changed;
    int i, j;
    SET(reach,0);
    reach[source] = changed = true;
    dist[source] = 0;
    while (changed) {
        changed = false;
        fo(i,n) {
            if (reach[i]) {
                fo (j,n) {
                    if (cf(i, j)) {
                        if (!reach[j] || dist[i] + costf(i, j) < dist[j]) {
                            reach[j] = changed = true;
                            dist[j] = dist[i] + costf(i, j);
                            prev[j] = i;
                        }
                    }
                }
            }
        }
    }
    if (!reach[sink]) return 0;
    for (i = sink; i != source; i = prev[i]) pushf(prev[i], i, 1);
    return 1;
}

int mcmf(void) {
    int ret, x;
    SET(flow,0);
    ret = total_cost = 0;
    while ((x = augment())) ret += x;
    return ret;
}

inline void Read() {
    int m;
    CI(m);
    n=m;

    source=n+m;
    sink=n+m+1;

    SET(cap,0);
    SET(cost,0);
    fo(i,n) {
        fo(j,m) {
            int tmp;
            CI(tmp);
            tmp=-tmp;
            cap[i][n+j]=1;
            cost[i][n+j]=tmp;
        }
    }
    fo(i,n) {
        cap[source][i]=1;
        cost[source][i]=0;
    }
    fo(j,m) {
        cap[n+j][sink]=1;
        cost[n+j][sink]=0;
    }

    n=n+m+2;
}
inline void Proc() {
    mcmf();
    cout<< abs(total_cost);
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
