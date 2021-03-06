/*
 * Author  : Pallab
 * Program : 1102
 *
 * 2012-05-08 22:44:29
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

const Int mod=1000000007;
inline Int domod(Int val){
  if(val<0)val+=mod;
  return val%mod;
}

struct Triple {
    Int d;
    Int x;
    Int y;
    Triple(Int d, Int x, Int y):
            d(d),x(x),y(y) {
        ;
    }
};
Triple egcd(Int a, Int b) {
    if (!b)return Triple(a,1,0);
    Triple q=egcd(b,a%b);
    return Triple(q.d, q.y, q.x-a/b*q.y);
}
inline Int invmod(Int a, Int n) {
    Triple t=egcd(a,n);
    if (t.d>1)return 0;
    Int r=t.x%n;
    return (r<0?r+n:r);
}

const int maxn=1000005*2;
Int invfact[maxn]; //inverse mod
Int fact[maxn];
inline void findFactorials(int upto) {
    fact[0]=fact[1]=1;
    for (int i=2;i<=upto;++i) {
        fact[i]= domod(fact[i-1]*i);
    }
}

int N,K;
inline void Read() {
    CI(N,K);
}
Int ncr(Int n, Int r){
    Int a = fact[n];
    Int b = invmod(fact[r],mod);
    Int c = invmod(fact[n-r],mod);
    //sdebug(a,b,c);
    return domod(domod(a*b)*c);
}
inline void Proc() {
    Int res = ncr(N+K-1,N);
    cout<<res;
    line;
}
int main() {
    findFactorials(1000000*2);
    int tt;
    CI(tt);
    foE(i,1,tt) {
        Read();
        cout<<"Case "<<i<<": ";
        Proc();
    }
    return 0;
}
