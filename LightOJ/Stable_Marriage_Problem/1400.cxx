/*
 * Author  : Pallab
 * Program : 1400
 *
 * 2012-03-09 14:44:38
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
template<class T>
inline void debug(T _x) {
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
    mx=105
};
struct People {
    int opp;
    int aim;
    vector<int> lst;
    vector<int> priority;
    void Init(int _n) {
        opp=-1;
        aim=0;
        lst.assign(_n,0);
        priority.assign(_n,0);
    }
};
struct Request {
    int opp;
    int own;
};

People man[mx];
People woman[mx];
Request request[mx];
deque<int> q;

inline void Gale_Shapley(int n) {
    q.clear();
    int cnt,m,w;
    for (int i=0;i<n;++i)q.push_back(i);

    while (!q.empty()) {
        cnt=0;
        while (!q.empty()) {
            m=q.front();
            q.pop_front();
            request[cnt].opp=man[m].lst[man[m].aim];
            request[cnt].own=m;
            man[m].aim++;
            cnt++;
        }
        if (cnt==0)break;
        q.clear();
        for (int i=0;i<cnt;++i) {
            m=request[i].own;
            w=request[i].opp;
            if (woman[w].opp==-1||woman[w].priority[m]<woman[w].priority[woman[w].opp]) {
                if (woman[w].opp!=-1) {
                    man[woman[w].opp].opp=-1;
                    q.push_back(woman[w].opp);
                }
                woman[w].opp=m;
                man[m].opp=w;
            }
            else {
                q.push_back(m);
            }
        }

    }
}
int N;
inline void Read() {
    CI(N);

    fo(i,N) {
        man[i].Init(N);
        woman[i].Init(N);
    }

    int tmp;
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) {
            CI(tmp);
            tmp-=N;
            tmp-=1;
            man[i].lst[j]=tmp;
        }
    }
    for (int i=0;i<N;++i) {
        for (int j=0;j<N;++j) {
            CI(tmp);
            tmp-=1;
            woman[i].priority[tmp]=j;
        }
    }
}
inline void Proc() {
    Gale_Shapley(N);
    for (int i=0;i<N;++i) {
        //debug(i+1,man[i].opp+N+1);
        cout<<" ("<<i+1<<' '<<man[i].opp+N+1<<")";
    }
    line;
}
int main() {
    int tt;
    CI(tt);
    foE(i,1,tt) {
        Read();
        cout<<"Case "<<i<<":";
        Proc();
    }
    return 0;
}
