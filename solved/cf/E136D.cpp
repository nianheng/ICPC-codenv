#include <bits/stdc++.h>

using ll = long long;
using namespace std;

const int maxn = 2e5+100;

typedef array<int, 2> arr;

int n, m;
int head[maxn], v[maxn], nex[maxn], num = 1;

inline void add(int x, int y) {
    v[++num] = y, nex[num] = head[x], head[x] = num;
}

arr dfs(int x, int lim) {
    if(lim == 0) return {0, 1000000000};
    int mx = 0, cnt = 0;
    for(int i=head[x]; i; i=nex[i]) {
        int y = v[i];
        arr tmp = dfs(y, lim);
        if(x != 1 && tmp[0] == lim)
            cnt++, tmp[0] = 0;
        cnt += tmp[1];
        mx = max(mx, tmp[0]);
    }
    return {mx+1, cnt};
}

void solve() {
    cin >> n >> m;
    for(int i=1; i<=n; i++)
        head[i] = 0;
    num = 1;
    for(int i=2; i<=n; i++) {
        int x; cin >> x;
        add(x, i);
    }
    int l = 0, r = n-1;
    while(l + 1 < r) {
        int mid = l+r>>1;
        if(dfs(1, mid)[1] > m)
            l = mid;
        else
            r = mid;
    }
    printf("%d\n", r);
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