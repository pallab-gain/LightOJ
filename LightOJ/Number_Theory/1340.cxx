/*
 * Author  : Pallab
 * Program : 1340.cxx
 *
 * 2012-01-10 10:13:25
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


#define N 1000000
#define MOD 10000019
#define Square(p) p * p

int mark [N];
int primeList[N];
int cnt;

inline void sieve () {
    SET(mark,-1);

    int sqrtN = (int)sqrt( (double)N );
    for ( int i = 3; i <= sqrtN; i += 2 ) {
        if ( mark [i] ) {
            for ( int j = i * i; j < N; j += i ) {
                mark [j] = 0;
            }
        }
    }
    cnt=0;
    primeList[cnt]=2;
    ++cnt;
    for ( int i = 3; i < N; i += 2 ) {
        if ( mark [i] ) {
            primeList[cnt]=i;
            ++cnt;
        }
    }
}


long long bigMod (long long b, long long p)
{
    if ( p == 0 ) return 1;
    if ( p % 2 == 0 ) return Square(bigMod (b, p / 2)) % MOD;
    return ((b) * bigMod (b, p - 1)) % MOD;
}

int main () {
    sieve ();
    int testCase;
    scanf ("%d", &testCase);

    foE(kase,1,testCase) {
        int n, t;
        scanf ("%d %d", &n, &t);
        long long res = 1;
        bool resFound = false;

        for ( int i = 0; i < cnt; i++ ) {
            //if ( n > primeList[i] ==0 )break;
            int tmp = n;
            int total=0;
            while ( tmp ) {
                total+= ( tmp/primeList[i] );
                tmp/=primeList[i];
            }
            if ( total >= t ) {
                resFound = true;
                res *= bigMod ( primeList[i], total / t);
                res %= MOD;
            }
        }

        cout<<"Case "<<kase<<": "<<( resFound==false ? -1 : res )<<"\n";
    }

    return 0;
}
// kate: indent-mode cstyle; space-indent on; indent-width 0; 
