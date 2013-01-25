/*
*	 ID : pallab81
* 	PROG : 1434
* 	LANG : C++
* 	2012-05-26-06.42.24 Saturday
*
* 	"I have not failed, I have just found 10000 ways that won't work.
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
    for (int i=0; i<_size; ++i) {
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
inline void wait( double seconds ) {
    double endtime = clock()+( seconds* CLOCKS_PER_SEC );
    while( clock() < endtime ) {
        ;
    }
}

const int rr[]= {0,-1,+1,+0,+0, -1,-1,+1,+1};
const int cc[]= {0,+0,+0,-1,+1, -1,+1,+1,-1};
const string cm[]= { "*","U","D","L","R","UL","UR","DR","DL"};
int R,C;
char G[31][31];
inline void Read() {
    CI(R,C);
    fo(i,R) {
        fo(j,C) {
            cin>>G[i][j];
        }
    }
}
#define TRUE 1
#define FALSE 0
int color[17][30][30];
string name;
int ln;
int dfs(int at, int r, int c) {
    if(color[at][r][c]!=-1)return color[at][r][c];

    if( at>=ln )return color[at][r][c]=TRUE;
    fo(i,9) {
        int tr=r+rr[i];
        int tc=c+cc[i];
        if( tr<0||tc<0||tr>=R||tc>=C )continue;
        if( G[tr][tc]==name[at] ) {
            if( dfs(at+1,tr,tc)==TRUE ) {
                return color[at][r][c]=TRUE;
            }
        }
    }
    return color[at][r][c]=FALSE;
}
void backTrack(int at, int r, int c) {
    if(at>=ln)return ;
    fo(i,9) {
        int tr=r+rr[i];
        int tc=c+cc[i];
        if( tr<0||tc<0||tr>=R||tc>=C )continue;
        if( G[tr][tc]==name[at] ) {
            if( dfs(at+1,tr,tc)==TRUE ) {
                cout<<", "<<cm[i];
                backTrack(at+1,tr,tc);
            }
        }
    }
    return ;
}
inline void doit() {
    SET(color,-1);
    fo(i,R) {
        fo(j,C) {
            if( G[i][j]==name[0] && dfs(1,i,j)==TRUE ) {
                cout<<name<<" found: ";
                cout<<"("<<i+1<<","<<j+1<<")";
                backTrack(1,i,j);
                line;
                return ;
            }
        }
    }
    cout<<name<<" not found\n";

}
inline void Proc() {
    line;
//    fo(i,R){
//        debug(G[i],C);
//    }
    int q;
    CI(q);
    while(q--) {
        cin>>name;
        ln=LN(name);
        doit();
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in","rt",stdin);
#endif
    int tt;
    CI(tt);
    foE(i,1,tt) {
        Read();
        cout<<"Case "<<i<<":";
        Proc();
    }


    return 0;
}
