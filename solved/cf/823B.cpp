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


const int maxn = 1e5+100;

void Solve() {
    int n = read();
    vector<arr> vc(n);
    for(auto &[x, _] : vc)
        x = read();
    for(auto &[_, y] : vc)
        y = read();
    sort(vc.begin(), vc.end());
    vector<ll> f(n), g(n);
    f[0] = vc[0][1];
    for(int i=1; i<n; i++)
        f[i] = max(f[i-1] + vc[i][0] - vc[i-1][0], 1ll*vc[i][1]);
    g[n-1] = vc[n-1][1];
    for(int i=n-2; i>=0; i--)
        g[i] = max(g[i+1] + vc[i+1][0] - vc[i][0], 1ll*vc[i][1]);
    double Ans = 1e18;
    double pos = 0;
    for(int i=0; i<n; i++) {
        double tmp = 1.0*max(g[i], f[i]);
        if(tmp < Ans) Ans = tmp, pos = vc[i][0];
    }
    for(int i=0; i<n-1; i++) {
        double now = 1.0*(g[i+1] - f[i] + vc[i][0] + vc[i+1][0])/2;
        if(now < 1.0*vc[i][0] || now > 1.0*vc[i+1][0])
            continue;
        double tmp = 1.0*(f[i] + g[i+1] + vc[i+1][0] - vc[i][0])/2;
        if(tmp < Ans) Ans = tmp, pos = now;
    }
    if(ll(pos) != ll(pos + 0.6)) printf("%lld.5\n", ll(pos));
    else printf("%lld\n", ll(pos));
}

int main() {
//    freopen("nh.in", "r", stdin);
    int T = read();
    while(T--) {
        Solve();
    }
    return 0;
}





