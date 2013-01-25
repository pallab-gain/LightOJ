/*
 * Author  : Pallab
 * Program : 1085
 *
 * 2012-05-12 13:14:06
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
const Int mod = 1000000007LL;
inline Int domod(Int var) {
    if (var<0)var+=mod;
    return var%mod;
}
const int inf = 100000;
int numbers[inf];
int sorted[inf];
set<int> st;
int n;
int cnt;
inline void Read() {
    st.clear();
    CI(n);
    fo(i,n) {
        CI(numbers[i]);
        st.insert(numbers[i]);
    }
    int j=0;
    foit(i,st) {
        sorted[j]=(*i);
        ++j;
    }
    cnt=j;
}
inline void Preprocess() {
    fo(i,n) {
        int index = lower_bound(sorted,sorted+cnt,numbers[i])-sorted;
        numbers[i]=index+1;
    }
    //debug(numbers,n);
}
//fenwick tree start
const Int Treesize=100000;
Int Tree[Treesize+5];
inline void Init() {
    SET(Tree,0);
}
inline void Increment(int from, Int delta) {
    for ( ; from<Treesize; from=(from|(from+1))) {
        Tree[from]=domod(Tree[from]+delta);
    }
}
inline Int Sum(int at) {
    Int result=0;
    for ( ; at>=0 ; at=(at&(at+1))-1) {
        result = domod(result+Tree[at]);
    }
    return result;
}
inline Int Sum2(int from, int to) {
    return Sum(to)-Sum(from-1);
}
inline void Proc() {

    Preprocess();
    Init();
    //line;
    for (int i=0;i<n;++i) {
        int index = numbers[i];
        Int delta = Sum(index-1)+1;
        Increment(index,delta);
    }
    
    cout<<Sum(cnt);
    line;
}
int main() {
    int tt;
    CI(tt);
    foE(i,1,tt) {
        Read();
        cout<<"Case "<<i<<": ";
        Proc();
    }
    return 0;
}
