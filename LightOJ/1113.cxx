/*
 * Author  : Pallab
 * Program : 1113.cxx
 *
 * 2012-02-16 12:37:31
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

#define CI( x ) scanf("%d",&x)
#define CL( x ) scanf("%lld",&x)
#define CD( x ) scanf("%lf",&x )
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

string cur;
deque<string> b,f;
string s1,s2;

inline void visit() {
    cin>>s2;
    b.push_back(cur);
    cur = s2;
    f.clear();
    puts(s2.c_str());
}
inline void Back() {
    if ( b.empty() ==true ) {
        puts("Ignored");
        return;
    }
    f.push_back(cur);
    cur = b.back();
    b.pop_back();
    puts(cur.c_str());
}
inline void Forward() {
    if ( f.empty() ==true ) {
        puts("Ignored");
        return ;
    }
    b.push_back(cur);
    cur = f.back();
    f.pop_back();
    puts(cur.c_str());
}
inline void solve() {
    b.clear();
    f.clear();
    cur="http://www.lightoj.com/";
    while ( cin>>s1 ) {
        if (s1=="QUIT" ) {
            return ;
        }
        else if ( s1=="VISIT" ) {
            visit();
        }
        else if ( s1=="BACK" ) {
            Back();
        }
        else {
            Forward();
        }
    }
}
int main() {
    int tt;
    CI(tt);
    foE(i,1,tt) {
        cout<<"Case "<<i<<":\n";
        solve();
    }
    return 0;
}
// kate: indent-mode cstyle; space-indent on; indent-width 0; 
