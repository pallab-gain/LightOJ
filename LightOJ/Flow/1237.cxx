/*
 * Author  : Pallab
 * Program : 1237
 *
 * 2012-02-23 20:50:09
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

int n1; // number of person;
int k; // important because (T-K)^2
int G; // impostant because (T-K)^2 > G ? G

int I[50],E[50];
inline void Read() {
    CI(n1);
    CI(k);
    CI(G);
    
    //cout<<"CRAP : "<<n1<<"\n";
    fo(i,n1) {
        CI(I[i]);
    }
    fo(i,n1) {
        CI(E[i]);
    }
}

inline Int two(int xx) {
    return (Int)xx*(Int)xx;
}

const int MAXN = (50+50)+5;
int cost[MAXN][MAXN];
int flow[MAXN][MAXN];
int cap[MAXN][MAXN];
int source,sink;
int n,total_cost;

inline void build_min_cost_flow_network() {
    source = (n1+n1);
    sink = source+1;
    n = n1+n1+2;
    SET(cost,0);
    SET(cap,0);
    for (int i=0;i<n1;++i) {
        for (int j=0;j<n1;++j) {
            if (I[i]>=E[j])continue;
            cap[i][n1+j]=1;
            cost[i][n1+j]= (int)(min((Int)G, two((E[j]-I[i])-k)));
        }
    }
    // source to ever i to n
    fo(i,n1) {
        cap[source][i]=1;
        cost[source][i]=0;
    }
    // every n+i to sink
    fo(i,n1) {
        cap[i+n1][sink]=1;
        cost[i+n1][sink]=0;
    }
}
inline void build_max_cost_flow_network() {
    source = (n1+n1);
    sink = source+1;
    n = n1+n1+2;
    SET(cost,0);
    SET(cap,0);
    for (int i=0;i<n1;++i) {
        for (int j=0;j<n1;++j) {
            if (I[i]>=E[j])continue;

            cap[i][n1+j]=1;
            cost[i][n1+j]=-(int)(min((Int)G, two((E[j]-I[i])-k)));

        }
    }
    // source to ever i to n
    fo(i,n1) {
        cap[source][i]=1;
        cost[source][i]=0;
    }
    // every n+i to sink
    fo(i,n1) {
        cap[i+n1][sink]=1;
        cost[i+n1][sink]=0;
    }
}
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

inline int augment() {
    int dist[MAXN], prev[MAXN];
    bool reach[MAXN];
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

inline int mcmf() {
    int ret, x;
    SET(flow,0);
    ret = total_cost = 0;
    while ((x = augment())) ret += x;
    return ret;
}
inline void Proc() {

    build_min_cost_flow_network();
    int v1=mcmf();
    int tcost1=total_cost;
    build_max_cost_flow_network();
    int v2=mcmf();
    int tcost2=total_cost;
    //cout<<n1<<" "<<v1<<' '<<v2<<' '<<tcost1<<' '<<tcost2<<'\n';
    if (v1<n1||v2<n1) {
        puts("impossible");
    }
    else {
        cout<<tcost1<<' '<<abs(tcost2);
        puts("");
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

}
// kate: indent-mode cstyle; space-indent on; indent-width 0; 
