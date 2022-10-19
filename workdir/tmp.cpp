#include<bits/stdc++.h>

#define mp(x, y) make_pair(x, y)
#define qmin(x, y) (x = min(x, y))
#define qmax(x, y) (x = max(x, y))

using ll = long long;
using namespace std;

typedef pair<int, int> pii;
typedef array<int, 2> arr;

const int maxn = 1e4+100, maxm = maxn<<1;
//const ll P = ;

int n, m, t, k;
int f[7][maxn], id[maxn], nc[10];
int head[maxn], nex[maxm], v[maxm], num = 1;

inline void add(int x, int y) {
    v[++num] = y, nex[num] = head[x], head[x] = num;
    v[++num] = x, nex[num] = head[y], head[y] = num;
}

void bfs(int s) {
    queue<int> q;
    for(int i=1; i<=n; i++)
        f[s][i] = n+1;
    f[s][nc[s]] = 0, q.push(nc[s]);
    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(int i=head[x]; i; i=nex[i]) {
            int y = v[i]; if(f[s][y] != n+1) continue;
            f[s][y] = f[s][x] + 1, q.push(y);
        }
    }
}

bool check(int o, int ID) {
    vector<int> ds;
    for(int i=0; i<k; i++)
        if(o>>i&1) ds.push_back(i+1);
    int len = 0;
    for(int i=0; i<ds.size(); i++)
        len += f[i==0?0:ds[i-1]][nc[ds[i]]];
    return len + f[ds[ds.size()-1]][ID] == f[0][ID];
}

void solve() {
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int x, y; cin >> x >> y;
        add(x, y);
    }
    cin >> t;
    for(int i=1; i<=t; i++)
        cin >> id[i];
    cin >> k;
    nc[0] = 1;
    vector<int> vis(n+1);
    for(int i=1; i<=k; i++)
        cin >> nc[i], vis[nc[i]] = 1, nc[i] = id[nc[i]];
    bfs(0);
    sort(nc+1, nc+k+1, [&](int x, int y){return f[0][x] < f[0][y];});
    for(int i=1; i<=k; i++)
        bfs(i);
    int mx = 1 << k;
    vector<int> ans(mx, 0);
    ans[0] = 1;
    for(int i=1; i<=t; i++) {
        if(vis[i]) continue;
        vector<int> tmp = ans;
        for(int o=1; o<mx; o++) {
            for(int e = o; e; e = e&(e-1)) {
                if(ans[o^e] == 0 || !check(e, id[i])) continue;
                tmp[o] = 1; break;
            }
        }
        ans = tmp;
    }
    int mn = k;
    for(int o=0; o<mx; o++) {
        if(!ans[o]) continue;
        int tmp = 0;
        for(int i=0; i<k; i++)
            if(o>>i&1) tmp++;
        qmin(mn, k - tmp);
    }
    printf("%d\n", mn);
}

int main() {
    freopen("nh.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}






