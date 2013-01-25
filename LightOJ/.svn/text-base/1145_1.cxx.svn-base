/*
 * Author  : Pallab
 * Program : 1145
 *
 * 2012-03-12 20:43:58
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
template<class T>
inline void debug(T _x) {
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

const int mod = 100000007;
const int maxnk = 1001;
const int maxs = 15005;

int N; // number of dice
int K; // dice face
int S; // sum to be

inline void Read() {
    scanf("%d %d %d",&N,&K,&S);
}
inline Int mymod(Int var) {
    while (var<0)var+=mod;
    return var%mod;
}
Int prv[maxs];
Int cur[maxs];
Int res[maxs];
inline void Proc() {

    SET(prv,0);
    SET(cur,0);
    SET(res,0);

    foE(i,1,K) {
        cur[i]=1;
        res[i]=1;
    }
    foE(i,1,S) {
        cur[i]+=cur[i-1];
    }

    foE(n,2,N) {
        memcpy(prv,cur,sizeof(prv));
        foE(s,1,S) {
            cur[s]=prv[s-1];
            if (s>K) {
                cur[s]=mymod(cur[s]- prv[s-K-1]);
            }
            res[s]=cur[s];
        }
        foE(s,1,S) {
            cur[s]=mymod(cur[s]+cur[s-1]);
        }

    }
    cout<<res[S];
    line;

}
int main() {
    int t;
    CI(t);
    foE(i,1,t) {
        Read();
        cout<<"Case "<<i<<": ";
        Proc();
    }

    return 0;
}
