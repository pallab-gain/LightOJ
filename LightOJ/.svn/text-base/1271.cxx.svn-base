/*
 * Author  : Xerxes
 * Program : 1271.cxx
 *
 * 2011-11-14 13:36:29
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
const int maxn = 50005;
const int inf = (int)1023456789;
int N;
int vi[ maxn ];
map< int, set<int> > E;
inline void Read(){
    E.clear();
    CI(N);
    fo(i,N){
        CI( vi[i] );
    }
    for(int i=1;i<N;++i ){
        E[ vi[i-1] ].insert( vi[i] );
        E[ vi[i] ].insert( vi[i-1] );
    }
}
int D[ maxn ];
int F[ maxn ];
 
inline void bfs(int s, int e){
    queue< int > q;
    fo(i,maxn){
        D[i] = inf ;
        F[i] = inf ;
    }
    D[s]=0;
   
    q.push(s);
   
    while( q.empty()==false ){
        int f = q.front();
        q.pop();
       
        set< int > cango = E[ f ];
        foit( it, cango ){
            int c = (*it);
            int d = D[ f ] + 1;
           
            if( d < D[ c ] ){
               
                    D[c]=d;
                    F[c]= f;
                    q.push(c);
               
            }
        }
    }
    stack<int> st;
    while(  e != s ){
        st.push( e );
        e = F[e];
    }
    cout<<s;
    while( st.empty()==false ){
        cout<<' '<<st.top();
        st.pop();
    }
    cout<<"\n";
}
inline void Proc(){
    bfs( vi[0], vi[N-1] );
}
 
int main() {
   
    int t;
    CI(t);
    for(int i=1;i<=t;++i){
        Read();
        cout<<"Case "<<i<<":\n";
        Proc();
    }
   
    return 0;
} 