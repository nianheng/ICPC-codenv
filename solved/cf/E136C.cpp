#include <bits/stdc++.h>

using ll = long long;
using namespace std;

const int maxn = 110;
const ll P = 998244353;

ll jc[maxn], ijc[maxn];

inline ll C(ll x, ll y) {
    return jc[x]*ijc[y]%P*ijc[x-y]%P;
}

void solve() {
    int n; cin >> n;
    vector<array<int, 3> > f(n+1);
    f[0][1] = 1;
    for(int i=2; i<=n; i++) {
        f[i][1] = f[i-2][1];
        f[i][2] = C(i-1, i/2) + f[i-2][0];
        if(f[i][2] >= P) f[i][2] -= P;
        f[i][0] = C(i, i/2) - f[i][1];
        if(f[i][0] < 0) f[i][0] += P;
        f[i][0] = f[i][0] - f[i][2];
        if(f[i][0] < 0) f[i][0] += P;
    }
    printf("%d %d %d\n", f[n][2], f[n][0], f[n][1]);
}

inline ll poww(ll x, ll y) {
    ll tmp = 1;
    while(y) {
        if(y&1) tmp = tmp*x%P;
        x = x*x%P, y>>=1;
    }
    return tmp;
}

void initjc() {
    jc[0] = 1;
    for(int i=1; i<=100; i++)
        jc[i] = jc[i-1]*i%P;
    ijc[100] = poww(jc[100], P-2);
    for(int i=99; i>=0; i--)
        ijc[i] = ijc[i+1]*(i+1)%P;
}

int main() {
//    freopen("nh.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    initjc();
    int T; cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}