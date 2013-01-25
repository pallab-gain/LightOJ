#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

struct EuclidReturn {
    long long u,v,d;

    EuclidReturn(long long _u, long long _v, long long _d) {
        u = _u;
        v = _v;
        d = _d;
    }
};

EuclidReturn Extended_Euclid(long long a, long long b) {
    if (b == 0) return EuclidReturn(1,0,a);
    EuclidReturn aux = Extended_Euclid(b,a % b);
    long long v = aux.u - (a / b) * aux.v;
    return EuclidReturn(aux.v,v,aux.d);
}

long long modular_inverse(int a, int n) {
    EuclidReturn  aux = Extended_Euclid(a,n);
    return ((aux.u / aux.d) % n + n) % n;
}

long long solve(int a, int b, int c, int x1, int x2, int y1, int y2) {
    if (x1 > x2 || y1 > y2) return 0;

    if (a == 0 && b == 0) {
        if (c == 0) return (long long)(x2 - x1 + 1) * (y2 - y1 + 1);
        return 0;
    }

    if (a == 0) {
        if (c % b == 0 && y1 <= -c/b && -c/b <= y2) return x2 - x1 + 1;
        return 0;
    }

    if (b == 0) {
        if (c % a == 0 && x1 <= -c/a && -c/a <= x2) return y2 - y1 + 1;
        return 0;
    }

    int g = __gcd(abs(a),abs(b));

    if (c % g != 0) return 0;

    a /= g;
    b /= g;
    c /= g;

    if (b < 0) {
        a = -a;
        b = -b;
        c = -c;
    }

    long long k = modular_inverse((a % b + b) % b,b) * ((-c % b + b) % b) % b;
    long long k2 = (a*k + c) / b;
    long long L1 = ceil((double)(x1 - k) / b),U1 = floor((double)(x2 - k) / b),L2,U2;

    if (a < 0) {
        L2 = ceil((double)(y1 + k2) / (-a));
        U2 = floor((double)(y2 + k2) / (-a));
    } else {
        L2 = ceil((double)(-k2 - y2) / a);
        U2 = floor((double)(-k2 - y1) / a);
    }

    return max(0LL,min(U1,U2) - max(L1,L2) + 1);
}

int main() {
    int a,b,c,x1,x2,y1,y2;
    int kase;
    scanf("%d",&kase);
    for (int i=1;i<=kase;++i) {
        scanf("%d %d %d %d %d %d %d",&a,&b,&c,&x1,&x2,&y1,&y2);
        //printf("Case %d: %lld\n",i,solve(a,b,c,x1,x2,y1,y2));
        cout<<"Case "<<i<<": "<<solve(a,b,c,x1,x2,y1,y2);
        puts("");
    }

    return 0;
}
// kate: indent-mode cstyle; space-indent on; indent-width 0; 
