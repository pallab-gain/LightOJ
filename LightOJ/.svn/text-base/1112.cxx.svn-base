/*
 * Author  : Xerxes
 * Program : D.cxx
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
const int mx = (int)1e5;
int N,Q;
int tree[ mx ];

// Fenwick tree start
inline void Update(int kth, int amount){
	for( ; kth<N; kth|=(kth+1) ){
		tree[ kth ]+=amount;
	}
}
inline int Query(int lo, int hi){
	if( lo==0 ){
		int sum = 0;
		for( ; hi>=0; hi = (hi&(hi+1)) -1  ){
			sum+= tree[hi];
		}
		return sum;
	}
	else{
		return Query( 0, hi ) - Query(0,lo-1) ;
	}
}
// Fenwick tree ends
inline void Read(){
	SET(tree,0);
	scanf("%d %d",&N,&Q);
	int x;
	fo(i,N){
		CI(x);
		Update(i,x);
	}
}

inline void Proc(){
	int sig;
	int ith;
	
	int money;
	int lo,hi;
	
	while(Q--){
		scanf("%d",&sig);
		if( sig==1 ){
			scanf("%d",&ith); // give all the money from ith sack
			int var = Query(ith,ith);
			cout<<var<<'\n';
			Update(ith,-var);
		}
		else if( sig==2 ){
			scanf("%d %d",&ith,&money); // add money to ith sack
			int var = Query(ith,ith);
			Update(ith,money);
		}
		else{
			scanf("%d %d",&lo,&hi); // find total money from lo to hi
			int var = Query(lo,hi);
			cout<<var<<'\n';
		}
	}
}

int main() {
	
	int t;
	CI(t);
	for(int i=1;i<=t;++i){
		Read();
		cout<<"Case "<<i<<":\n";
		Proc();
	}
	
	return 0;
} 
