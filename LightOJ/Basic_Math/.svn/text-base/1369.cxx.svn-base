/*
 * Author  : Pallab
 * Program : 1369
 *
 * 2012-05-08 10:18:08
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
const int maxn = (int)1e5;
Int array[maxn+5];
int n,q;
inline void Read() {
    array[0]=0;
    CI(n,q);
    foE(i,1,n) {
        scanf("%lld",&array[i]);
    }
}
inline void Proc() {
    Int sum1=0;
    for (int i=1;i<=n;++i) {
        Int tmp = array[i]*(n-i);
        sum1+=tmp;
    }
    Int sum2=0;
    for (int i=1;i<=n;++i) {
        sum2+= ( array[i]*(i-1));
    }
    line;
    //debug(sum1,sum2,"");
    int tmp;
    int at,value;
    while (q--) {
        CI(tmp);
        if (!tmp) {
            CI(at,value);
            at+=1;
            Int tmp1 = array[at]*(n-at);
            Int tmp2 = ((Int)value)*(n-at);
            sum1 = sum1-tmp1+tmp2;

            tmp1 = array[at]*(at-1);
            tmp2 = ((Int)value)*(at-1);
            sum2 = sum2-tmp1+tmp2;

            array[at]=(Int)value;
        }
        else {
            cout<<(sum1-sum2);
            line;
        }
    }

}
int main() {
    int tt;
    CI(tt);
    foE(i,1,tt) {
        Read();
        cout<<"Case "<<i<<":";
        Proc();
    }
    return 0;
}
