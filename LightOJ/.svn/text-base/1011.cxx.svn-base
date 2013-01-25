//	ID : pallab81
// 	PROG : 1011
// 	LANG : C++
// 	2011-08-04-22.07.31 Thursday
//
// 	"I have not failed, I have just found 10000 ways that won't work.
//


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

#include <cassert>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <cstring>

using namespace std;

#define fo(i,ed) for(int i = 0 ; i < ed ; ++i )
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

int pi[ 20 ][ 20 ] ; //priority index of man-woman
int cando[ 20 ][ 1<<17 ];
int N; // number of male and number of female

inline void read() {
    scanf("%d",&N);
    fo(i,N) {
        fo(j,N) {
            scanf("%d",&pi[i][j]);
        }
    }
}
inline int isSelected(int mask, int index) {
    return mask& ( (int)1<<index) ;
}
inline int select( int mask, int index ) {
    return  mask| ((int)1<<index)  ;
}
inline int go(int now_male, int mask) {
    if(now_male==N) {
        return 0;
    }
    int &best = cando[ now_male ][ mask ];
    if( best!=-1 ) {
        return best;
    }
    int i;
    best = 0;
    //choosing female for current male

    for(i=0; i<N; ++i) {
        if(isSelected(mask,i) )continue;
        // if this woman is not already selected
        int var = pi[ now_male ][ i ];
        int bit = select(mask,i);
        best = max( best, var+go( now_male+1, bit ) );

    }

    return best;
}
inline void proc(int cases) {
    SET( cando, -1);
    printf("Case %d: %d\n",cases,go(0,0));
}
int main() {
    //freopen("in.txt","rt",stdin);
    //cout<<sizeof(cando)/1024/1024<<"\n";
    //cout<<sizeof(pi)/1024/1024<<"\n";
    int cases,tot;
    for( scanf("%d",&cases), tot = cases; cases; --cases ) {
        read();
        proc( tot-cases+1 );
    }

    return 0;
}


