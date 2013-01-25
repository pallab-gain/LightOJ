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
double x11,y11,r11;
double x22,y22,r22;

inline void Read(){
	cin>>x11>>y11>>r11;
	cin>>x22>>y22>>r22;
}
/*
 * Double part1 = r*r*Math.acos((d*d + r*r - R*R)/(2*d*r));
Double part2 = R*R*Math.acos((d*d + R*R - r*r)/(2*d*R));
Double part3 = 0.5*Math.sqrt((-d+r+R)*(d+r-R)*(d-r+R)*(d+r+R));

Double intersectionArea = part1 + part2 - part3;
 */

inline double two(double x){
	return x*x;
}
inline double dist(){
	return sqrt( two(x11-x22)+two(y11-y22) ) ;
}
inline void Proc(){
	
	double r = r11;
	double R = r22;
	double d = dist();
	if( R < r ){
		swap(R,r);
	}
	
	double part1 = two(r)*acos(( two(d) + two(r) - two(R))/(2*d*r));
	double part2 = two(R)*acos(( two(d) + two(R) - two(r))/(2*d*R));
	double part3 = (double)0.5*sqrt((-d+r+R)*(d+r-R)*(d-r+R)*(d+r+R));

	double intersectionArea = part1 + part2 - part3;
	printf("%.8lf\n",intersectionArea);
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
