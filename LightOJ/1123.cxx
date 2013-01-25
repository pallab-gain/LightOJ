/*
 * Author  : Pallab
 * Program : A
 *
 * 2012-03-03 20:52:04
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

const int inf = (int)201;
int root[ inf+10 ];
int rank[ inf+10 ];
inline void _Set() {
    fo(i,inf) {
        root[i]=i;
        rank[i]=0;
    }
}
inline int _Find(int x) {
    if ( x!= root[x] ) {
        root[x] = _Find(root[x]);
    }
    return root[x];
}
inline void _Union(int x, int y) {
    int rx = _Find(x);
    int ry = _Find(y);

    if ( rank[rx] > rank[ry] ) {
        root[ry] = rx;
    }
    else {
        root[rx] = ry;
    }
    if ( rank[rx]==rank[ry] ) {
        rank[ry]+=1;
    }
}
#define P3 pair<int, pair<int,int> >
set< P3 > st;
int N,E;
inline int mst() {
    int cnt=0;
    _Set();
    int cost=0;
    foit(it,st) {
        if (cnt==N-1)break;
        int c=it->first;
        int u=it->second.first;
        int v=it->second.second;
        if ( _Find(u)!=_Find(v) ) {
            _Union(u,v);
            cost+=c;
            ++cnt;
        }
    }
    if (cnt!=N-1)return -1;
    //debug(N,cnt);
    return cost;
}
inline void solve(int kase) {
    st.clear();
    CI(N,E);
    int u,v,c;
    cout<<"Case "<<kase<<":";
    puts("");
    fo(i,E) {
        CI(u,v,c);
        st.insert( mk(c, mk(u,v) ) );
        cout<<mst();
        puts("");
    }
}
int main() {
    int tt;
    CI(tt);
    foE(i,1,tt) {
        solve(i);
    }

}
