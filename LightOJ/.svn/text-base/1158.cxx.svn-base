/*
 * Author  : Pallab
 * Program : 1158
 *
 * 2012-03-16 18:31:30
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
int d;
string s;
int vi[13];
int cnt;

inline void Read() {
    cin>>s>>d;
    cnt=0;

    fo(i,LN(s)) {
        vi[cnt]= (s[i]-'0');
        ++cnt;
    }
}

Int dp[1<<10][1002];
Int go(int msk, int m) {
    if (msk==0) {
        return m==0 ? 1LL : 0LL;
    }
    Int &ways=dp[msk][m];
    if (ways!=-1)return ways;

    ways=0;
    fo(i,cnt) {
        if (AND(msk,i)) {
            int a=go(XOR(msk,i),((m*10)+vi[i])%d);
            ways+=a;
        }
    }
    return ways;
}
int repeat[10];
Int fact[20];
inline void findFactorials(int upto) {
    fact[0]=fact[1]=1;
    for (int i=2;i<=upto;++i) {
        fact[i]=(fact[i-1]*i);
    }
}

inline Int fun() {
    SET(repeat,0);
    fo(i,cnt) {
        repeat[vi[i]]++;
    }
    Int ret=1;
    fo(i,10) {
        ret*= fact[ repeat[i] ];
    }
    return ret;
}
inline void Proc() {
    SET(dp,-1);
    int n= (1<<cnt);
    Int var=go( n-1 , 0);
    cout<<var/fun();
    line;
}
int main() {
    //debug( sizeof(dp)/1024/1024 );
    findFactorials(11);
    int tt;
    CI(tt);
    foE(i,1,tt) {
        Read();
        cout<<"Case "<<i<<": ";
        Proc();
    }
    return 0;
}
