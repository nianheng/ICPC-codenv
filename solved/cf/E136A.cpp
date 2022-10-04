#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    printf("%d %d\n", (n+1)/2, (m+1)/2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin>> T;
    while(T--) {
        solve();
    }
}