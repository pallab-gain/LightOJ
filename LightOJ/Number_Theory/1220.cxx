/*
*	ID : pallab81
* 	PROG : 1220
* 	LANG : C++
* 	2012-03-18-16.20.39 Sunday
*
* 	"I have not failed, I have just found 10000 ways that won't work.
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
#include <deque>
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


#define foR(i1,st,ed) for(int i1 = st , j1 = ed ; i1 < j1 ; ++i1 )
#define fo(i1,ed) foR( i1 , 0 , ed )
#define foE(i1,st,ed) foR( i1, st, ed+1 )
#define foit(i, x) for (typeof((x).begin()) i = (x).begin(); i != (x).end(); i++)
#define bip system("pause")
#define Int long long
#define pb push_back
#define SZ(X) (int)(X).size()
#define LN(X) (int)(X).length()
#define mk make_pair
#define SET( ARRAY , VALUE ) memset( ARRAY , VALUE , sizeof(ARRAY) )
#define line puts("")

template<class T1>
inline void debug(T1 _x) {
    cout<<_x<<'\n';
}
template<class T1, class T2>
inline void debug(T1 _x,T2 _y) {
    cout<<_x<<' '<<_y<<'\n';
}
template<class T1, class T2, class T3>
inline void debug(T1 _x,T2 _y,T3 _z) {
    cout<<_x<<' '<<_y<<' '<<_z<<'\n';
}
template<class T1, class T2, class T3, class T4>
inline void debug(T1 _x,T2 _y,T3 _z,T4 _zz) {
    cout<<_x<<' '<<_y<<' '<<_z<<' '<<_zz<<'\n';
}
template< class T1>
inline void debug(T1 _array,int _size) {
    cout<<"[";
    for (int i=0; i<_size; ++i) {
        cout<<' '<<_array[i];
    }
    puts(" ]");
}
inline bool CI(int &_x) {
    return scanf("%d",&_x)==1;
}
inline bool CI(int &_x, int &_y) {
    return CI(_x)&&CI(_y) ;
}
inline bool CI(int &_x, int &_y, int &_z) {
    return CI(_x)&&CI(_y)&&CI(_z) ;
}
inline bool CI(int &_x, int &_y, int &_z, int &_zz) {
    return CI(_x)&&CI(_y)&&CI(_z)&&CI(_zz) ;
}
inline void wait( double seconds ){
    double endtime = clock()+( seconds* CLOCKS_PER_SEC );
    while( clock() < endtime ){
        ;
    }
}
inline Int fastPow(Int x, Int y) {
    Int res= (Int)1;
    for ( ; y ; ) {
        if ( (y&1) ) {
            res*= x;
        }
        x*=x;
        y>>=1;
    }
    return res;
}
const double eps=(double)1e-9;
Int N;
inline void Read(){
    cin>>N;
}
inline double get(int i){
    double x = ( (double)1. )/i;
    return (x)+eps;
}
inline void Proc(){
    int best=1;
    Int _N=( N<0 ? -N : N ) ;
    for(int i=1;i<=32;++i){
        Int tmp1 = (Int)pow( (double)_N, get(i) ) ;
        Int tmp2 = fastPow(tmp1,i);
        //debug(N,tmp1,tmp2);
        if(tmp2==_N){
            if( ( N<0 && (i&1) )||(N>0) )
                best=max(best,i);
        }
    }
    cout<<best;
    line;
}

int main(){
	#ifndef ONLINE_JUDGE
        freopen("in","rt",stdin);
	#endif
	int tt;
	CI(tt);
	foE(i,1,tt){
		Read();
		cout<<"Case "<<i<<": ";
		Proc();
	}


return 0;
}

