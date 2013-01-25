/*
 * Author  : Pallab
 * Program : 1044.cxx
 * 
 * 2011-11-14 20:34:55
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
const int inf = (int)1e9;
const int maxn = 1001 ;

char line[1001];
int ln;

inline void Read(){
	gets(line);
	ln = strlen(line);
}
int pos[ maxn ][ maxn ];
int dp[ maxn ];

inline void build(){
	SET(pos,-1);
	fo(i,maxn){
		pos[i][i]=1;
	}
	for(int  i=ln-1;i>=0;--i){
		for(int j=ln-1;j>i;--j){
			if( line[i]==line[j]  ){
				if( i+1==j ){
					pos[i][j]=1;
				}
				else if( (i+1 <= j-1 ) && ( pos[i+1][j-1]==1 ) ){
					pos[i][j]=1;
				}
			}
		}
	}
	
}
inline void go(){
	fill(dp,dp+ln,inf);
	for(int i=0;i<ln;++i){
		for(int j=i;j>=0;--j){
			if( pos[j][i]==1 ){
				dp[i]= min( dp[i], ( j ? dp[j-1] : 0  ) +1 );
			}
		}
	}
	
	cout<<dp[ln-1]<<"\n";

}
inline void Proc(){
	SET(dp,-1);
	build();
	go();
}

int main() {
	
	int t;
	scanf("%d\n",&t);
	foE(i,1,t){
		Read();
		cout<<"Case "<<i<<": ";
		Proc();
	}
	
	return 0;
} 