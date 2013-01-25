/*
 * Author  : Xerxes
 * Program : 1258.cxx
 *
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
const int max_len = (int)1e6 + 10;
char text[ max_len ];
char pattern[ max_len ];
int dif;


int F[ max_len ];
int len;
int m,n;


inline void revCopy(){
	int i,j;
	for(i=0,j=len-1; i<len;++i,--j ){
		pattern[j]=text[i];
	}
}
inline void Read(){
	gets(text);
	len = strlen(text);
}

// KMP begin
inline void build_failure_function(){
	int i,j;
	F[0] = F[1] = 0; 
	for(i = 2; i <= m; i++) {
		j = F[i - 1];
		for( ; ; ) {
			if(pattern[j] == pattern[i - 1]) { 
			F[i] = j + 1; break; 
		}
		if(j == 0) {
			F[i] = 0; break; 
		}
		j = F[j];
		}
	}   
}

inline void Knuth_Morris_Pratt(){
	n = m = len;
	build_failure_function(); 

		int i = 0;
		int j = 0;
  
		for( ; ; ) {
			if(j == n) break; 
			if(text[j] == pattern[i]) {
				i++;
				j++;
				if(i == m);
			}
			else if(i > 0) i = F[i];
			else j++;
		}
		
	dif = i-j ;
	if( dif < 0 )dif = -dif;
}

// KMP end

int main() {
	/*
	#ifndef ONLINE_JUDGE
		freopen("in", "rt", stdin);
	#endif
	*/
	int cases = 1,Kase=1;
	for ( scanf("%d\n",&cases) ; cases; --cases,++Kase) {
		Read();
		revCopy();
		Knuth_Morris_Pratt();
		printf("Case %d: %d\n",Kase,len+dif);
	}
	
	return 0;
} 
