#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef array<int, 2> arr;

#define qmin(x, y) (x = min(x, y))
#define qmax(x, y) (x = max(x, y))
#define mp(x, y) make_pair(x, y)

inline int read() {
    int tmp = 0, fh = 1;
    char ch = getchar();
    while(!isdigit(ch)) {
        if(ch == '-') fh = -1;
        ch = getchar();
    }
    while(isdigit(ch))
        tmp = (tmp<<1) + (tmp<<3) + ch - '0', ch = getchar();
    return tmp * fh;
}


const int maxn = 4100;
const ll P = 1e9+7;

int n;
ll a[maxn], b[maxn][maxn];
ll f[maxn*2];

inline ll C(ll x) {
    return x*(x+1)/2;
}

inline void add(ll &x, const ll &y) {
    x += y;
    if(x >= P) x -= P;
}

inline void del(ll &x, const ll &y) {
    x -= y;
    if(x < 0) x += P;
}

void calcA2() {
    for(int i=1; i<=n; i++)
        for(int j=i; j<=n; j++) {
            ll tmp = C(n-j) * b[i][j] % P;
            if(i != j) tmp = tmp * 2 % P;
            add(f[i+j], tmp);
        }
}

void calcC2() {
    for(int i=1; i<=n; i++)
        for(int j=i; j<=n; j++) {
            ll tmp = C(i-1) * b[i][j] % P;
            if(i != j) tmp = tmp * 2 % P;
            add(f[i+j], tmp);
        }
}

void calcB2() {
    vector<ll> da(2*n+6);
    for(int i=1; i<=n; i++)
        for(int j=i; j<=n; j++) {
            ll l = 2 - i + j;
            ll ml = i+j, mr = 2*(n+1) - i-j;
            if(ml > mr) swap(ml, mr);
            ll r = 2*n + i - j;
            ll tmp = (i == j) ? 1 : 2;
            tmp = tmp * b[i][j] % P;
            add(da[l], tmp), del(da[ml+2], tmp);
            del(da[mr+2], tmp), add(da[r+4], tmp);
        }
    for(int i=2; i<=n*2; i++)
        add(da[i], da[i-2]);
    for(int i=2; i<=n*2; i++)
        add(da[i], da[i-2]), add(f[i], da[i]);
}

void calc2AB() {
    vector<ll> da(2*n+6);
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++) {
            ll l = 2*i + 1;
            ll ml = 2*i - j + n + 1, mr = j + i;
            if(ml > mr) swap(ml, mr);
            ll r = n + i;
            ll tmp = 2;
            tmp = tmp * b[i][j] % P;
            add(da[l], tmp), del(da[ml+1], tmp);
            del(da[mr+1], tmp), add(da[r+2], tmp);
        }
    for(int i=2; i<=n*2; i++)
        add(da[i], da[i-1]);
    for(int i=2; i<=n*2; i++)
        add(da[i], da[i-1]), add(f[i], da[i]);
}

void calc2BC() {
    vector<ll> da(2*n+6);
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++) {
            ll l = 1 + j;
            ll ml = i + j, mr = 2 * j - i;
            if(ml > mr) swap(ml, mr);
            ll r = 2*j - 1;
            ll tmp = 2;
            tmp = tmp * b[i][j] % P;
            add(da[l], tmp), del(da[ml+1], tmp);
            del(da[mr+1], tmp), add(da[r+2], tmp);
        }
    for(int i=2; i<=n*2; i++)
        add(da[i], da[i-1]);
    for(int i=2; i<=n*2; i++)
        add(da[i], da[i-1]), add(f[i], da[i]);
}

void calc2AC() {
    for(int i=1; i<=n; i++)
        for(int j=i+2; j<=n; j++)
            add(f[i+j], C(j-i-1) * 2 * b[i][j] % P);
}

void printans() {
    for(int i=2; i<=2*n; i++)
        printf("%lld\n", f[i]);
}

inline void inits() {
    n = read();
    for(int i=1; i<=n; i++)
        a[i] = read();
    for(int i=1; i<=n; i++)
        for(int j=i; j<=n; j++)
            b[i][j] = a[i] * a[j] % P;
}

void delsbctr() {
    for(int i=1; i<=n; i++)
        for(int j=i; j<=n; j++)
            if(i == j) del(f[i+j], b[i][j]*n%P);
            else del(f[i+j], b[i][j]*n%P*2%P);
}

int main() {
//    freopen("nh.in", "r", stdin);
    inits();
    calcA2();
    calcC2();
    calcB2();
    calc2AB();
    calc2BC();
    calc2AC();
    delsbctr();
    printans();
    return 0;
}







