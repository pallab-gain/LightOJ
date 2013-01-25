/*
 * Author  : Pallab
 * Program : 1119
 *
 * 2012-03-14 17:58:05
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
inline int OR(int msk,int bit) {
    return ( msk|(1<<bit) );
}
inline int AND(int msk, int bit) {
    return ( msk&(1<<bit) );
}
inline int XOR(int msk, int bit) {
    return ( msk&(~(1<<bit)));
}
inline bool marked(int msk, int bit) {
    return ( AND(msk,bit)!=0 );
}
const int inf=1023456789;
int N;
int g[15][15];
inline void Read() {
    CI(N);
    SET(g,0);
    fo(i,N) {
        fo(j,N)CI(g[i][j]);
    }
}
int dp[1<<15];
int go(int msk) {
    if (msk==0)return 0;
    int &best=dp[msk];
    if (best!=-1)return best;
    best=inf;

    fo(i,N) {
        //going to pick I
        if (marked(msk,i)) {
            int localbest=g[i][i];
            //all previously processed jobs ?
            fo(j,N) {
                if (i!=j&&!marked(msk,j)) {
                    localbest+=g[i][j];
                }
            }
            best=min(best,localbest+go( XOR(msk,i)));
        }
    }
    return best;
}
inline void Proc() {
    SET(dp,-1);
    int best=inf;
    fo(i,N) {
        int a= g[i][i]+go( XOR((1<<N)-1,i) );
        best=min(best,a);
    }
    cout<<best;
    line;
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


