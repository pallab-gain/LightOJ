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

// TRI CUT BEGIN
map< int, map< char, int > > daddi;
set< string > candidate;
int key;
int global_key;

inline void _Ini(){
        daddi.clear();
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
string s1,s2,s3;
int ln1,ln2,ln3;
inline void Read(){
	cin>>s1>>s2>>s3;
	ln1 = LN(s1);
	ln2 = LN(s2);
	ln3 = LN(s3);
}


int dp[60][60][60];
int go( int i, int j, int k){
	if( i==ln1 || j==ln2 || k==ln3 ){
		return 0;
	}
	
	int &best = dp[i][j][k];
	if( best!=-1 ){
		return best;
	}
	best = 0;
	best = max( best, go( i, j, k+1 ) );
	best = max( best, go( i, j+1, k ) );
	best = max( best,  go( i+1, j, k ) ) ;
	best = max( best, go( i, j+1,k+1) );
	best = max( best,  go( i+1, j, k+1) );
	best = max( best,  go( i+1,j+1, k) );
	
	if( s1[i]==s2[j] && s1[i]==s3[k] ){
		int v = 1+go( i+1, j+1, k+1 );
		best = max( best, v );
	}
	
return best;
}

inline void Proc(){
	SET(dp,-1);
	int var = go(0,0,0);
	cout<<var<<"\n";
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
