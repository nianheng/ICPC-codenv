#include <bits/stdc++.h>
#define qmin(x, y) (x = min(x, y))

using ll = long long;
using namespace std;
typedef array<int, 2> arr;

const int maxn = 2e5+100;
const int inf = 0x3f3f3f3f;

void solve() {
    int n; cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    vector<arr> a(n+1);
    int Ans = 0;
    for(int i=0; i<n; i++) {
        a[i+1] = {s1[i] - '0', s2[i] - '0'};
        Ans += a[i+1][0] + a[i+1][1];
    }
    vector<arr> f(n+1, {inf, inf});
    f[0][0] = 0;
    for(int i=1; i<n; i++)
        for(auto d : {0, 1}) {
            if(f[i-1][d] == inf)
                continue;
            int c = d^1;
            if(!a[i][c]) {
                qmin(f[i][d], f[i-1][d]);
                continue;
            }
            qmin(f[i][d], f[i-1][d] + 1);
            if(!a[i+1][d]) {
                qmin(f[i][c], f[i-1][d]);
                continue;
            }
            qmin(f[i+1][c], f[i-1][d] + 1);
        }
    printf("%d\n", Ans - min(min(f[n-1][0], f[n-1][1]), min(f[n][0], f[n][1])));
}

int main() {
//    freopen("nh.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    while(T--) {
        solve();
    }
    return 0;
}