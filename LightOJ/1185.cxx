/*
 * Author  : Pallab
 * Program : C
 *
 * 2012-03-04 12:22:29
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

inline void debug(int _x) {
    cout<<_x<<'\n';
}
inline void debug(int _x,int _y) {
    cout<<_x<<' '<<_y<<'\n';
}
inline void debug(int _x,int _y,int _z) {
    cout<<_x<<' '<<_y<<' '<<_z<<'\n';
}
inline void debug(int _x,int _y,int _z,int _zz) {
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
    mx=105
};
vector<int> G[mx];
int N;
int E;
inline void Read() {
    CI(N,E);
    fo(i,mx) {
        G[i].clear();
    }
    int u,v;
    fo(i,E) {
        CI(u,v);
        //--u;
        //--v;
        G[u].pb(v);
        G[v].pb(u);
    }
}
int used[mx];
int oddUsed[mx];
int evenUsed[mx];

inline int bfs(int src) {
    SET(used,-1);
    SET(oddUsed,0);
    SET(evenUsed,0);
    queue<pair<int,int> >q;


    q.push( mk(1,0) );
    used[src]=0;

    while (!q.empty()) {
        int u=q.front().first;
        int t=q.front().second;
        q.pop();

        fo(i,SZ(G[u])) {
            int v=G[u][i];
            int nt=(t==0?1:0);

            if (used[v]==-1) {
                used[v]=1;
                q.push( mk(v,nt) );
                if (nt==0) {
                    evenUsed[v]=1;
                }
                else {
                    oddUsed[v]=1;
                }
            }
            else {
                if (nt==0&&evenUsed[v]==0) {
                    evenUsed[v]=1;
                    q.push( mk(v,nt) );
                }
                else if (nt==1&&oddUsed[v]==0) {
                    oddUsed[v]=1;
                    q.push( mk(v,nt));
                }
            }
        }
    }
    int tot=0;
    foE(i,1,N) {
        //debug(i,evenUsed[i],oddUsed[i]);
        if (evenUsed[i])++tot;
    }
    //puts("");
    return tot;
}
inline void Proc() {
    cout<<bfs(1);
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
