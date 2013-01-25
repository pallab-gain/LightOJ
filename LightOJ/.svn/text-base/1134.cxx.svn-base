/*
 * Author  : Pallab
 * Program : 1134
 *
 * 2012-03-15 20:56:34
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

template< class T1>
inline void debug(T1 _array,int _size) {
    cout<<"[";
    for (int i=0;i<_size;++i) {
        cout<<' '<<_array[i];
    }
    puts(" ]");
}
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
const int maxn=(int)1e5;
unsigned long long nctwo[maxn+5];
inline void C() {
    nctwo[0]=0;
    nctwo[1]=0;
    nctwo[2]=1;
    foE(i,3,maxn)
    nctwo[i]=nctwo[i-1]+(i-1);
}
int N,M;
int numbers[maxn+10];
inline void Read() {
    CI(N,M);
    fo(i,N) {
        CI(numbers[i]);
    }
}
int csum[maxn];//cumulative sum
int cmod[maxn];//cumulative sum + mod with M
inline void Proc() {
    SET(cmod,0);
    fo(i,N) {
        if (i) {
            csum[i]=(csum[i-1]+numbers[i])%M;
        }
        else {
            csum[i]=numbers[i]%M;
        }
        cmod[csum[i]]++;
    }

    unsigned long long res=0;
    fo(i,M) {
        if (i) {
            res+=nctwo[cmod[i]];
        }
        else {
            res+=cmod[i];
            res+=nctwo[cmod[i]];
        }
    }
    cout<<res;
    line;
}
int main() {
    C();
    int tt;
    CI(tt);
    foE(i,1,tt) {
        Read();
        cout<<"Case "<<i<<": ";
        Proc();
    }
    return 0;
}
