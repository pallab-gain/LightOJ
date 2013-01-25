/*
 * Author  : Pallab
 * Program : 1172_2
 *
 * 2012-03-01 07:41:45
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
inline bool isOdd(int bit) {
    return ( (bit&1)!=0 );
}
int R,C,K;
int data[200][200];
inline void Read() {
    CI(R,C,K);
    int ax,ay;
    SET(data,0);
    fo(i,K) {
        CI(ax,ay);
        --ax;
        --ay;
        data[ax][ay]=1;
    }
}
const int rr[]={-2,-2,+2,+2,-1,+1,-1,+1};
const int cc[]={-1,+1,-1,+1,-2,-2,+2,+2};
int board[200][200];
const int MAXN=(200*200)+5;
int white,black;
vector<int>G[MAXN];
inline void build_bpgraph() {
    white=black=0;
    SET(board,0);
    fo(i,R) {
        fo(j,C) {
            if (data[i][j])continue;
            if (isOdd(i+j)) {
                ++black;
                board[i][j]=black;

            }
            else {
                ++white;
                board[i][j]=white;

            }
        }
    }
    fo(i,MAXN)G[i].clear();

    fo(i,R) {
        fo(j,C) {
            if ( data[i][j]||isOdd(i+j))continue;
            int u=board[i][j] ;
            fo(k,8) {
                int tr=i+rr[k];
                int tc=j+cc[k];
                if (tr<0||tc<0||tr>=R||tc>=C)continue;
                if (data[tr][tc])continue;
                int v=board[tr][tc];
                G[u].pb(v);
            }
        }
    }
}
int LL[40002], RR[40002];
int used[40002];

int bpm(int u) {
    if (used[u])
        return 0;
    used[u] = 1;
    fo(i,SZ(G[u])) {
        int v = G[u][i];
        if (RR[v] == -1 || bpm(RR[v])) {
            LL[u] = v;
            RR[v] = u;
            return 1;
        }
    }
    return 0;
}
inline int match() {
    SET(LL,-1);
    SET(RR,-1);
    bool d;
    do {
        d = true;
        SET(used,0);
        for (int u = 1; u <= white; ++u) {
            if (LL[u] == -1 && bpm(u)) {
                d = false;
            }
        }
    } while (!d);
    int r = 0;
    for (int u = 1; u <= white; ++u) {
        if (LL[u] != -1)
            ++r;
    }

    return r;
}
inline void Proc() {
    build_bpgraph();
    int ans = match();
    //debug(white,black,ans);
    cout<<(white+black-ans);
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
