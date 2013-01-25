/*
 * 		Author : Xerxes
 * 		Program: 
 * 		Created On : 28.09.2011 13:10:35 BDT
 *      "I have not failed, I have just found 10000 ways that won't work.
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
#define fo(i,st,ed) for(int i = st ; i < ed ; ++i )
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
#define tp pair< int, pair<int,int> >
#define mmk( x, y , z ) mk( x, mk( y, z ) )

inline void wait( double seconds ){
    double endtime = clock()+( seconds* CLOCKS_PER_SEC );
    while( clock() < endtime ){
        ;
    }
}
int K=1;
Int N;
string name;

inline void Read(){
		cin>>N>>name;
}
inline void Proc(){
	printf("Case %d: ",K);
	if( name=="Alice" ){
		if( ( N-1 )%3 == 0 ){
			cout<<"Bob\n";
		}
		else{
			cout<<"Alice\n";
		}
	}
	else{
		if( N%3==0 ){
			cout<<"Alice\n";
		}
		else{
			cout<<"Bob\n";
		}
	}
}

int main(){
	/*
    #ifndef ONLINE_JUDGE
        freopen("in.txt","rt",stdin);
    #endif
    */
    int cases=1;
    for( CI(cases) ; cases ; --cases,++K ){
       Read();
       Proc(); 
    }

return 0;
}


