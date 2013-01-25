/*
 * Author  : Xerxes
 * Program : A.cxx
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
string s1,s2;
string ss1,ss2;

inline void Read(){
	getline(cin,s1);
	getline(cin,s2);
	ss1=ss2="";
	for(int i=0,j=LN(s1);i<j;++i ){
		if( s1[i]==' ' )continue;
		ss1+= tolower(s1[i]);
	}
	for(int i=0,j=LN(s2);i<j;++i ){
		if( s2[i]==' ' )continue;
		ss2+= tolower(s2[i]);
	}
	sort(ss1.begin(),ss1.end(),less<char>() );
	sort(ss2.begin(),ss2.end(),less<char>() );
}
inline void Proc(){
	if( ss1==ss2 ){
		cout<<"Yes\n";
	}
	else{
		cout<<"No\n";
	}
}
int main() {
	
	int t;
	scanf("%d\n",&t);
	for(int i=1;i<=t;++i){
		Read();
		cout<<"Case "<<i<<": ";
		Proc();
	}
	
	return 0;
} 
