/*
 * Author  : Pallab
 * Program :1147
 *
 * 2012-03-09 23:01:36
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
template<class T1, class T2>
inline T1 OR(T1 msk,T2 bit) {
    return ( msk|(1LL<<bit) );
}
template<class T1, class T2>
inline T1 AND(T1 msk, T2 bit) {
    return ( msk&(1LL<<bit) );
}
template<class T1, class T2>
inline T1 XOR(T1 msk, T2 bit) {
    return ( msk&(~(1LL<<bit)));
}
template<class T1, class T2>
inline bool marked(T1 msk, T2 bit) {
    return ( AND(msk,bit)!=0 );
}
enum {
    mx=100,
    inf=1023456789
};
int N;
int w[mx];
int sum;
inline void Read() {
    CI(N);
    sum=0;
    fo(i,N) {
        CI(w[i]);
        sum+=w[i];
    }
}
Int dp[100010];
inline void fun(int id) {
    bitset<7> bb(dp[id]);
    cout<<bb;
}
inline void Proc() {
    SET(dp,0);
    dp[0]=1;
    int half=(sum>>1);
    for (int i=0;i<N;++i) {
        for (int j=half-w[i];j>=0;--j) {
            if (dp[j]!=0) {
                dp[j+w[i]]|=(dp[j]<<1);
            }
        }
    }
    int p=(N>>1)+(N&1 ? 1:0);
    for (int i=half;i>=0;--i) {
        if ( marked(dp[i],p) ) {
            int a=i;
            int b=sum-a;
            if (a>b)swap(a,b);
            cout<<a<<' '<<b;
            line;
            break;
        }
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
