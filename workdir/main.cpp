#include<bits/stdc++.h>

#define mp(x, y) make_pair(x, y)
#define qmin(x, y) (x = min(x, y))
#define qmax(x, y) (x = max(x, y))

using ll = long long;
using namespace std;

typedef pair<int, int> pii;
typedef array<int, 2> arr;

const ll inf = 1e14;

//const int maxn = ;
//const ll P = ;

inline void solve() {
    int n, m; cin >> n >> m;
    vector<vector<ll> > f(n, vector<ll>(n, inf));
    vector<vector<ll> > g(n, vector<ll>(n, inf));
    for(int i=0; i<m; i++) {
        int x, y; ll z; cin >> x >> y >> z;
        x--, y--;
        qmin(f[x][y], z);
        qmin(f[y][x], z);
        g[x][y] = g[y][x] = 1;
    }
    for(int x=0; x<n; x++)
        g[x][x] = 0;
    for(int k=0; k<n; k++)
        for(int x=0; x<n; x++)
            for(int y=0; y<n; y++)
                qmin(g[x][y], g[x][k] + g[k][y]);
    ll Ans = 1e18;
    for(int x=0; x<n; x++)
        for(int y=0; y<n; y++) {
            if(x == y || g[x][y] == inf) continue;
            qmin(Ans, f[x][y] * (g[0][x] + g[y][n-1] + 1));
            for(int k=0; k<n; k++) {
                if(g[x][k] == inf) continue;
                qmin(Ans, f[x][y] * (g[x][k] + g[k][0] + g[k][n-1] + 2));
            }
        }
    printf("%lld\n", Ans);
}

int main() {
//    freopen("nh.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}






