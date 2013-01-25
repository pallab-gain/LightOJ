/*
 * Author  : Pallab
 * Program : 1087
 *
 * 2012-05-09 10:11:53
 * I have not failed, I have just found 10000 ways that won't work.
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>
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
template<class T1, class T2, class T3, class T4, class T5>
inline void debug(T1 _x,T2 _y,T3 _z,T4 _zz, T5 _zzz) {
    cout<<_x<<' '<<_y<<' '<<_z<<' '<<_zz<<' '<<_zzz<<'\n';
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
#define S int
#define T int
#define MAX_SIZE 1000000
typedef struct {
    S key;
    T value;
    int size,height;
    int child[2];
}node;
node list[MAX_SIZE];
int size;
int balance(int );
int cmp(const void *a, const void *b) {
    return *((int*)a) - *((int*)b);
}
#define sz(t) (t ? list[t].size : 0 )
#define ht(t) (t ? list[t].height : 0 )
int rotate(int t,int l, int r) {
    int s=list[t].child[r];
    list[t].child[r]=list[s].child[l];
    list[s].child[l]=balance(t);

    if (t)list[t].size=sz(list[t].child[0])+sz(list[t].child[1])+1;
    if (s)list[s].size=sz(list[s].child[0])+sz(list[s].child[1])+1;
    return balance(s);
}
int balance(int t) {
    int i;
    for (i=0;i<2;++i) {
        if ( ht(list[t].child[!i]) - ht(list[t].child[i] )< -1 ) {
            if (ht(list[list[t].child[i]].child[!i])-ht(list[list[t].child[i]].child[i])>0)
                list[t].child[i]=rotate(list[t].child[i],i,!i);

            return rotate(t,!i,i);
        }
    }
    if (t)list[t].height=max( ht(list[t].child[0]),ht(list[t].child[1]))+1;
    if (t)list[t].size=sz(list[t].child[0])+ sz(list[t].child[1])+1;
    return t;
}
int move_down(int t,int rhs) {
    if (t==0)return rhs;
    list[t].child[1]=move_down(list[t].child[1],rhs);
    return balance(t);
}
int find(int t, const S* key) {
    if (t==0)return 0;
    int res = cmp(key, &list[t].key);
    if (res==0)return t;
    if (res<0)return find(list[t].child[0],key);
    return find(list[t].child[1],key);
}
int erase(int t, const S* key) {
    if (t==0)return 0;
    int res = cmp(key, &list[t].key);
    if (res==0)return move_down(list[t].child[0],list[t].child[1]);
    if (res<0)list[t].child[0]=erase(list[t].child[0],key);
    else
        list[t].child[1]=erase(list[t].child[1],key);
    list[t].size--;
    return balance(t);
}
int insert2(int t, int x) {
    if (t==0)return x;
    if (cmp(&list[x].key,&list[t].key)<=0)list[t].child[0]=insert2(list[t].child[0],x);
    else
        list[t].child[1]=insert2(list[t].child[1],x);
    list[t].size++;
    return balance(t);
}
int insert(int root, const S* key, const T* value) {
    ++size;
    list[size].size = list[size].height=1;
    memcpy(&list[size].key,key,sizeof(S));
    memcpy(&list[size].value,value,sizeof(T));
    return insert2(root,size);
}
int rank(int t, int k) {
    if (!t)return 0;
    int m = sz(list[t].child[0]);
    if (k<m)return rank(list[t].child[0],k);
    if (k==m)return t;
    return rank(list[t].child[1],k-m-1);
}
int t[MAX_SIZE*2];
inline void Proc() {
    line;
    char ch;
    int x;
    int N,Q;
    CI(N,Q);
    fo(i,N) {
        CI(t[i]);
    }
    int root=0;
    fo(i,N) {
        root = insert(root,&i,&t[i]);
    }
    int itr=N;
    while (Q--) {
        scanf("\n%c %d",&ch,&x);
        if (ch=='a') {
            t[itr]=x;
            root=insert(root,&itr,&t[itr]);
            ++itr;
            ++N;
        }
        else {
            --x;
            if (x<N) {
                T value = list[ rank(root,x) ].value;
                S key = list[ rank(root,x) ].key;
                root = erase(root, &key);
                cout<<value;
                line;
                --N;
            }
            else {
                puts("none");
            }
        }
    }
}
int main() {
    int tt;
    CI(tt);
    foE(i,1,tt) {
        cout<<"Case "<<i<<":";
        Proc();
    }
    return 0;
}

