/*
 * Author  : Pallab
 * Program : 1215
 *
 * 2012-03-18 00:14:47
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
template< class T >
inline T gcd(T a, T b) {
    // NEGATIVE VALUE'R GCD HOTE PARBE NA
    assert( (a >=0 && b>=0 ) );
    while ( b > T(0) ) {
        a%=b;
        swap(a,b);
    }
    return a;
}

template< class T >
inline T lcm(T a, T b) {
    return (a/gcd(a,b))*b;
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

Int a,b,c;
inline void Read() {
    scanf("%lld %lld %lld",&a,&b,&c);
}
map<Int,int> mp;
map<Int,int> Mp;
inline void Proc() {
    mp.clear();
    factorize(a);
    fo(i,SZ(primeDivisors)) {
        mp[primeDivisors[i].first]=max(mp[primeDivisors[i].first],primeDivisors[i].second);
    }
    factorize(b);
    fo(i,SZ(primeDivisors)) {
        mp[primeDivisors[i].first]=max(mp[primeDivisors[i].first],primeDivisors[i].second);
    }
    Mp.clear();
    factorize(c);
    fo(i,SZ(primeDivisors)) {
        Int x=primeDivisors[i].first;
        int y=primeDivisors[i].second;
        if (y>mp[x]) {
            Mp[x]=y;
        }
        else {

        }
    }
    Int res=1;
    foit(it,Mp) {
        res*= fastPow(it->first,it->second);
    }


    if ( lcm(a,lcm(b,res) )!=c ) {
        puts("impossible");
    }
    else {
        cout<<res;
        line;
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
