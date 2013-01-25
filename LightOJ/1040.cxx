/*
 * Author  : Xerxes
 * Program : E.cxx
 *
 * 2011-11-10 10:11:51
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

const int inf = (int)100;
int root[ inf+10 ];
int rank[ inf+10 ];
inline void _Set(){
    fo(i,inf){
        root[i]=i;
        rank[i]=0;
    }
}
inline int _Find(int x){
    if( x!= root[x] ){
        root[x] = _Find(root[x]);
    }
return root[x];
}
inline void _Union(int x, int y){
    int rx = _Find(x);
    int ry = _Find(y);

    if( rank[rx] > rank[ry] ){
        root[ry] = rx;
    }
    else{
        root[rx] = ry;
    }
    if( rank[rx]==rank[ry] ){
        rank[ry]+=1;
    }
}


int n; // number of rooms
int c;
#define mmk( x, y, z ) mk( x, mk( y, z ) )
#define tp pair< int, pair<int, int > >

vector< tp > E;
inline void  Read(){
	CI(n);
	E.clear();
	int x;
	c=0;
	fo(i,n){
		fo(j,n){
			CI(x);
			if( x ){
				c+=x;
				E.pb( mmk(x,i,j) );
			}
		}
	}
}

inline void Proc(){
	sort(E.begin(), E.end(), less< tp >() );
	_Set();
	
	int nc=0;
	int nk=0;
	for( int i=0,j=SZ(E); ( (i<j) && (nk!=n-1) ); ++i ){
		int d = E[i].f;
		int u = E[i].s.f;
		int v = E[i].s.s;
		
		if( _Find(u)!=_Find(v) ){
			_Union(u,v);
			nc+=d;
			++nk;
		}
	}
	if( nk!=n-1 ){
		cout<<-1<<"\n";
	}
	else{
		cout<<c-nc<<"\n";
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
