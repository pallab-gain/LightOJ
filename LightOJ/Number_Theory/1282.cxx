/*
 * Author  : Pallab
 * Program : 1282
 *
 * 2012-05-02 16:25:24
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
  for (int i=0;i<_size;++i) {
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
const Int mod = 1000LL;
inline Int domod(Int x){
  if(x<0)x+=mod;
  return x%mod;
}
inline Int fastPow(Int a, Int b) {
    Int x= (Int)1,y= domod(a);
    while (b>0) {
        if (b&1) {
            x= domod(x*y);
        }
        y=domod(y*y);
        b>>=1;
    }
    return domod(x);
}
inline Int fun(Int p, Int q){
//   Let C = A^B, 
//   log(C) = B*log(A), log - decimal logarithm log(x) = ln(X)/ln(10). 
//   First three digits of C are first three digits of mantissa of log(C). 

   double part1 = log10(p)*q;
   //extrac the fractional part of part1[ fmod(float/double_number,1) ] plus add 2
   //http://www.cplusplus.com/reference/clibrary/cmath/fmod/
   //and store it in part2
   double part2 =  fmod(part1,1) +2;
   double tmp =  pow(10., part2);
   return (Int)tmp;
}
int n,k;
inline void Read() {
  CI(n,k);
}
inline void Proc() {
    printf("%03lld %03lld\n",fun(n,k),fastPow(n,k));
}
int main(){
  int tt;
  CI(tt);
  foE(i,1,tt){
    Read();
    cout<<"Case "<<i<<": ";
    Proc();
  }
  return 0;
} 
