/*
 * Author  : Xerxes
 * Program : F.cxx
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

// TRI CUT BEGIN
map< char, int > daddi[ (int)100000 ];
int key;

inline void _Ini(){
	fo(i, (int)100000 ){
		daddi[i] = map<char,int>();
	}
	key = (int)1;
	
	map< char, int > &sons = daddi[key];
	sons = map<char,int>();
	++key;
}
inline int _Find(int id, char letter){
	map<char, int > &sons = daddi[id];
	if( sons.count(letter) ){
		return sons[letter];
	}
	return -1;
}
inline void _Add(int id, char letter){
	map<char,int > &sons = daddi[id];
	sons.insert( mk(letter,key) );
	daddi[key] = map<char,int>();	
	
	++key;
}
inline void _Go(string line, int id= (int)1 ){
	for( int i=0,j=LN(line); i<j; ++i ){
		char letter = line[i];
		int signal = _Find(id,letter);
		if( signal== (int)-1 ){
			int tkey = key;
			_Add(id, letter);
			id = tkey;
		}
		else{
			id = signal;
		}	
	}
}
inline int _isPrefix(string line, int id= (int)1){
	for( int i=0,j=LN(line); i<j; ++i ){
		char letter = line[i];
		int signal = _Find(id,letter);
		if( signal== (int)-1 ){
			return (int)0;
		}
		else{
			id = signal;
		}
	}
return (int)1;
}
// TRI CUT ENDS

const int MAXN = (int)10000 ;
string str[ MAXN ];
int N;

bool cmp(string s1, string s2){
	int l1 = LN(s1);
	int l2 = LN(s2);
	if( l1!=l2 ){
		return l1 > l2 ;
	}
return s1 < s2 ;
}
inline void Read(){
	CI(N);
	fo(i,N){
		cin>>str[i];
	}
	sort( str, str+N, cmp);
}

inline void Proc(){
	_Ini();
	fo(i,N){
		// search prefix
		int var = _isPrefix(str[i]);
		if( var==1 ){
			cout<<"NO\n";
			return ;
		}
		//build tri
		_Go(str[i]);
	}
	cout<<"YES\n";
}

int main() {
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;++i){
		Read();
		cout<<"Case "<<i<<": ";
		Proc();
	}
	return 0;
} 
