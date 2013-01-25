/*
 * Author  : Pallab
 * Program : 1110
 *
 * 2011-11-24 13:02:16
 *
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

string dp[101][101];
long vs[101][101];
string S[2];
int L[2];
 
inline void Read(){
    cin>>S[0]>>S[1];
    L[0] =LN(S[0]);
    L[1] =LN(S[1]);
}
 
string go( int i, int j ){
    if( i >=  L[0] || j >= L[1] ){
        return "";
    }
    if( vs[i][j]!=-1){
        return dp[i][j];
       
    }
    vs[i][j]=1;
    string best = "";
    string a = go(i+1,j);
    
    int lbest = 0;
    int la = LN(a);
    if( la >= lbest    ){
        if( la== lbest && a < best ){
            best = a;
	    lbest = la;
        }
        else if( la > lbest ) {
            best = a;
	    lbest = la;
        }
       
    }
    
    string b = go(i,j+1);
    int lb = LN(b);
    
    if( lb >= lbest    ){
        if( lb==lbest && b < best ){
            best = b;
	    lbest = lb;
        }
        else if( lb > lbest ) {
            best = b;
	    lbest = lb;
        }
       
    }
   
    if( S[0][i] == S[1][j] ){
        string d = S[0][i] + go( i+1,j+1 );
	int ld = LN(d);
            if( ld >= lbest    ){
                if( ld==lbest && d < best ){
                    best = d;
		    lbest = ld;
                }
                else if( ld > lbest ) {
                    best = d;
		    lbest = ld;
                }
       
            }
    }
    dp[i][j]= best;
return best;
}
 
inline void Proc(){
    SET(vs,-1);
    string var = go( 0, 0 );
    if( LN(var) < 1){
        cout<<":(\n";
    }
    else{
        cout<<var<<"\n";
    }
}
 
int main() {
       
    int t;
    CI(t);
    foE(i,1,t){
        Read();
        cout<<"Case "<<i<<": ";
        Proc();
    }
       
    return 0;
}
 