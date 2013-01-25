/*
 * Author  : Xerxes
 * Program : Road Construction.cxx
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
const int max_city = (int)50 ;
int kase=1;
map< string, int > mp;

int N; // number of roads

struct NODE{
	int u,v,w;
	NODE(int _u, int _v, int _w):
	u(_u),v(_v),w(_w){;}
};
vector< NODE > E;

inline void Read(){
	CI(N);
	mp.clear();
	E.clear();
	
	string u,v;
		
	int w,idx,ud,vd;
	idx=0;
	
	fo(i,N){
		cin>>u>>v>>w;
		
		if( mp.count(u) < 1 ){
			mp[ u ] = idx;
			ud = idx;
			++idx;
		}
		else{
			ud = mp[ u ];
		}
		
		if( mp.count(v) < 1 ){
			mp[ v ] = idx;
			vd = idx;
			++idx;
		}
		else{
			vd = mp[v];
		}
		E.pb( NODE(ud,vd,w) );
	}
}

int root[ max_city+10 ];
int rank[ max_city+10 ];

inline void _Set(){
	for(int i=0;i<=max_city;++i){
		root[i]=i;
		rank[i]=0;
	}
}
inline int _Find(int x){
	if( x!= root[x] ){
		root[x] = _Find( root[x] );
	}
return root[x];
}
inline void _Union(int x, int y){
	int rx = _Find(x);
	int ry = _Find(y);
	if( rank[ rx ] > rank[ ry ] ){
		root[ ry ] = rx;
	}
	else{
		root[ rx ] = ry;
	}
	if( rank[rx] == rank[ry] ){
		rank[ry]+=1;
	}
return ;
}

inline bool cmp(NODE A, NODE B){
	return ( A.w < B.w ) ;
}

inline void Proc(){
		sort(E.begin(),E.end(), cmp);
		_Set();
		int unique_city = SZ(mp);
		int cost = 0;
		int build= 0;
		for(int i=0,j=SZ(E); i<j ; ++i){
			
			int u = E[i].u;
			int v = E[i].v;
			int w = E[i].w;
			
			if( _Find(u)!=_Find(v) ){
				_Union(u,v);
				cost+= w;
				++build;
			}
		}
		cout<<"Case "<<kase<<": ";
		if( build+1 != unique_city ){
			cout<<"Impossible\n";
		}
		else{
			cout<<cost<<'\n';
		}
		
}

int main() {
	
	int cases = 1;
	for ( CI(cases) ; cases; --cases,++kase) {
		Read();
		Proc();
	}
	
	return 0;
} 
