#include <bits/stdc++.h>

using ll = long long;
using namespace std;

#define qmin(x, y) (x = min(x, y))

inline int lowbit(int x) {return x&(-x);}

void solve() {
    int n, m; cin >> n >> m;
    vector<int> p(n+1);
    for(int i=1; i<=n; i++) {
        int x; cin >> x;
        p[x] = i;
    }

    if(m >= n-1) {
        printf("0\n");
        return;
    }

    vector<int> sum(n+1);
    function<void(int, int)> revise = [&](int x, int z) {
        for(int i=x; i<=n; i+=lowbit(i))
            sum[i] += z;
    };
    function<int(int)> query = [&](int x) {
        int z = 0;
        for(int i=x; i; i-=lowbit(i))
            z += sum[i];
        return z;
    };

    vector<int> nx(n+1);
    for(int i=1; i<=n; i++)
        nx[i] = i-1 - query(p[i]), revise(p[i], 1);

    function<int(int, int, int)> calc = [&](int l, int o, int d) {
        ll tmp = nx[l + d];
        for(int h=0; h<d; h++)
            if(!(o>>h&1)) tmp -= p[l+h] > p[l+d];
        return tmp;
    };

    int mx = 1 << m+1;
    vector<ll> f(mx, n*n);
    f[0] = 0;
    for(int l=1; l+m<=n; l++) {
        for(int o=0; o<mx; o++) {
            if(f[o] == n*n) continue;
            for(int d=0; d<=m; d++) {
                int dc = 1<<d;
                if(o&dc) continue;
                ll tmp = calc(l, o, d);
                qmin(f[o|dc], f[o] + tmp);
            }
        }
        for(int o=0; o<mx; o++) {
            if(o&1) f[o>>1] = f[o];
            f[o] = n*n;
        }
    }
    printf("%lld\n", f[(mx-1)>>1]);
}

int main() {
//    freopen("nh.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}