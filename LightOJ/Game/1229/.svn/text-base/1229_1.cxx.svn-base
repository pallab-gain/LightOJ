/*
 *  1229_1.cxx
 *
 * 	Author : Pallab
 * 	Created on: 9:45:13 PM - 2012:12:25
 * 	"I have not failed, I have just found 10000 ways that won't work."
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
#include <numeric>
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

#define bip system("pause")
#define Int long long
#define pb push_back
#define SZ(X) (int)(X).size()
#define LN(X) (int)(X).length()
#define mk make_pair
#define SET( ARRAY , VALUE ) memset( ARRAY , VALUE , sizeof(ARRAY) )
#define line puts("")

inline void wait ( double seconds ) {
    double endtime = clock() + ( seconds * CLOCKS_PER_SEC );
    while ( clock() < endtime ) {
        ;
    }
}
template<class T>
    inline T fastIn() {
    register char c=0;
    register T a=0;
    bool neg=false;
    while ( c<33 ) c=getchar();
    while ( c>33 ) {
        if ( c=='-' ) {
            neg=true;
        } else {
            a= ( a*10 ) + ( c-'0' );
        }
        c=getchar();
    }
    return neg?-a:a;
}
inline void readword ( char *buffer, int &cnt ) {
    int c;
    cnt=0;
    c = getchar();
    while ( c >= 0 && c <= ' ' ) {
        c = getchar();
    }
    if ( c < 0 ) {
        buffer[cnt] = 0;
        return;
    }
    while ( c > ' ' ) {
        buffer[cnt++] = c;
        c = getchar();
    }
    buffer[cnt] = 0;
}
char board[205];
int boardLen;
bool wins[205];
bool seen[205];
int grundy[205];

inline void read() {
    readword ( board, boardLen );
}
inline bool samne3 ( int at ) {
    int xCount=0,dCount=0;
    for ( int i=1,k=0; i<=3; ++i,++k ) {
        if ( at+k>=boardLen ) return false;
        if ( board[at+k]=='X' ) ++xCount;
        else ++dCount;
    }
    return dCount==1&&xCount==2;
}
inline bool pichone3 ( int at ) {
    int xCount=0,dCount=0;
    for ( int i=1,k=0; i<=3; ++i,--k ) {
        if ( at+k<0 ) return false;
        if ( board[at+k]=='X' ) ++xCount;
        else ++dCount;
    }
    return dCount==1&&xCount==2;
}
inline bool safe ( int at ) {
    for ( int i=-2; i<=+2; ++i ) {
        if ( at+i<0||at+i>=boardLen ) continue;
        if ( board[at+i]=='X' ) return false;
    }
    return true;
}
inline int find_grundy ( int n ) {
    if ( seen[n] ) return grundy[n];
    seen[n]=true;

    int &result=grundy[n];
    if ( n==0 ) return result=0;
    if ( n==1 ) return result=1;

    bool mex[20]={false};
    for ( int i=1,l=0,r=n-1; i<=n; ++i,++l,--r ) {
        int v1=find_grundy ( max ( 0, l-2 ) );
        int v2=find_grundy ( max ( 0, r-2 ) );
        mex[v1^v2]=true ;
    }
    result=0;
    while ( mex[ result ] ) ++result;

    return result;
}

inline void simulate() {
    for ( int i=0; i<boardLen; ++i ) {
        if ( wins[i] ) continue;
        if ( board[i]=='.'&& safe ( i ) ) {
            board[i]='X';
            int x=0,cnt=0,xOR=0,indx;
            for ( int j=0; j<boardLen; ) {
                if ( board[j]=='X' ) {
                    ++j;
                } else {
                    cnt=0,indx=j;
                    while ( j<boardLen && board[j]=='.' ) {
                        ++cnt;
                        ++j;
                    }
                    if ( indx==0||j>=boardLen ) x=1;
                    else x=2;

                    xOR^= find_grundy ( max ( 0,cnt-2*x ) );
                }
            }
            if ( !xOR ) wins[i]=true;
            board[i]='.';
        }
    }

}
inline void proc() {
    //for ( int i=0; i<=boardLen; ++i ) cout<<i<<' '<<grundy[i]<<'\n';
    SET ( wins,false );

    //I can win in just one single moves
    bool checked_single=false;
    for ( int i=0; i<boardLen; ++i ) {
        if ( wins[i] ) continue;

        if ( samne3 ( i ) ) {
            if ( board[i]=='.' ) wins[i]=checked_single=true;
            else if ( board[i+1]=='.' ) wins[i+1]=checked_single=true;
            else if ( board[i+2]=='.' ) wins[i+2]=checked_single=true;
        } else if ( pichone3 ( i ) ) {
            if ( board[i]=='.' ) wins[i]=checked_single=true;
            else if ( board[i-1]=='.' ) wins[i-1]=checked_single=true;
            else if ( board[i+2]=='.' ) wins[i-2]=checked_single=true;
        }
    }
    //if no win in just next move found
    if ( checked_single==false ) {
        simulate();
    }

    int yes=true;
    for ( int i=0; i<boardLen; ++i ) {
        if ( wins[i] ) {
            cout<<' '<<i+1;
            yes=false;
        }
    }
    if ( yes ) puts ( " 0" );
    else puts ( "" );

}
int main() {
    SET ( seen,false );
    for ( int i=0; i<=200; ++i ) find_grundy ( i );

    int kase = 1;
#if defined( xerxes_pc )
    freopen ( "in1", "r", stdin );
    kase = 1;
#endif
    kase=fastIn<int>();
    for ( int i=1; i<=kase; ++i ) {
        read();
        cout<<"Case "<<i<<":";
        proc();
    }
    return 0;
}

// kate: indent-mode cstyle; indent-width 4; replace-tabs on;
