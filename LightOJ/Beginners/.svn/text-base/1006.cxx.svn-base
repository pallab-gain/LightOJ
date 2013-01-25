/*
 * Author  : Pallab
 * Program : 1006
 *
 * 2012-05-14 15:38:29
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

int a, b, c, d, e, f,N;
Int hexx[10005];
// int fn( int n ) {
//     if ( n == 0 ) return a;
//     if ( n == 1 ) return b;
//     if ( n == 2 ) return c;
//     if ( n == 3 ) return d;
//     if ( n == 4 ) return e;
//     if ( n == 5 ) return f;
//     return( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) )%10000007;
// }
inline void Gen() {
    hexx[0]=a%10000007;
    hexx[1]=b%10000007;
    hexx[2]=c%10000007;
    hexx[3]=d%10000007;
    hexx[4]=e%10000007;
    hexx[5]=f%10000007;
    for (int i=6;i<=N;++i) {
        hexx[i] = hexx[i-1]+hexx[i-2]+hexx[i-3]+hexx[i-4]+hexx[i-5]+hexx[i-6];
	while(hexx[i]<0)hexx[i]+=10000007;
	while(hexx[i]>=10000007)hexx[i]-=10000007;
    }

}
inline void Read() {
    scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &N);
}
inline void Proc() {
    Gen();
    cout<< hexx[N];
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
