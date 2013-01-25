/*
 * Author  : Pallab
 * Program : 1256_1
 *
 * 2012-05-19 00:33:02
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
inline string fastRead() {
    register char c[33];
    gets(c);
    return (string)c;
}
struct Node {
    int  u;
    int  v;
    string name;
    Node(int u=0,int v=0,string name=""):
            u(u),v(v),name(name) {
        ;
    }
};
int N;
Node  words[1000];
inline void Read() {
    fastRead(&N);
    fo(i,N) {
        words[i].name = fastRead();
        words[i].u = (words[i].name[0]-'a');
        words[i].v = (words[i].name[ LN(words[i].name)-1 ]-'a');
    }
}
int inDegree[27];
int outDegree[27];
int Edges[27][27];
inline void Build() {
    SET(inDegree,0);
    SET(outDegree,0);
    SET(Edges,0);
    fo(i,N) {
        inDegree[ words[i].u ]++;
        outDegree[ words[i].v ]++;
        Edges[ words[i].u ][words[i].v]+=1;
    }
}
inline bool isEular() {
    int cnt=0;
    fo(i,26) {
        int d = abs(inDegree[i]-outDegree[i]);
        if (d==0)continue;
        if (d>1)return false;
        if (d==1)cnt++;
    }
    return cnt<=2 ;
}
bool visited[27];
inline bool isConnected() {
    int u=0;
    fo(i,26) {
        if ( !inDegree[i] && !outDegree[i] )continue;

        if ( inDegree[i]>=outDegree[i] ) {
            u=i;
            if ( inDegree[i]>outDegree[i])break;
        }
    }
    SET(visited,false);
    stack<int> s;
    s.push(u);
    visited[u]=true;
    while (!s.empty()) {
        int f = s.top();
        s.pop();
        fo(i,26) {
            int c = i;
            if ( Edges[f][c]>0 && !visited[c]) {
                visited[c]=true;
                s.push(c);
            }
        }
    }
    fo(i,26) {
        if (inDegree[i] && visited[i]==false)return false;
    }

    return true;
}
bool used[1000];
int path[1000];
void dfs(int now, int &cnt) {
    fo(i,N) {
        if ( words[i].u==now && !used[i]) {
            used[i]=true;
            dfs( words[i].v, cnt);
            path[cnt++]=i;
        }
    }
}
inline void printEular() {
    int u=0;
    fo(i,26) {
        if ( !inDegree[i] && !outDegree[i] )continue;

        if ( inDegree[i]>=outDegree[i] ) {
            u=i;
            if ( inDegree[i]>outDegree[i])break;
        }
    }

    SET(used,false);
    int cnt=0;
    dfs(u,cnt);
    string ret="";
    ret+=words[ path[cnt-1] ].name;
    for (int i=cnt-2;i>=0;--i) {
        ret+=' ';
        ret+=words[ path[i] ].name;
    }
    puts(ret.c_str());

}
inline void Proc() {
    Build();
    if ( isEular()==false || isConnected()==false ) {
        puts("No");
        return ;
    }
    puts("Yes");
    printEular();
}
int main() {
    int tt;
    fastRead(&tt);

    foE(i,1,tt) {
        Read();
        cout<<"Case "<<i<<": ";
        Proc();
    }
    return 0;
}
