/*
 *      ID : pallab81
 *      PROG : 1060
 *      LANG : C++
 *
 *      2012-06-05 11:45:09
 *      "I have not failed, I have just found 10000 ways that won't work.
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
#define line putchar_unlocked('\n')

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

#define getchar getchar_unlocked
#define putchar putchar_unlocked

inline void fastRead(int *a) {
    register char c=0;
    while (c<33) c=getchar();
    *a=0;
    while (c>33)
    {
        *a=*a*10+c-'0';
        c=getchar();
    }
}
inline string fastRead() {
    register char c[33];
    gets(c);
    return (string)c;
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
inline void wait( double seconds ) {
    double endtime = clock()+( seconds* CLOCKS_PER_SEC );
    while ( clock() < endtime ) {
        ;
    }
}

namespace FACT {
#define T Int
T fact[25];
inline void calc(int upto) {
    fact[0]=fact[1]=1;
    for (int i=2;i<=upto;++i) {
        fact[i]= fact[i-1]*i;
    }
}
}
map<char,int> mp;
inline Int totalPermutation() {
    Int up=0;
    Int dn=1;
    foit(it,mp) {
        dn*= FACT::fact[ it->second ];
        up+=(it->second);
    }
    return (FACT::fact[up])/dn;
}
string givenString;
int nth;
inline void Read() {
    cin>>givenString;
    fastRead(&nth);
    nth--;
}

inline void Solve() {
    Read();
    mp.clear();
    foit(it,givenString) {
        mp[ (*it) ]++;
    }
    Int total = totalPermutation();
    if ( nth>=total ) {
        puts("Impossible");
        return ;
    }
    Int prv=0;
    string res="";
    for (int i=0;i<LN(givenString);++i) {
        foit(it,mp) {
            if (it->second>0) {
                char ch=it->first;
                mp[ch]--;
                Int get = totalPermutation();
                if ( prv+get-1>=nth) {
                    res+=ch;
                    goto L;
                }
                else {
                    mp[ch]++;
                    prv+=(get);
                }

            }
        }
L:
        ;
    }
    cout<<res;
    line;
}
#define showcase
int main() {
    FACT::calc(20);

    int tt;
    CI(tt);
    foE(i,1,tt) {
#ifdef showcase
        cout<<"Case "<<i<<": ";
#endif
        Solve();
    }

    return 0;
}

// kate: indent-mode cstyle; space-indent on; indent-width 0; 
