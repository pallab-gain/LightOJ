/*
*	ID : pallab81
* 	PROG : 1427
* 	LANG : C++
* 	2012-05-28-01.05.58 Monday
*
* 	"I have not failed, I have just found 10000 ways that won't work.
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
    for (int i=0; i<_size; ++i) {
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
inline void wait( double seconds ) {
    double endtime = clock()+( seconds* CLOCKS_PER_SEC );
    while( clock() < endtime ) {
        ;
    }
}
#define maxn 500005
#define charset 26
#define maxw 505
vector<int> E[maxn];
int freq[maxw];
char ss[1000010];
char st[maxw];
int hash[maxw];
struct Node {
    int link[charset];
    int fail;
    int f;
    void Set() {
        SET(link,0);
        fail=f=0;
    }
};
Node trie[maxn];
int cnt,root;
inline void Ini_trie() {
    cnt=1;
    root=cnt++;
    trie[0].Set();
    trie[1].Set();
    fo(i,charset) {
        trie[0].link[i]=root;
    }
}
inline void Addinto_trie(char *in,int k) {
    int now=root;
    for(; *in; ++in) {
        int id=*in-'a';
        if(!trie[now].link[id]) {
            trie[cnt].Set();
            trie[now].link[id]=cnt++;
        }
        now=trie[now].link[id];
    }
    hash[k]=now;
}
inline void build() {
    queue<int> q;
    q.push(root);
    while( !q.empty() ) {
        int t=q.front();
        q.pop();
        for(int i=0; i<charset; i++) {
            int tt=trie[t].link[i];
            int ff=trie[t].fail;
            if(trie[t].link[i]) {
                trie[tt].fail=trie[ff].link[i];
                q.push(tt);
            } else {
                trie[t].link[i]=trie[ff].link[i];
            }
        }
    }
}
inline void AC(char *str) {
    int i=0,cur=root;
    for(; str[i]; i++) {
        int id=str[i]-'a';
        cur=trie[cur].link[id];
        trie[cur].f++;
    }
}
void dfs(int u) {
    freq[u]=trie[u].f;
    foit(it,E[u]) {
        int v= (*it);
        dfs(v);
        freq[u]+=freq[v];
    }
}
inline void Solve() {
    int n;
    //{
    Ini_trie();
    for(int i=0; i<maxn; ++i) {
        E[i].clear();
    }
    CI(n);
    getchar();
    gets(ss);
    fo(i,n) {
        gets(st);
        Addinto_trie(st,i);
    }
    //}
    build();
    for(int i=1; i<cnt; ++i) {
        int f = trie[i].fail;
        E[f].pb(i);
    }
    SET(freq,0);
    AC(ss);
    dfs(root);
    fo(i,n) {
        cout<<freq[hash[i]];
        line;
    }

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","rt",stdin);
#endif
    int tt;
    CI(tt);
    foE(i,1,tt) {
        cout<<"Case "<<i<<":\n";
        Solve();
    }


    return 0;
}
