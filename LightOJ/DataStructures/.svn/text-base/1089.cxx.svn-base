/*
 * Author  : Pallab
 * Program : 1089
 *
 * 2012-05-13 17:22:54
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
    for (int i=0;i<_size;++i) {
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

class Interval {
public:
    int s;
    int t;
    Interval(int s=0,int t=0):
            s(s),t(t) {
        ;
    }
};
const int mx = (50005);
int N,Q;
Interval intervals[mx];
int queries[mx];


class MyHash {
#define MAX_HAS_LEN (50005*3) //change accordingly
#define S int //type of points
public :
    map<S,int> mp;
    int points[MAX_HAS_LEN];
    int nPoints;
    int ID;
    inline void clearHash() {
        ID=1;
        mp.clear();
        memset(points,0,sizeof(points));
        nPoints=0;
    }
    inline void Push(int point) {
        points[nPoints]=point;
        ++nPoints;
    }
    inline void Encode() {
        sort(points,points+nPoints,less<int>());
        int prv=INT_MIN;
        for (int i=0;i<nPoints;++i) {
            if (prv!=points[i]) {
                prv=points[i];

                mp[ points[i] ]=ID;
                ++ID;
            }
        }
    }
    inline int GetId(int point) {
        return mp[point];
    }

};
class BIT {
//********************************
//REMEMBER 1[ONE] BASED INDEXING//
//********************************
#define MAX_BIT (50005*3) //change accordingly
public :
    int Tree[MAX_BIT];
    void clearBIT() {
        SET(Tree,0);
    }
    void Update(int idx,int delta) {
        if (idx<=0)return ;

        while (idx<MAX_BIT) {
            Tree[idx]+=delta;
            idx+=(idx & -idx );
        }
    }
    int Query(int idx) {
        if (idx<=0)return 0;

        int ret=0;
        while (idx>0) {
            ret+=Tree[idx];
            idx-=(idx & -idx );
        }
        return ret;
    }
};


inline void Read() {

    CI(N,Q);
    int a,b;
    fo(i,N) {
        CI(a,b);
        intervals[i].s=a;
        intervals[i].t=b;
    }
    fo(i,Q) {
        CI(a);
        queries[i]=a;
    }
}
MyHash hash;
BIT myBit;
inline void Proc() {
    hash.clearHash();
    myBit.clearBIT();
    //for all intervals
    fo(i,N) {
        hash.Push(intervals[i].s);
        hash.Push(intervals[i].t);
    }
    //for all query points
    fo(i,Q) {
        hash.Push(queries[i]);
    }

    hash.Encode();
    //run bit on all encoded intervals
    fo(i,N) {
        int a = hash.GetId( intervals[i].s );
        int b = hash.GetId( intervals[i].t );
        myBit.Update(a,1);
        myBit.Update(b+1,-1);
    }
    
    line;
    //answer the queries
    fo(i,Q) {
        int a=hash.GetId(queries[i]);
        cout<< myBit.Query(a);
        line;
    }

}
int main() {
    int tt;
    CI(tt);
    foE(i,1,tt) {
        cout<<"Case "<<i<<":";
        Read();
        Proc();
    }
    return 0;
}
