/*
 * Author  : Pallab
 * Program : 1212
 *
 * 2012-02-16 13:07:13
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
#include <deque>
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
#define f first
#define s second
#define SET( ARRAY , VALUE ) memset( ARRAY , VALUE , sizeof(ARRAY) )

int n,m;
deque<int>dq;
string s;
int v;
inline void pushL() {
    if ( SZ(dq) == n ) {
        puts("The queue is full");
    }
    else {
        dq.push_front(v);
        cout<<"Pushed in left: "<<v<<"\n";
    }
}
inline void pushR() {
    if ( SZ(dq) == n ) {
        puts("The queue is full");
    }
    else {
        dq.push_back(v);
        cout<<"Pushed in right: "<<v<<"\n";
    }
}
inline void popL() {
    if ( dq.empty()==true ) {
        puts("The queue is empty");
    }
    else {
        v = dq.front();
        dq.pop_front();
        cout<<"Popped from left: "<<v<<"\n";
    }
}
inline void popR() {
    if ( dq.empty()==true ) {
        puts("The queue is empty");
    }
    else {
        v = dq.back();
        dq.pop_back();
        cout<<"Popped from right: "<<v<<"\n";
    }
}
inline void solve() {
    dq.clear();
    scanf("%d %d",&n,&m);
    while (m) {
        cin>>s;
        if (s=="pushLeft") {
            cin>>v;
            pushL();
        }
        else if (s=="pushRight") {
            cin>>v;
            pushR();
        }
        else if (s=="popLeft") {
            popL();
        }
        else {
            popR();
        }
        --m;
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
