/*
 * Author  : Pallab
 * Program : 1041
 *
 * 2012-03-07 16:26:55
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

const int inf = (int)55;
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

int N;
map<string,int> mp;
struct node {
    int u;
    int v;
    int w;
    node(int u=0,int v=0,int w=0):
            u(u),v(v),w(w) {
        ;
    }
};
inline bool cmp1(node A, node B) {
    return A.w<B.w;
}
vector< node > vi;
int cnt;
inline void Read() {
    CI(N);
    vi.clear();
    mp.clear();
    string s[3];
    _Set();

    int w;
    cnt=0;
    fo(i,N) {
        cin>>s[1]>>s[2]>>w;
        int id1,id2;
        if (mp.count(s[1])) {
            id1=mp[s[1]];
        }
        else {
            id1=mp[s[1]]=cnt;
            ++cnt;
        }
        if (mp.count(s[2])) {
            id2=mp[s[2]];
        }
        else {
            id2=mp[s[2]]=cnt;
            ++cnt;
        }
        vi.pb( node(id1,id2,w) );

    }
}
inline void Proc() {
    int sz=SZ(vi);
    int cost=0;
    sort(vi.begin(),vi.end(), cmp1);
    int i,k;
    for (i=k=0;i<sz&&k!=(cnt-1);++i) {
        int u=vi[i].u;
        int v=vi[i].v;
        int w=vi[i].w;
        if (_Find(u)!=_Find(v)) {
            ++k;
            cost+=w;
            _Union(u,v);
        }
    }
    if (k!=(cnt-1)) {
        puts("Impossible");
    }
    else {
        cout<<cost;
        line;
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
