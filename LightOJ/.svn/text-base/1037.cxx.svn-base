/*
 * Author  : Xerxes
 * Program : 1037.cxx
 *
 * 2011-11-12 21:12:19
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
 
#define VI vector< int >
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
const int inf = (int)1e6;
int bit;
int kase ;
int n; // number of target
int li[ 16 ]; // number of life power
char m[16][16];
int dp[ (1<<16) ];
 
double timeout;
inline void Read(){
    CI(n);
    fo(i,n){
        CI(li[i]);
    }
    getchar();
    fo(i,n){
        gets(m[i]);
    }
}
inline int min_time(int msk, int tar){
    int best = 1;
    fo(i,n){
        if( ( msk&(1<<i) ) !=0 ){
            best = max( best, m[i][tar]-'0' );
        }
    }
    
    int v = li[ tar ]/best ;
    if( (li[tar]%best)!=0 ){
        v+=1;
    }
    //cout<<best<<" "<<v<<"\n";
    return v;
}
 
int go( int msk  ){
    
    if( msk == bit ){
        return 0;
    }
    
    int &best = dp[msk];
    if( best==-1){
        best = inf;
    
        fo(i,n){
            if( ( msk&(1<<i) ) == 0 ){
                // i can down this agent
                int v = min_time(msk,i) + go( msk|(1<<i) );
                best =  min( best, v );
            }
        }
    }
return best;
}
 
inline void Proc(){
    bit = (1<<n)-1  ;
    SET(dp,-1);
    int var = go(0);
    cout<<var<<"\n";
}
int main() {
    
    CI(kase);
    for(int i=1; i<=kase;++i ){
        Read();
        cout<<"Case "<<i<<": ";
        Proc();
    }
    
    return 0;
}