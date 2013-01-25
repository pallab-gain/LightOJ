/*
 * Author  : Pallab
 * Program : 1105
 *
 * 2012-03-12 15:15:24
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
const int maxn=100;
Int fib[maxn+5];
inline void Fibonacci(int upto) {
    fib[0]=0;
    fib[1]=1;
    fib[2]=1;
    for (int i=3;i<=upto;++i) {
        fib[i]=fib[i-1]+fib[i-2];
    }
}
inline Int fastPow(Int x, Int y) {
    Int res= (Int)1;
    for ( ; y ; ) {
        if ( (y&1) ) {
            res*= x;
        }
        x*=x;
        y>>=1;
    }
    return res;
}
int N;
inline void Read() {
    CI(N);
}
/*
 * http://goo.gl/8tUaQ
 * Zeckendorf(n)= {
 * local(k); a=0;
 * while(n>0, k=0;
 * 	while(fibonacci(k)<=n, k=k+1);
 * 	a=a+10^(k-3); n=n-fibonacci(k-1); ); a
 * }
 *
 * { for (n=0, 10000, Zeckendorf(n); print(n, " ", a);
 */
int res[50];
int leftmost;
inline void Zeckendorf(int n) {
    int k;
    SET(res,0);

    leftmost=-1;
    while (n>0) {
        k=0;
        while (fib[k]<=n) {
            k=k+1;
        }
        res[k-3]=1;
        n=n-fib[k-1];
        if (leftmost==-1)leftmost=k-3;
    }
    for (int i=leftmost;i>=0;--i)
        putchar(res[i]?'1':'0');
    line;

}
inline void Proc() {
    Zeckendorf(N);
}
int main() {
    Fibonacci(70);
//    debug(fib[60]);
    int tt;
    CI(tt);
    foE(i,1,tt) {
        Read();
        cout<<"Case "<<i<<": ";
        Proc();
    }
    return 0;
}

