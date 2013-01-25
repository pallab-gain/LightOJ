/*
 * Author  : Pallab
 * Program : 1079_1
 *
 * 2012-03-12 01:23:32
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
const int maxn=100;
double P;
int N;
pair<int, double> banks[maxn+5];
inline bool cmp(pair<int, double> A, pair<int,double> B) {
    return A.second < B.second;
}
inline void Read() {
    cin>>P>>N;
    fo(i,N) {
        cin>>banks[i].first>>banks[i].second;
    }

}
const double eps = (double)1e-11;
const int inf=102345678;


bool vis[10020];
double dp[10020];

inline void Proc() {
    //cout<<setprecision(9)<<fixed;

    //sort(banks,banks+N, cmp);
    fill(dp,dp+10010,(double)inf);
    fill(vis,vis+10010,false);

    vis[0]=true;
    dp[0]=0;
    for (int i=0;i<N;++i) {
        int localmoney=banks[i].first;
        double caught=banks[i].second;

        for (int money=10010-localmoney;money>=0;--money) {
            if (vis[money]) {
                dp[money+localmoney] = min(dp[money+localmoney], dp[money]+(1-dp[money])*caught );
                vis[money+localmoney]=1;
            }
        }
    }
    int best=0;
    for (int i=10000;i>=0;--i) {
        if (dp[i]<P) {
            best=i;
            break;
        }
    }
    cout<<best;
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






