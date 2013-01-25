/*
 * Author  : Pallab
 * Program : 1007
 *
 * 2012-03-11 02:34:00
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
#define Int unsigned long long
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
const int maxn = 5*((int)(1e6)) ;
int divisor[maxn+5];
inline Int value(Int p, Int exponent, Int power) {
    return power / p * (p - 1);
}
inline void generateDivisorTable(int upTo) {
    for (int i = 1; i < upTo; i++)
        divisor[i] = i;
    for (int i = 2; i * i < upTo; i++) {
        if (divisor[i] == i) {
            for (int j = i * i; j < upTo; j += i)
                divisor[j] = i;
        }
    }

}
Int result[maxn+5];
inline void calculateUpTo(int upTo) {
    result[1] = 1;
    for (int i = 2; i < upTo; i++) {
        int iDivided = i;
        int exponent = 0;
        do {
            iDivided /= divisor[i];
            exponent++;
        } while (iDivided % divisor[i] == 0);
        result[i] = result[iDivided] * value(divisor[i], exponent, i / iDivided);
    }
    
    result[1]=result[0]=0;
    for (int i=2;i<upTo;i++) {
        result[i] = result[i-1]+( result[i]*result[i]) ;
    }
    return ;
}

int main() {
    generateDivisorTable(maxn+1);
    calculateUpTo(maxn+1);
    int kase;
    CI(kase);
    int a,b;
    foE(i,1,kase) {
        CI(a,b);
        cout<<"Case "<<i<<": "<<result[b]-result[a-1];
        line;
    }
    return 0;
}
