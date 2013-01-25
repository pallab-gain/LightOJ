/*
*	ID : pallab81
* 	PROG : 1347
* 	LANG : C++
* 	2012-09-11-21.36.33 Tuesday
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
#if !defined( ONLINE_JUDGE )
#define debug
#endif
const int mxn=5010;
char str[3][mxn];
inline void readString(char *ss) {
    char ch;
    while( true ) {
        ch=getchar();
        if(ch>='a'&&ch<='z') {
            int i=0;
            ss[i++]=ch;
            while( (ch=getchar())!='\n' ) {
                ss[i++]=ch;
            }
            ss[i]=0;
            return ;
        }
    }
}
inline void read() {
    fo(i,3) {
        readString(str[i]);
    }
}
namespace suffix_array {
const int maxlen = 5010*5;
const int alphabet = 256;
char s[maxlen];
int id[maxlen];
int n;
int p[maxlen], cnt[maxlen], c[maxlen];
int pn[maxlen], cn[maxlen];
inline void get_string() {
    sprintf(s,"%s%s%s",str[0],str[1],str[2]);
    n = strlen(s);
    s[n++]=0;
}
inline void assign_ids() {
    SET(id,0);
    int indx=0;
    fo(i,3) {
        fo(j,strlen(str[i])) {
            id[indx++]=i+1;
        }
    }
}
inline void build_sa() {
    memset (cnt, 0, alphabet * sizeof(int));
    for (int i=0; i<n; ++i) {
        ++cnt[s[i]];
    }
    for (int i=1; i<alphabet; ++i) {
        cnt[i] += cnt[i-1];
    }
    for (int i=0; i<n; ++i) {
        p[--cnt[s[i]]] = i;
    }
    c[p[0]] = 0;
    int classes = 1;
    for (int i=1; i<n; ++i) {
        if (s[p[i]] != s[p[i-1]]) {
            ++classes;
        }
        c[p[i]] = classes-1;
    }
    for (int h=0; (1<<h)<n; ++h) {
        for (int i=0; i<n; ++i) {
            pn[i] = p[i] - (1<<h);
            if (pn[i] < 0)  pn[i] += n;
        }
        memset (cnt, 0, classes * sizeof(int));
        for (int i=0; i<n; ++i)
            ++cnt[c[pn[i]]];
        for (int i=1; i<classes; ++i)
            cnt[i] += cnt[i-1];
        for (int i=n-1; i>=0; --i)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i=1; i<n; ++i) {
            int mid1 = (p[i] + (1<<h)) % n,  mid2 = (p[i-1] + (1<<h)) % n;
            if (c[p[i]] != c[p[i-1]] || c[mid1] != c[mid2])
                ++classes;
            cn[p[i]] = classes-1;
        }
        memcpy (c, cn, n * sizeof(int));
    }
}
int phi[maxlen],LCP[maxlen],PLCP[maxlen];
void compute_lcp() {
    phi[p[0]]=-1;
    for(int i=1; i<n; ++i) {
        phi[p[i]]=p[i-1];
    }
    int L=0;
    for (int i = 0; i < n; i++) {                  // compute Permuted LCP in O(n)
        if (phi[i] == -1) {
            PLCP[i] = 0;    // special case
            continue;
        }
        while (s[i + L] == s[phi[i] + L]) L++;
        PLCP[i] = L;
        L = max(L-1, 0);
    }
    for (int i = 1; i < n; i++) {
        LCP[i] = PLCP[p[i]];
    }
}
}
//---------------------------------------------
bool vis[10];
inline bool possible( int length) {
    int cnt=0;
    SET(vis,0);
    foR(i,1,suffix_array::n) {
        int si = suffix_array::p[i];
        int lcp = suffix_array::LCP[i];

        if( lcp<length) {
            if(cnt>0) {
                cnt=0;
                SET(vis,0);
            }
        } else {
            if(!vis[ suffix_array::id[suffix_array::p[i-1] ] ] ) {
                vis[ suffix_array::id[suffix_array::p[i-1]]]=true;
                ++cnt;
            }
            if(!vis[ suffix_array::id[suffix_array::p[i]]]) {
                vis[ suffix_array::id[suffix_array::p[i]]]=true;
                ++cnt;
            }
            if(cnt>=3)return true;
        }

    }
    return false;
}
inline int bsearch() {
    int lo = 0;
    int hi = 5010*3;
    int bst = lo;
    while(lo+1<hi) {
        int mid = (lo+hi)/2;
        if( possible(mid)) {
            lo=mid;
        } else hi=mid;
    }
    return lo;
}
inline void proc() {
    suffix_array::get_string();
    suffix_array::assign_ids();
    suffix_array::build_sa();
    suffix_array::compute_lcp();
#undef debug
#if defined(debug)
    fo(i,3) {
        puts(str[i]);
    }
#endif
//#define debug
#if defined(debug)
    puts(suffix_array::s);
    fo(i,suffix_array::n) {
        printf("%d",suffix_array::id[i]);
    }
    line;
    foR(i,1,suffix_array::n) {
        int si = suffix_array::p[i];
        int lcp = suffix_array::LCP[i];
        int id = suffix_array::id[ si ];
        printf("%d %d %d %s\n",id, lcp, si, suffix_array::s+si);
    }
    line;
#endif
    int retval=bsearch();
    cout<<retval;
    line;
}
int main() {
    int kase=1;
#if !defined ( ONLINE_JUDGE )
    freopen("in","r",stdin);
    kase=1;
#endif
    scanf("%d",&kase);
    foE(i,1,kase) {
        read();
        cout<<"Case "<<i<<": ";
        proc();
    }
    return 0;
}


