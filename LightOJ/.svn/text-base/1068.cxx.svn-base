/*
 * Author  : Pallab
 * Program : 1068
 *
 * 2012-03-06 09:00:23
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
#define line puts("")
int a,b;
int k;
inline void Read() {
    CI(a,b,k);
}
int numbers[12];
int cnt;
int dp[12][2][82][82];
int go(int at,int smaller,int m1, int m2) {
    if (at==cnt) {
        return (m1==0 && m2==0 ? 1 : 0 );
    }

    int &nway=dp[at][smaller][m1][m2];
    if (nway==-1) {
        nway=0;
        int to = smaller==0 ? numbers[at] : 9;
        for (int d=0;d<=to;++d) {
            int nxtsmaller=smaller|(d<numbers[at] ? 1 : 0);
            nway+=go(at+1,nxtsmaller,(m1+d)%k,((m2*10)+d)%k );
        }

    }
    return nway;
}
inline int howmany(int number) {
    if (k>82)return 0;
    SET(dp,-1);
    cnt=0;
    while (number>0) {
        int mod=number%10;
        number/=10;
        numbers[cnt++]=mod;
    }
    reverse(numbers,numbers+cnt);
    return go(0,0,0,0);
}
inline void Proc() {
    cout<< howmany(b)-howmany(a-1) ;
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

}
