/*
 * Author  : Pallab
 * Program : 1090
 *
 * 2012-05-02 19:06:36
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

int nn,rr,pp,qq;
inline void Read() {
    CI(nn,rr,pp,qq);
}
//calculate
//number of 2, and 5  n!

inline Int calc(int n,int x) {
    Int ret=0;
    for ( Int i=1; i<=n; i*=x ) {
        Int var = (Int)(n/i);
        if (var<0)break;
        ret+=var;
    }
    return ret;
}

//calculate
//number of 2, and 5 in p^q

inline Int calc(int p,int q, int x) {
    //factorize p respect to x;
    Int ret=0;

    while ( (p%x)==0 ) {
        p/=x;
        ++ret;
    }
    return ret*q;
}
inline void Proc() {
    Int two1 = calc(rr,2)+calc(nn-rr,2);
    Int five1= calc(rr,5)+calc(nn-rr,5);

    Int two2 = calc(nn,2) + calc(pp,qq,2) ;
    Int five2 = calc(nn,5) + calc(pp,qq,5);

    Int two = two2-two1;
    Int five = five2-five1;

    Int res = min(two,five);
    //debug(two2,five2, two1, five1);
    cout<<res;
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
