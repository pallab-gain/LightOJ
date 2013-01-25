/*
 * Author  : Pallab
 * Program : 1421.cxx
 *
 * 2012-03-05 23:23:34
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
inline void debug(int _x) {
    cout<<_x<<'\n';
}
inline void debug(int _x,int _y) {
    cout<<_x<<' '<<_y<<'\n';
}
inline void debug(int _x,int _y,int _z) {
    cout<<_x<<' '<<_y<<' '<<_z<<'\n';
}
inline void debug(int _x,int _y,int _z,int _zz) {
    cout<<_x<<' '<<_y<<' '<<_z<<' '<<_zz<<'\n';
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
enum {
    maxn=(int)1e5+10
};
int n;
int numbers[maxn];
inline void Read() {
    CI(n);
    fo(i,n) {
        CI(numbers[i]);
    }
}
int LIS[2][maxn];
int B[maxn];
inline void lis(int id) {
    LIS[id][0]=1;
    B[0]=numbers[0];
    int maxLen=1;
    for (int i=1;i<n;++i) {
        int number=numbers[i];
        int lowerbound=lower_bound(B,B+maxLen,number)-B;
        LIS[id][i]=lowerbound+1;
        if (lowerbound==maxLen) {
            B[maxLen++]=number;
        }
        else {
            B[lowerbound]=number;
        }
    }

}
inline void Proc() {
    lis(0);
    reverse(numbers,numbers+n);
    lis(1);

    int best=0;
    fo(i,n) {
        //debug(i,LIS[0][i],LIS[1][i]);
        best=max(best, min(LIS[0][i],LIS[1][(n-1)-i]) );
    }
    cout<<(best<<1)-1;
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

}

