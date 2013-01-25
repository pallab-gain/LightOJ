/*
 * Author  : Pallab
 * Program : K
 *
 * 2012-03-04 09:12:18
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

inline void debug(int _x) {
    cout<<_x<<'\n';
}
inline void debug(int _x,int _y) {
    cout<<_x<<' '<<_y<<'\n';
}
inline void debug(int _x,int _y,int _z) {
    cout<<_x<<' '<<_y<<' '<<_z<<'\n';
}
inline void debug(int _x,int _y,int _z,int _zz) {
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
enum {
    maxn=1000010
};

int phivalue[maxn];
inline int phi(int n) {
    if (n<=1)return 0;
    int result=n;
    for (int i=2; i*i<=n; ++i) {
        if (n%i ==0 ) {
            while ( n%i ==0) {
                n/=i;
            }
            result-= (result/i);
        }
    }
    if (n>1) {
        result-=(result/n);
    }
    return result;
}


inline void test() {
    for (int i=1;i<=10000;++i) {

        for (int k=1; ;++k) {
            if (phi(k)>=i) {
                debug(i,k,phi(k));
                break;
            }
        }
    }
//   for(int i=1;i<=100;++i){
//     debug(i,phi(i));
//   }
}

int used[maxn];
inline int doit(int num) {
    if (used[num]!=-1)return used[num];
    for (int k=num+1; ;++k) {
        int var;
        if (phivalue[k]==-1) {
            var=phivalue[k]= phi(k);
        }
        else {
            var= phivalue[k];
        }

        if ( var >=num ) {
            return used[num]=k;
        }
    }
}
inline void solve() {
    int N;
    CI(N);
    Int sum=0;
    int num;
    fo(i,N) {
        CI(num);
        sum = sum+doit(num);
    }
    cout<<sum;
    puts(" Xukha");
}
int main() {
    //test();
    SET(used,-1);
    SET(phivalue,-1);
    int tt;
    CI(tt);
    foE(i,1,tt) {
        cout<<"Case "<<i<<": ";
        solve();
    }

}
