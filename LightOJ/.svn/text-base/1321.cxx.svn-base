/*
 * Author  : Pallab
 * Program : 1321
 *
 * 2012-03-08 13:28:39
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
#define line puts("")
template<class T>
inline void debug(T _x) {
    cout<<_x<<'\n';
}
template<class T1, class T2>
inline void debug(T1 _x,T2 _y) {
    cout<<_x<<' '<<_y<<'\n';
}
template<class T1, class T2, class T3>
inline void debug(T1 _x,T2 _y,T3 _z) {
    cout<<_x<<' '<<_y<<' '<<_z<<'\n';
}
template<class T1, class T2, class T3, class T4>
inline void debug(T1 _x,T2 _y,T3 _z,T4 _zz) {
    cout<<_x<<' '<<_y<<' '<<_z<<' '<<_zz<<'\n';
}
inline bool CI(int &_x) {
    return scanf("%d",&_x)==1;
}
inline bool CI(int &_x, int &_y) {
    return CI(_x)&&CI(_y) ;
}
inline bool CI(int &_x, int &_y, int &_z) {
    return CI(_x)&&CI(_y)&&CI(_z) ;
}
inline bool CI(int &_x, int &_y, int &_z, int &_zz) {
    return CI(_x)&&CI(_y)&&CI(_z)&&CI(_zz) ;
}

enum {
    mx=105,
    inf=1023456789
};
struct NODE {
    int v;
    double w;
    NODE(int v=0,double w=0):
            v(v),w(w) {
        ;
    }
    bool operator<(const NODE & r)const {
        return w<r.w;
    }
};
vector<NODE>E[mx];
int N,M,S,K;
inline void Read() {
    CI(N,M,S,K);
    //clear
    fo(i,N)E[i].clear();
    int u,v,w;
    fo(i,M) {
        CI(u,v,w);
        E[u].pb(NODE(v, (double)w/100));
        E[v].pb(NODE(u, (double)w/100));
    }
}
double D[mx];
int F[mx];
inline double dj(int src) {
    priority_queue<NODE>pq;
    SET(F,0);
    fill(D,D+mx,0);
    pq.push(NODE(src,1.));
    D[src]=1;
    while (!pq.empty()) {
        int u=pq.top().v;
        double w=D[u];

        pq.pop();
        if (F[u])continue;
        fo(i,SZ(E[u])) {
            int v=E[u][i].v;
            double d=(E[u][i].w)*w;
            if (F[v]==0&&d>D[v]) {
                D[v]=d;
                pq.push(NODE(v,d));
            }
        }
        F[u]=1;
    }

    return D[N-1];
}
inline void Proc() {
    double var=dj(0);
    printf("%.9lf\n", (double)( (double)(K*2)*S)/var);

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
