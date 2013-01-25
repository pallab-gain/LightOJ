/*
ID: pallab81
PROG:
LANG: C++
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
#include <cmath>

using namespace std;
#define p system("pause")
#define MX ((1<<31)-1)
#define MN (-1*MX)
#define ABS(x) ( (x) < (0) ? (-1*x) : (x) )
#define VI vector<int>
#define VVI vector<VI >
#define VS vector<string>
#define VC vector<char>
#define VVC vector<VC >
#define VB vector<bool>
#define VVB vector<VB >
#define PAIR pair<int,int>
#define VP vector<PAIR >
#define L_P list<PAIR >
#define IO ifstream cin(".in") ; ofstream cout(".out");

inline VI input() {
    string ss;
    VI vt;
    cin>>ss;
    for (int i=0;i<ss.length();i++) {
        vt.push_back(ss[i]-'0');
    }
    return vt;
}
inline void print(VI vt) {
    for (int i=0;i<vt.size();i++) {
        cout<<vt[i];
    }
    cout<<endl;
}

inline bool isBigger(VI sir, VI student) {
    if (sir.size()!=student.size()) {
        return (student.size()>sir.size());
    }
    else {
        for (int i=0;i<sir.size();i++) {
            if (sir[i]!=student[i]) {
                return (student[i]>sir[i]);
            }
        }
    }
    return false;
}

inline void makePalin(VI &vt) {
    int len = vt.size();
    int j = (len>>1);
    if (len&1) {
        for (int i=j+1;i<len;i++) {
            vt[i] = vt[len-(i+1)];
        }
        return ;
    }

    for (int i=j;i<len;i++) {
        vt[i] = vt[len-(i+1)];
    }
    return ;
}

inline void nextNum(VI &vt, int pos1,int pos2) {
    int len = vt.size();
    if (pos1<0) {
        vt[len-1]=1;
        vt.insert(vt.begin(),1);
        return;
    }
    if (vt[pos1]<9) {
        vt[pos1]=vt[pos2]=vt[pos1]+1;
        return;
    }

    vt[pos1]=vt[pos2]=0;
    nextNum(vt,pos1-1,pos2+1);

    return ;
}


inline void doit(VI vt) {
    VI NUM = vt;
    makePalin(vt);

    while (!isBigger(NUM,vt)) {
        int len = vt.size();
        if (len&1) {
            len>>=1;
            nextNum(vt,len,len);
        }
        else {
            len>>=1;
            nextNum(vt,len-1,len);
        }
    }
    print(vt);
    return ;
}

int main() {
    int n;
    cin>>n;
    for (int i=1;i<=n;i++) {
        VI vt = input();
	cout<<"Case "<<i<<": ";
        doit(vt);
        vt.clear();
    }
//p;
    return 0;
}
