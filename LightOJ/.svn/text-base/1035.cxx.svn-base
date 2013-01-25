/*
 * Author  : Pallab
 * Program : 1035
 *
 * 2012-01-27 12:41:20
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

#define CI( x ) scanf("%d",&x)
#define CL( x ) scanf("%lld",&x)
#define CD( x ) scanf("%lf",&x )
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
#define f first
#define s second
#define SET( ARRAY , VALUE ) memset( ARRAY , VALUE , sizeof(ARRAY) )

const int MAXN = 100;
bitset< MAXN > mark;
int primes[MAXN];
int cnt;
inline void sieve() {
    mark=0 ;
    int i,j;
    int sqrtN = (int)sqrt( (double)MAXN )+1;
    for (i=3;i<=sqrtN;i+=2) {
        if ( !mark[i] ) {
            for (j=i*i; j<MAXN;j+=i) {
                mark[j]=1;
            }
        }
    }
    cnt=0;
    primes[cnt++]=(int)2;
    for (i=3;i<=MAXN;i+=2) {
        if ( !mark[i] ) {
            primes[cnt++]=i;
        }
    }
}
int N;
inline void Read() {
    CI(N);
}
inline void Proc() {
    int i,j;
    cout<<N;
    string token=" = ";

    for (i=0; (i<cnt && primes[i]<=N) ;++i) {
        int _N = N;
        int freq=0;
        do {
            freq+= ( _N/primes[i] );
            _N/=primes[i];
        } while ( _N>0 );
        cout<<token<<primes[i]<<" ("<<freq<<")";
        token=" * ";
    }
    puts("");
}
int main() {
    sieve();

    int t;
    CI(t);
    foE(i,1,t) {
        Read();
        cout<<"Case "<<i<<": ";
        Proc();
    }
    return 0;
}
// kate: indent-mode cstyle; space-indent on; indent-width 0; 
