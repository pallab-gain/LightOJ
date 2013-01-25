/*
 * Author  : Xerxes
 * Program : 1083.cxx
 *
 * 2011-11-11 18:30:23
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
const int inf = (int)1023456789;
const int maxn = (int)30001;
 
 
int n;
int vi[ maxn ];
struct NODE{
    int left;
    int right;
    NODE(int left=0,int right=0)
        : left(left),right(right){};
};
NODE* area;
inline void Compile(){
    
    area = new NODE[ n ];
    stack< int > st ;
    int tmp;
    
    for(int i=0;i<n; ++i ){
        while( st.empty()==false ){
            if( vi[i] <= vi[ st.top() ] ){
                st.pop();
            }
            else{
                break;
            }
        }
        
        tmp = ( st.empty() ? -1 : st.top() ) ;
        
        area[ i ].left = i-tmp-1;
        st.push(i);
    }
    while(st.empty()==false){
        st.pop();
    }
    
    for(int i=n-1; i>=0; --i ){
        while( st.empty()==false ){
            if( vi[i] <= vi[ st.top() ] ){
                st.pop();
            }
            else{
                break;
            }
        }
        tmp = st.empty() ? n : st.top();
        area[ i ].right = tmp-i-1;
        st.push(i);
    }
    while( st.empty()==false ){
        st.pop();
    }
}
 
inline void Read(){
    CI(n);
    fo(i,n){
        CI(vi[i]);
    }
}
inline void Proc(){
    Compile();
    Int best = 0;
    fo(i,n){
        Int lhv = (Int)area[i].left;
        Int rhv = (Int)area[i].right;
        
        Int tlen = (Int)lhv+rhv+1;
        Int cur_area = (Int)tlen*vi[i];
        best = max( best, cur_area );
    }
    cout<<best<<"\n";
    delete area;
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
