#include <bits/stdc++.h>

using ll = long long;
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    ll Ans = 1e18;
    for(int i=1; i+2<=n; i++)
        for(int j=i; j<=i+2; j++) {
            ll tmp = 0;
            for(int k=i; k<=i+2; k++)
                tmp += abs(a[k] - a[j]);
            Ans = min(Ans, tmp);
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
}