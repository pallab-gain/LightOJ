/*
 * Author  : Pallab
 * Program : 1157.cxx
 *
 * 2011-12-17 19:01:27
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
#define foR(i,st,ed) for(int i = st ; i < ed ; ++i )
#define fo(i,ed) foR( i , 0 , ed )
#define foE(i,st,ed) for(int i = st ; i <= ed ; ++i )
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

inline void wait(double seconds) {
    double endtime = clock()+(seconds * CLOCKS_PER_SEC);
    while (clock() < endtime) {
        ;
    }
}
inline int doMod(int num) {
    if (num < 0) {
        num += (int) 1000007;
    }
    while (num >= (int) 1000007) {
        num -= (int) 1000007;
    }
    return num;
}
const int maxn = (int)1e3;
int a[maxn+1][maxn+1];
int b[maxn+1][maxn+1];
char s1[maxn+1];
char s2[maxn+1];
int len1,len2;
inline void Read() {
    gets(s1);
    gets(s2);
}
inline void Proc() {
    len1 = strlen(s1);
    len2 = strlen(s2);
    SET(a,0);
    SET(b,0);
    for (int i = 0; i <= len1; ++i) {
        b[i][0] = 1;
    }
    for (int i = 0; i <= len2; ++i) {
        b[0][i] = 1;
    }

    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                a[i][j] = a[i - 1][j - 1] + 1;
                b[i][j] = b[i - 1][j - 1];
            } else {
                int xx = a[i - 1][j];
                int yy = a[i][j - 1];
                a[i][j] = ( xx>yy ? xx : yy ) ;
                if (a[i][j] == a[i - 1][j]) {
                    b[i][j] += b[i - 1][j];
                }
                if (a[i][j] == a[i][j - 1]) {
                    b[i][j] += b[i][j - 1];
                }
                if (a[i][j] == a[i - 1][j - 1]) {
                    b[i][j] -= b[i - 1][j - 1];
                }
                b[i][j] = doMod( b[i][j] );
            }
        }
    }
    cout<<b[len1][len2]<<"\n";

}
int main() {
    int t;
    scanf("%d\n",&t);
    foE(i,1,t) {
        Read();
        cout<<"Case "<<i<<": ";
        Proc();
    }

    return 0;
}
// kate: indent-mode cstyle; space-indent on; indent-width 0; 
