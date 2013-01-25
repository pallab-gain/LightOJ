/*
 * Author  : Pallab
 * Program : 1259
 *
 * 2012-05-01 21:33:14
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

const int inf = (int)1e7;
bool used[inf+1];
int primes[664579+10];
int cnt;

inline void sieve() {
    int sqrtN = (int)sqrt((double)inf)+1;
    int i,j;
    for (i=3;i<=sqrtN;i+=2) {
        if (!used[i]) {
            for (j=i*i;j<inf;j+=i) {
                used[j]=true;
            }
        }
    }
    cnt=0;
    primes[cnt++]=2;
    for (i=3;i<inf;i+=2) {
        if (!used[i])primes[cnt++]=i;
    }
}
inline bool isP(int x) {
    if ( x<2)return false;
    if (x==2)return true;
    if ( (x&1)==0 )return false;
    return !used[x] ? true : false ;
}
int main() {
    int tt,x,ret;
    sieve();
    CI(tt);
    foE(i,1,tt) {
        CI(x);
	ret=0;
	for(int k=0;k<cnt;++k){
	   int a = primes[k];
	   int b = x-a;
	   if(a>b)break;
	   if( isP(b) ){
	      ++ret;
	   }
	}
        cout<<"Case "<<i<<": "<<ret;line;

    }
    return 0;
}
