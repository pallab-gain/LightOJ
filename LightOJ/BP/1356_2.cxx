/*
 * Author  : Pallab
 * Program : 1356_2.cxx
 *
 * 2012-03-05 02:43:19
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

enum {
    arraysize = 40005,
    maximumN = 500005
};
vector<int>G[arraysize];
int N;
int LL[arraysize], RR[arraysize];
int used[arraysize];

int bpm(int u) {
    if (used[u])
        return 0;
    used[u] = 1;
    fo(i,SZ(G[u])) {
        int v = G[u][i];
        if (RR[v] == -1 || bpm(RR[v])) {
            LL[u] = v;
            RR[v] = u;
            return 1;
        }
    }
    return 0;
}
inline int match() {
    SET(LL,-1);
    SET(RR,-1);
    bool d;
    do {
        d = true;
        SET(used,0);
        for (int u = 0; u < N; ++u) {
            if (LL[u] == -1 && bpm(u)) {
                d = false;
            }
        }
    } while (!d);
    int cnt=0;
    for (int u=0;u<N;++u) {
        if (LL[u]!=-1)++cnt;
    }
    return cnt;
}
int array[arraysize];
inline void readArray(int upto) {
    for (int i=0;i<upto;++i) {
        CI(array[i]);
    }
}
map<int,int> Index;
inline void Read() {
    CI(N);
    readArray(N);
}
int divisors[maximumN];
inline void divisorTable(int upto) {
    for (int i=1;i<upto;++i) {
        divisors[i]=i;
    }
    for (int i=2;i*i<upto;++i) {
        if (divisors[i]==i) {
            for (int j=i*i; j<upto;j+=i) {
                divisors[j]=i;
            }
        }
    }
}
int primality[arraysize];

inline void Proc() {
    SET(primality,0);
    Index.clear();
    for (int i=0;i<N;++i) {
        Index[array[i]]=i;
    }
    for (int i=0;i<N;++i) {
        int number=array[i];
        while (number!=1) {
            int divisor = divisors[number];
            while ( (number%divisor) ==0) {
                primality[i]++;
                number/=divisor;
            }
        }
    }

    fo(i,N)G[i].clear();
    for (int i=0;i<N;++i) {
        int number=array[i];
        while (number!=1) {
            int divisor=divisors[number];
            number/=divisor;
            if (Index.count(array[i]/divisor)) {
                if ( primality[i]%2 ==0 ) {
                    //debug(1,i+1,Index[array[i]/divisor]+1);
                    G[i].pb( Index[array[i]/divisor] );
                }
                else {
                    //debug(2,Index[array[i]/divisor]+1,i+1);
                    G[Index[array[i]/divisor]].pb(i);
                }
            }
            while ( (number%divisor)==0) {
                number/=divisor;
            }
        }
    }

    //debug(N,match());
    cout<<N-match();
    puts("");
}

int main() {
    divisorTable(500001);

    int tt;
    CI(tt);
    foE(i,1,tt) {
        Read();
        cout<<"Case "<<i<<": ";
        Proc();
    }

}

