#include <bits/stdc++.h>

using ll = long long;
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> a(n+1);
    for(int i=1; i<=n; i++)
        a[i] = s[i-1] - '0';
    vector<int> b(10), c(10);
    for(int i=1; i<=n; i++) {
        for(int j=8; j > a[i]; j--)
            c[j+1] += b[j], b[j] = 0;
        b[a[i]]++;
    }
    for(int i=0; i<=9; i++) {
        while(b[i]--) printf("%d", i);
        while(c[i]--) printf("%d", i);
    }
    printf("\n");
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