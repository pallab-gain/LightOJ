/*
* Author  : Pallab
* Program : 1114_2.cxx
*
* 2012-02-14 11:41:51
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
#define Int unsigned long long
#define pb push_back
#define SZ(X) (int)(X).size()
#define LN(X) (int)(X).length()
#define mk make_pair
#define f first
#define s second
#define SET( ARRAY , VALUE ) memset( ARRAY , VALUE , sizeof(ARRAY) )


const int maxn = 10001;
const int maxw = 26*2;
map<string,int> mp;
int n;

inline void Read() {
    CI(n);
    mp.clear();
    string str;
    fo(i,n) {
        cin>>str;
        if ( LN(str) >1 ) {
            sort(str.begin()+1,str.end()-1, less<char>());
        }
        mp[ str ]++;
    }
}

inline void Proc() {
    int m;
    string str;
    scanf("%d\n",&m);
    Int res;

    while (m--) {
        res=1;
        getline(cin,str);
        stringstream ss(str);

        for (string tmp; getline(ss,tmp,' '); ) {
            if ( LN(tmp)<1 )continue;
            if ( LN(tmp)>1 ) {
                sort(tmp.begin()+1,tmp.end()-1, less<char>());
            }

            int v = mp[tmp];
            res = res*v;
            if ( res==0 )break;
        }
        cout<<res;
        puts("");
    }

}
int main() {

    int tt;
    CI(tt);
    foE(i,1,tt) {
        Read();
        cout<<"Case "<<i<<":";
        puts("");
        Proc();
    }
    return 0;
}
// kate: indent-mode cstyle; space-indent on; indent-width 0; 
