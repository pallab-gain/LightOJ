/*
 * Author  : Xerxes
 * Program : I.cxx
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
const int MAXN = (int)1e5;
int tree[ MAXN*4  ];
char buff[ MAXN+5 ];
int N,Q;
inline void Read(){
	SET( tree , 0 );
	gets(buff);
	N = strlen(buff);
	CI(Q);
}
void build(int v, int tl, int tr){
	if( tl==tr ){
		;
	}
	else{
		int tm = ( tl+tr )/2;
		build(v*2, tl, tm);
		build((v*2)+1, tm+1, tr );
	}
}
void update(int v, int tl, int tr, int l, int r, int add){
	if( l>r ){
		return ;
	}
	if( l==tl && tr==r ){
		tree[v]+=add;
	}
	else{
		int tm = ( tl+tr )/2;
		update( v*2, tl, tm,      l,  min(r,tm), add );
		update( (v*2)+1, tm+1, tr , max(l,tm+1),r, add );
	}
}
int get( int v, int tl, int tr, int pos ){
	if( tl==tr ){
		return tree[v];
	}
	int tm = (tl+tr)/2;
	if( pos <= tm ){
		return tree[v] + get( v*2, tl, tm, pos );
	}
	else{
		return tree[v] + get( (v*2)+1, tm+1, tr, pos );
	}
}

inline void Proc(){
	char ch;
	int l,r;
	//cout<<buff<<" "<<N<<"\n";
	while( Q-- ){
		cin>>ch;
		if( ch=='I' ){
			scanf("%d %d",&l,&r);
			update(1,0,N-1,l-1,r-1,1);
		}
		else{
			scanf("%d",&l);
			int v = get(1,0,N-1,l-1);
			if( v&1 ){
				cout<< ( buff[l-1]=='0' ? "1\n" : "0\n" ) ;
			}
			else{
				cout<< buff[l-1]<<'\n';
			}
			
		}
	}
}
int main() {
	int t;
	scanf("%d",&t);
	for( int i=1;i<=t;++i){
		getchar();
		Read();
		cout<<"Case "<<i<<":\n";
		Proc();
	}
	
	return 0;
} 
