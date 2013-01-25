/*
* 	ID : Palab
* 	PROG : 1109
* 	LANG : C++
* 	2012-03-18-12.20.01 Sunday
*
* 	"I have not failed, I have just found 10000 ways that won't work.
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
    for (int i=0; i<_size; ++i) {
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
// pre written codes
const Int inf = (Int)1000000;
bitset<inf> used;
Int primes[inf];
int cnt;
inline void sieve() {
    Int sqrtN = (Int)sqrt((double)inf)+1;
    used=0;
    Int i,j;
    for (i=3; i<=sqrtN; i+=2) {
        if (!used[i]) {
            for (j=i*i; j<inf; j+=i) {
                used[j]=1;
            }
        }
    }
    cnt=0;
    primes[cnt++]=2;
    for (i=3; i<inf; i+=2) {
        if (!used[i])primes[cnt++]=i;
    }
}
int tot;
vector< pair<Int,int> > primeDivisors;
inline void factorize(Int number) {
    primeDivisors.clear();
    for (int i=0; i<cnt&&primes[i]*primes[i]<=number; ++i) {
        if ( (number%primes[i]) ==0) {
            int power=0;
            while ((number%primes[i])==0) {
                number/=primes[i];
                ++power;
            }
            primeDivisors.pb(mk(primes[i],power));
        }
    }
    if ( number!=1) {
        primeDivisors.pb(mk(number,1));
    }
    tot = SZ(primeDivisors);
}
int ndiv;
void genDivisor(int at, Int current) {
    if (at==tot) {
        ++ndiv;
        return ;
    }
    Int p=primeDivisors[at].first;
    int power=primeDivisors[at].second;
    for (int i=0; i<=power; ++i) {
        genDivisor(at+1,current);
        current*=p;
    }
}

// ends

inline void getDivisorsum(int N) {
    factorize(N);
    ndiv=0;
    genDivisor(0,1);

}
vector< pair<int,int> > vi;
inline void pre() {
    vi.clear();
    foE(i,1,1000) {
        getDivisorsum(i);
        vi.pb(mk(ndiv,-i));
    }
}

int _n;
inline void Read() {
    CI(_n);
}

inline void Proc() {
    cout<< -(vi[_n-1].second);
    line;
}
int main() {
    sieve();
    pre();
    sort(vi.begin(),vi.end(),less<pair<int,int> >());

    //freopen("in","rt",stdin);
    int tt;
    CI(tt);
    foE(i,1,tt) {
        Read();
        cout<<"Case "<<i<<": ";
        Proc();
    }
    return 0;
}
