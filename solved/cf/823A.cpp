#include<bits/stdc++.h>

using ll = long long;
using namespace std;

void solve() {
    int n, c; cin >> n >> c;
    vector<int> a(110);
    for(int i=1; i<=n; i++) {
        int x; cin >> x;
        a[x]++;
    }
    int Ans = 0;
    for(int i=0; i<=100; i++)
        Ans += min(a[i], c);
    printf("%d\n", Ans);
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