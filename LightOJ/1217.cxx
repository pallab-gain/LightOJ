/*
 * Author  : Pallab
 * Program : 1217
 *
 * 2012-03-09 11:36:16
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
    mx=1001
};
int sell[mx];
int N;

inline int mod(int i) {
    if (i<0)i+=N;
    return (i%N);
}
inline void Read() {
    CI(N);
    fo(i,N) {
        CI(sell[i]);
    }
}
int taken[mx];
int dp[mx][2];
int go(int at, int k ) {
    //come end of index
    if (at==N)return 0;

    int& best=dp[at][k];
    if (best!=-1)return best;

    best=0;
    // I can sell = YES
    if (taken[at]==0) {
        //-------------------------------
        // sell here
        taken[at]++;
        taken[mod(at-1)]++;
        taken[mod(at+1)]++;
        int v1=sell[at]+go(at+1,1);
        best=max(best,v1);
        taken[at]--;
        taken[mod(at-1)]--;
        taken[mod(at+1)]--;
        //-------------------------------

        //-------------------------------
        //don't sell here
        int v2=go(at+1,0);
        best=max(best,v2);
        //-------------------------------
    }
    //else just move forward
    else {
        int v1=go(at+1,0);
        best=max(best,v1);
    }
    return best;
}

inline void Proc() {
     // take care of index 0 specially
    
    // 0 ke na niye
    SET(dp,-1);
    SET(taken,0);
    int v1=go(1,0);
    
    
    //now 0 ke niye
    SET(dp,-1);
    SET(taken,0);
    taken[0]=1;
    taken[1]=1;
    taken[N-1]=1;
    int v2=sell[0]+go(1,1);
    cout<<max(v1,v2);
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

