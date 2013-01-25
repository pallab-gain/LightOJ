/*
 * Author  : Pallab
 * Program : 1209
 *
 * 2012-02-26 07:44:51
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

#define CI( x ) scanf("%d",&x)
#define CL( x ) scanf("%lld",&x)
#define CD( x ) scanf("%lf",&x )
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


int M,F,V;
vector<int> mwant;
vector<int> fwant;
vector<int> mnwant;
vector<int> fnwant;
int nm,nf;
inline void Read() {
    CI(M);
    CI(F);
    CI(V);
    char s1,s2;
    int id1,id2;
    mwant.clear();
    fwant.clear();
    mnwant.clear();
    fnwant.clear();

    fo(i,V) {
        cin>>s1>>id1>>s2>>id2;
        //cout<<s1<<" "<<id1<<" "<<s2<<" "<<id2<<'\n';
        if (s1=='M') {
            mwant.pb(id1-1);
            fnwant.pb(id2-1);
        }
        else {
            fwant.pb(id1-1);
            mnwant.pb(id2-1);
        }
    }
}
const int maxn=(600);
int cap[maxn][maxn];
inline void build_bpnetwork() {
    nm=SZ(mwant);
    nf=SZ(fwant);
    SET(cap,0);
    fo(i,nm) {
        fo(j,nf) {
            if (mwant[i]==mnwant[j] || fnwant[i]==fwant[j]) {
                cap[i][j]=1;
            }
        }
    }
}
int used[maxn];
int mt[maxn];
int try_kuhn(int v) {
    if (used[v])return 0;
    used[v]=1;
    for (int i=0;i<nf;++i) {
        if (cap[v][i]&&(mt[i]==-1||try_kuhn(mt[i]))) {
            mt[i]=v;
            return 1;
        }
    }
    return 0;
}
inline int match() {
    build_bpnetwork();

    SET(mt,-1);
    for (int i=0;i<nm;++i) {
        SET(used,0);
        try_kuhn(i);
    }
    int d=0;
    for (int i=0;i<nm;++i) {
        if (mt[i]!=-1)++d;
    }
    //cout<<V<<' '<<d<<"\n";
    return V-d;
}
inline void Proc() {
    cout<< match();
    puts("");
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
// kate: indent-mode cstyle; space-indent on; indent-width 0; 
