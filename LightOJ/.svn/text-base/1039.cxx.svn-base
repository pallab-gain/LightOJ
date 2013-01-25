/*
 * Author  : Pallab
 * Program : 1039
 *
 * 2012-03-06 16:27:01
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
#define line puts("")


inline int decode(string &str) {
    int v=0;
    fo(i,3) {
        v=(v*100)+((str[i]-'a')+1);
    }
    return v;
}
inline char move1(char v) {
    if (v=='z')return 'a';
    ++v;
    return v;
}
inline char move2(char v) {
    if (v=='a')return 'z';
    --v;
    return v;
}
inline string MOVE1(string &str, int k) {
    string tmp="";
    fo(i,3) {
        if (i==k) {
            tmp+=move1(str[i]);
        }
        else {
            tmp+=str[i];
        }
    }
    return tmp;
}
inline string MOVE2(string &str, int k) {
    string tmp="";
    fo(i,3) {
        if (i==k) {
            tmp+=move2(str[i]);
        }
        else {
            tmp+=str[i];
        }
    }
    return tmp;
}
string s;
string e;
int forbid;
int forbidden[51][27][27];
inline void Read() {
    SET(forbidden,0);
    cin>>s>>e;
    CI(forbid);
    string str;
    fo(k,forbid) {
        fo(i,3) {
            cin>>str;
            fo(j,LN(str)) {
                forbidden[k][i][str[j]-'a']=1;
                //debug(k,i,str[j]-'a');
            }
        }
    }
}
inline bool Bad(string &str) {
    fo(i,forbid) {
        bool f=true;
        fo(j,3) {
            f&=(forbidden[i][j][ str[j]-'a' ] );
        }
        if (f)return true;
    }
    return false;
}
int move[1000000];
inline int bfs() {
    if ( Bad(s) )return -1;
    if ( Bad(e) )return -1;
    SET(move,63);
    queue<string>q;

    q.push(s);
    move[decode(s)]=0;
    while (!q.empty()) {
        string u=q.front();
        int d=move[ decode(u)];

        if (u==e)return d;
        q.pop();
        fo(i,3) {
            string v1=MOVE1(u,i);
            string v2=MOVE2(u,i);
            if ( d+1<move[decode(v1)] && !Bad(v1)) {
                move[decode(v1)]=d+1;
                q.push(v1);
            }
            if ( d+1<move[decode(v2)] && !Bad(v2)) {
                move[ decode(v2)]=d+1;
                q.push(v2);
            }
        }

    }

    return -1;
}
inline void Proc() {
    cout<<bfs();
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
