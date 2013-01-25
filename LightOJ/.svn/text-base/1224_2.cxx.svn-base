/*
 * Author  : Pallab
 * Program : 1224.cxx
 * 
 * 2011-11-18 21:21:40
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
#define Int unsigned short
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
inline int swt( char ch ){
	if( ch=='A' )return 0;
	if( ch=='C' )return 1;
	if( ch=='G' )return 2;
	if( ch=='T' )return 3;
	
return -1;// kill
}

const int maxn = 1<<20;
struct NODE{
	int W[4];
	Int C[4];
	Int L;
};

NODE tree[ maxn ];
int key;

inline void _ini(){
	NODE tmp;
	for(int i=0;i<4;++i){
		tmp.W[i]=-1;
		tmp.C[i]=(Int)0;
		tmp.L= (Int)0;
	}
	key=0;
	fill(tree,tree+maxn,tmp);
	++key;
}

inline int _find(int id, int ltr){
	NODE tmp = tree[ id ];
	if( tmp.W[ ltr ]!=-1 ){
		return tmp.W[ ltr ];
	}
	return -1;
}
inline void _add(int id, int ltr){
	NODE& tmp = tree[ id ];
	tmp.W[ltr] = key;
	++key;
}
inline void _go( string str, int id=(int)0 ){
	for(int i=0,j=LN(str); i<j; ++i){
		int ltr = swt( str[i] );
		int signal = _find( id, ltr);
		
		if( signal== (int)-1 ){
			int tkey = key;
			_add(id,ltr);
			id = tkey;
		}
		else{
			id = signal;
		}
		tree[id].C[ltr]++;
		tree[id].L= (Int)i+1;
	}
}
int nword;
inline void Read(){
	_ini();
	scanf("%d\n",&nword);
	string ss;
	while(nword--){
		cin>>ss;
		_go(ss);
	}
}
inline void Proc(){
	int best=0;
	fo(k,maxn){
		Int mx=0;
		fo(i,4){
			mx = max(mx, tree[k].C[i] );
		}
		int var = (int)mx * (int)tree[k].L;
		best = max( best, var);
	}
	cout<<best<<"\n";
}

int main() {
	int t;
	CI(t);
	for(int i=1;i<=t;++i){
		Read();
		cout<<"Case "<<i<<": ";
		Proc();
	}
	return 0;
}