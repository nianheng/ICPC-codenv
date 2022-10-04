#include <bits/stdc++.h>

using ll = long long;

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++)
        cin >> a[i];

    vector<int> ln(n+1), rn(n+1), lx(n+1), rx(n+1);
    vector<int> vc;
    for(int i=1; i<=n; i++) {
        while(!vc.empty() && a[vc.back()] >= a[i])
            vc.pop_back();
        ln[i] = vc.empty() ? 0 : vc.back(), vc.push_back(i);
    }
    vc.clear();
    for(int i=1; i<=n; i++) {
        while(!vc.empty() && a[vc.back()] <= a[i])
            vc.pop_back();
        lx[i] = vc.empty() ? 0 : vc.back(), vc.push_back(i);
    }
    vc.clear();
    for(int i=n; i>=1; i--) {
        while(!vc.empty() && a[vc.back()] >= a[i])
            vc.pop_back();
        rn[i] = vc.empty() ? n+1 : vc.back(), vc.push_back(i);
    }
    vc.clear();
    for(int i=n; i>=1; i--) {
        while(!vc.empty() && a[vc.back()] <= a[i])
            vc.pop_back();
        rx[i] = vc.empty() ? n+1 : vc.back(), vc.push_back(i);
    }

    int m = *max_element(a.begin(), a.end());
    vector<vector<int> > p(m+1);
    for(int i=1; i<=n; i++)
        p[a[i]].push_back(i);
    ll Ans = 0;
    for(int x=1; x<=m; x++) {
        if(p[x].empty()) continue;
        for(int y=x; y<=m; y+=x) {
            if(p[y].empty()) continue;
            int i = 0, j = 0;
            int las = 0;
            while(i < p[x].size() && j < p[y].size()) {
                int xd = p[x][i], yd = p[y][j];
                if(xd < yd) {
                    i = lower_bound(p[x].begin(), p[x].end(), yd) - p[x].begin();
                    i--;
                    xd = p[x][i];
                    int LL = max(ln[xd], lx[yd]), LR = min(xd + 1, yd + 1);
                    LL = max(LL, las);
                    int RL = max(xd-1, yd-1), RR = min(rn[xd], rx[yd]);
                    if(LL < LR && RL < RR)
                        Ans += 1ll * (LR - LL - 1) * (RR - RL - 1);
                    las = LR - 1;
                    i++;
                }
                else {
                    j = lower_bound(p[y].begin(), p[y].end(), xd) - p[y].begin();
                    if(j == p[y].size() || p[y][j] > xd) j--;
                    yd = p[y][j];
                    int LL = max(ln[xd], lx[yd]), LR = min(xd + 1, yd + 1);
                    LL = max(LL, las);
                    int RL = max(xd-1, yd-1), RR = min(rn[xd], rx[yd]);
                    if(LL < LR && RL < RR)
                        Ans += 1ll * (LR - LL - 1) * (RR - RL - 1);
                    las = LR - 1;
                    j++;
                }
            }
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