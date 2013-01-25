/*
 * Author  : Pallab
 * Program : 1054
 *
 * 2012-03-17 18:15:53
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
const Int mod = 1000000007LL;
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
inline Int domod(Int x){
  if(x<0)x+=mod;
  return x%mod;
}
inline Int powerMod (Int a, Int b, Int m) {
    Int res = 1;
    while (b > 0)
        if (b & 1) {
            res = invmod(res * a, m);
            --b;
        }
        else {
            a = invmod( a * a, m);
            b >>= 1;
        }
    return invmod(res , m);
}
inline Int fastPow(Int a, Int b) {
    Int x= (Int)1,y= domod(a);

    while (b>0) {
        if (b&1) {
            x= domod(x*y);
        }
        y=domod(y*y);
        b>>=1;
    }
    return domod(x);
}
Int _N,_M;
inline void Read() {
    cin>>_N>>_M;
}

vector< pair<Int,int> >primeDivisors;
inline void factorize(Int number) {
    primeDivisors.clear();
    for (Int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            int power = 0;
            do {
                power++;
                number /= i;
            } while (number % i == 0);
            primeDivisors.pb(mk(i, power));
        }
    }
    if (number != 1)
        primeDivisors.pb(mk(number, 1));
}


inline void Proc() {
    factorize(_N);
    Int ret=1;
    fo(i,SZ(primeDivisors)) {
        Int number = primeDivisors[i].first;
        Int power = (_M*primeDivisors[i].second)+1 ;
        Int p1 = domod(fastPow(number, power)-1 );
        Int p2 = domod( invmod(number-1,mod) );
	Int p3 = domod(p1*p2);
	//debug(ret,p1,p2);
        ret = domod( ret*p3 );
    }
    cout<<ret;
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

