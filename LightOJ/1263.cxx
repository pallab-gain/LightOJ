/*
 * Author  : Xerxes
 * Program : B.cxx
 *
 * 2011-11-10 02:20:53
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
int n;
int e;
vector< vector<int> > E;
int p[1000];
int vis[1000];
int money;
int ppl;

inline void Read(){
	scanf("%d %d",&n,&e);
	E.assign(n, vector<int>() );
	
	fo(i,n){
		CI(p[i]);
	}
	int u,v;
	fo(i,e){
		scanf("%d %d",&u,&v);
		E[u-1].pb(v-1);
		E[v-1].pb(u-1);
	}
	
}

inline  void colorit(int u){
	if( vis[u]==-1 ){
		vis[u]=1;
		money+= p[u];
		ppl+=1;
		vector<int> cango = E[u];
		for(int i=0,j=SZ(cango); i<j; ++i ){
			int v = cango[i];
			colorit(v);
		}
	}
}
inline void Proc(){
	SET(vis,-1);
	int st=-1; // standard
	bool nice = true ; // assume everything possible
	
	for(int i=0;i<n;++i ){
		if( vis[i]==-1 ){
			ppl=0;
			money=0;
			colorit(i);
			if( money%ppl !=0 ){
				nice=false;
			}
			else{
				int tst = money/ppl; // temporary standard
				if( st==-1 ){
					st = tst;
				}
				else{
					if( st!=tst ){
						nice=false;
					}
				}
			}
		}
		
	}
	if( nice ){
		cout<<"Yes\n";
	}
	else{
		cout<<"No\n";
	}
}

int main() {
	
	int t;
	CI(t);
	foE(i,1,t){
		Read();
		cout<<"Case "<<i<<": " ;
		Proc();
	}
	
	return 0;
}