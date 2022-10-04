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


const int maxn = 1e6+100;
const ll P = 998244353;

struct node {
    ll f, g, h;
}p[maxn];

int n;
int head[maxn], v[maxn<<1], num = 1, nex[maxn<<1];
ll inv2, pw2;

inline void add(int x, int y) {
    v[++num] = y, nex[num] = head[x], head[x] = num;
    v[++num] = x, nex[num] = head[y], head[y] = num;
}

inline void merge(node &A, node B, ll ms) {
    A.f = (A.f + ms * inv2 * (B.f + B.g)) % P;
    A.g = (A.g + ms * inv2 * (B.g - B.h)) % P;
    A.h = (A.h + ms * inv2 * B.h) % P;
}

void dfs1(int x, int Fa) {
    p[x].f = 0, p[x].g = 1ll*(n+2)*pw2%P, p[x].h = pw2*2%P;
    for(int i=head[x]; i; i=nex[i]) {
        int y = v[i]; if(y == Fa) continue;
        dfs1(y, x);
        merge(p[x], p[y], 1);
    }
}

void dfs2(int x, int Fa) {
    if(Fa) {
        node tmp = p[Fa];
        merge(tmp, p[x], -1);
        merge(p[x], tmp, 1);
    }
    for(int i=head[x]; i; i=nex[i])
        if(v[i] != Fa) dfs2(v[i], x);
}

inline ll poww(ll x, ll y) {
    ll tmp = 1;
    while(y) {
        if(y&1) tmp = tmp*x%P;
        x = x*x%P, y>>=1;
    }
    return tmp;
}

void initpw2() {
    inv2 = poww(2, P-2);
    pw2 = poww(2, n-2);
}

int main() {
//    freopen("nh.in", "r", stdin);
    n = read();
    initpw2();
    for(int i=1; i<n; i++)
        add(read(), read());
    dfs1(1, 0);
    dfs2(1, 0);
    ll Ans = 0;
    for(int i=1; i<=n; i++)
        Ans = (Ans + p[i].f) % P;
    Ans = (Ans * inv2 % P + P) % P;
    printf("%lld\n", Ans);
    return 0;
}







