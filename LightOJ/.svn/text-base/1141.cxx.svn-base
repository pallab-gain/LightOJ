/*
 * Author  : Pallab
 * Program : 1141
 *
 * 2012-03-05 13:20:03
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

int s,t;
int factors[200];
int cnt;
inline void primeFactorization(int number) {
    cnt=0;
    int tmp=number;
    for (int i=2;i*i<=number;++i) {
        if ( number%i ==0) {
            while ( number%i ==0 ) {
                number/=i;
            }
            factors[cnt++]=i;
        }
    }
    if (number>1&&number!=tmp) {
        factors[cnt++]=number;
    }
}
inline void Read() {
    CI(s,t);
}
int D[1005];
inline void Proc() {
    SET(D,63);
    queue<int> q;
    q.push(s);
    D[s]=0;
    while (!q.empty()) {
        int u=q.front();
        q.pop();
        if (u==t) {
            cout<<D[u];
            puts("");
            return ;
        }
        primeFactorization(u);
        fo(i,cnt) {
            int v=u+factors[i];
            if (v<=t&&D[u]+1<D[v]) {
                D[v]=D[u]+1;
                q.push(v);
                //debug(v,D[v],factors[i]);
            }
        }
    }

    puts("-1");
}
int main() {
    int tt;
    CI(tt);
    foE(i,1,tt) {
        Read();
        cout<<"Case "<<i<<": ";
        Proc();
    }

}
