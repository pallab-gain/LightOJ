/*
  * Author  : Pallab
  * Program : 1047.cxx
  *
  * 2011-11-20 16:55:03
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
 
 const int maxn = 20;
 const int inf = (int)1e9;
 int matrix[maxn][ 3 ];
 int dp[ maxn ][ 3 ];
 int n;
 
 inline void Read(){
     CI(n);
     fo(i,n){
        fo(j,3){
            CI(matrix[i][j]);
        }
     }
 }
 
 //color
 //0
 //1
 //2
 
 int go( int curr_neighbour, int pre_color ){
        if( curr_neighbour== n ){
            return 0;
        }
       
       
        if( dp[ curr_neighbour ][ pre_color ]!=-1 ){
            return dp[ curr_neighbour ][ pre_color ];
        }
       
        int best = inf;
        if( curr_neighbour==0 ){
            fo(i,3){
                int v = matrix[curr_neighbour][i] +go( curr_neighbour+1, i );
                best = min( best, v );
            }
        }
        else{
            fo(i,3){
                if( pre_color!=i ){
                    int v = matrix[curr_neighbour][i] + go( curr_neighbour+1, i );
                    best = min( best, v );
                }
            }
           
        }
       
    return dp[ curr_neighbour ][ pre_color ]=best;
 }
 
 inline void Proc(){
     SET( dp, -1 );
     int retval = go( 0, 0 );
     cout<<retval<<"\n";
 }
 
 int main() {
     
     int t;
     CI(t);
     foE(i,1,t){
         Read();
         cout<<"Case "<<i<<": ";
         Proc();
     }
     
     return 0;
 }
 