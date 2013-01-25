/*
 * Author  : Xerxes
 * Program : K.cxx
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

const int mx = 100000;
int N,Q;
Int bit[mx+5][2];
 
inline void update(int p, int v)
{
	for( int i=p; i<=mx; i|= (i+1) ){
		bit[i][0]+= v*(i-p+1);
		bit[i][1]+= v;
	}
}
 
inline Int query(int p){
	Int ret = 0;
	
	for (int i=p; i>=0 ; i = (i&(i+1))-1 ){
		ret += bit[i][0];
		ret += bit[i][1]*(p-i);
	}
	return ret;
}
inline void Read(){
	scanf("%d %d",&N,&Q);
	SET( bit, 0 );
}

inline void Proc(){
	int sig;
	int l,r,val;
	while(Q--){
		CI(sig);
		if(sig==0){ // update query
			scanf("%d %d %d",&l,&r,&val);
			update(l,val);
			update(r+1,-val);
		}
		else{ // find sum query
			scanf("%d %d",&l,&r);
			Int v = query(r)-query(l-1);
			cout<<v<<'\n';
		}
	}
}
int main() {
	
	int tt;
	CI(tt);
	for(int i=1;i<=tt;++i){
		Read();
		cout<<"Case "<<i<<":\n";
		Proc();
	}
	
	return 0;
} 
