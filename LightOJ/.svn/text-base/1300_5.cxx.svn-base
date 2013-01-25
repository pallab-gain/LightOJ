/*
 * Author  : Pallab
 * Program : 1300_5
 *
 * 2012-05-18 12:07:47
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

template<class T1>
inline void debug(T1 _x) {
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
template< class T1>
inline void debug(T1 _array,int _size) {
    cout<<"[";
    for (int i=0;i<_size;++i) {
        cout<<' '<<_array[i];
    }
    puts(" ]");
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

#ifdef ONLINE_JUDGE
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#endif
inline void fastRead(int *a) {
    register char c=0;
    while (c<33) c=getchar();
    *a=0;
    while (c>33)
    {
        *a=*a*10+c-'0';
        c=getchar();
    }
}
vector< int> E[10000];
vector< int> tE[10000];
int N,nE;
inline void Read() {

    fastRead(&N);
    fastRead(&nE);
    fo(i,N) {
        E[i].clear();
        tE[i].clear();
    }
    int u,v;
    fo(i,nE) {
        fastRead(&u);
        fastRead(&v);
        E[u].pb(v);
        E[v].pb(u);
        tE[u].pb(v);
        tE[v].pb(u);
    }
}

inline void Remove(int at, int value) {
    for ( vector<int>::iterator it = tE[at].begin(); it!=tE[at].end(); ) {
        if ( (*it)==value ) {
            tE[at].erase(it);
            break;
        }
        else {
            it++;
        }
    }

}
bool used[10000];
int tin[10000];
int fup[10000];
int timer;
inline void dfs(int v, int p = -1) {
    ++timer;
    used[v] = true;
    tin[v] = fup[v] = timer;
    foit(it,E[v]) {
        int to = (*it);
        if (to == p) {
            continue;
        }
        if (used[to]) {
            fup[v] = min (fup[v], tin[to]);
        }
        else {
            dfs (to, v);
            fup[v] = min (fup[v], fup[to]);
            if (fup[to] > tin[v]) {
                Remove(v,to);
                Remove(to,v);
            }

        }
    }
}

inline void find_bridge() {
    timer=0;
    SET(used,false);
    fo(i,N) {
        if (!used[i]) {
            dfs(i);
        }
    }
}
bool cycle[10000];
int explored[10000];
int color[10000];
bool visited[10000];
bool foundCycle;
deque<int> s;
inline void explore(int at,int color_type=1) {
    if (foundCycle)return ;
    explored[at]=1;
    color[at]=color_type;
    foit(it,tE[at]) {
        int v = (*it);
        if ( !explored[v] ) {
            explore(v, color_type^1 );
        }
        else if ( color[at]==color[v] ) {
            foundCycle=true;
            s.clear();
            s.pb(at);
            cycle[at]=visited[at]=true;
            while ( s.empty()==false ) {
                int f = s.back();
                s.pop_back();
                foit(iit,tE[f]) {
                    int c = (*iit);
                    if (!visited[c]) {
                        s.pb(c);
                        cycle[c]=visited[c]=true;
                    }
                }
            }
        }
    }
}
inline void find_cycle() {
    SET(explored,0);
    SET(cycle,false);
    SET(visited,false);

    fo(i,N) {
        if (!explored[i] ) {
            foundCycle=false;
            explore(i);
        }
    }
}

inline void Proc(int kaseno) {

    find_bridge();
    find_cycle();
    cout<<"Case "<<kaseno<<": "<<count(cycle,cycle+N,1);
    line;
}
int main() {

    int tt;
    fastRead(&tt);
    foE(i,1,tt) {
        Read();
        Proc(i);
    }
    return 0;
}


