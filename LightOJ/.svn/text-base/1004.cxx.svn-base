//	ID : pallab81
// 	PROG : 1004
// 	LANG : C++
// 	2011-08-04-19.32.19 Thursday
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
int N;
vector< vector<int> > cando;
inline void proc(int cases) {
    scanf("%d",&N);
    cando.assign(2, vector<int>( N+50, 0 ));

    int i,j,var;
    for(i=1; i<N; ++i) {
        for(j=1; j<=i; ++j) {
            scanf("%d",&var);
            cando[1][j] = max( cando[0][j-1]+var, cando[0][j]+var);
        }
        swap( cando[0], cando[1] );
    }
    for(j=1; j<=N; ++j) {
        scanf("%d",&var);
        cando[1][j] = max( cando[0][j-1]+var, cando[0][j]+var);
    }
    swap(cando[0], cando[1]);
    for(i=N-1; i>=1; --i) {
        for(j=1; j<=i; ++j) {
            scanf("%d",&var);
            cando[1][j] = max( cando[0][j]+var, cando[0][j+1]+var);
        }
        swap( cando[0], cando[1]);
    }
    printf("Case %d: %d\n",cases,cando[0][1]);
}
int main() {
    //freopen("in.txt","rt",stdin);
    int cases,i;
    for( scanf("%d",&cases),i=cases; cases; --cases ) {
        proc(i-cases+1);
    }

    return 0;
}


