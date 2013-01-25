/*
 * Author  : Pallab
 * Program : 1038
 *
 * 2012-03-11 15:16:09
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
vector< pair<Int,int> >primeDivisors;
int sz;
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
vector<int> divisors;
void genDivisor(int at, Int current) {
    if (at==SZ(primeDivisors)) {
        divisors.pb(current);
        return ;
    }
    Int p=primeDivisors[at].first;
    int power=primeDivisors[at].second;
    for (int i=0;i<=power;++i) {
        genDivisor(at+1,current);
        current*=p;
    }
}
const int maxn=(int)(1e5);
double dp[maxn+5];

inline double solve(int number) {
    factorize(number);
    divisors.clear();
    genDivisor(0,1);
    sort(divisors.begin(),divisors.end(),less<int>());
    int sz=SZ(divisors);

    double sum=0;
    for (int i=1;i<sz;++i) {
        sum+= dp[ number/divisors[i] ];
    }
    sum+=sz;
    sum/=(double)(sz-1);
    return sum;
}
inline void pre() {
    dp[0]=0;
    dp[1]=0;
    dp[2]=2;
    dp[3]=2;
    for (int i=4;i<=maxn;++i) {
        dp[i]=solve(i);
    }
}

int N;
inline void Read() {
    CI(N);
}
inline void Proc() {
    cout<<setprecision(9)<<fixed<<dp[N];
    line;
}
int main() {
    pre();
    int tt;
    CI(tt);
    foE(i,1,tt) {
        Read();
        cout<<"Case "<<i<<": ";
        Proc();
    }
    return 0;
}
