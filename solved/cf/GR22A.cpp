#include<bits/stdc++.h>

#define mp(x, y) make_pair(x, y)
#define qmin(x, y) (x = min(x, y))
#define qmax(x, y) (x = max(x, y))

using ll = long long;
using namespace std;

typedef pair<int, int> pii;
typedef array<int, 2> arr;

//const int maxn = ;
//const ll P = ;

bool cmp(int x, int y) {
    return x > y;
}

void solve() {
    int n; cin>>n;
    vector<vector<int> > a(2);
    vector<int> b(n+1), c(n+1);
    for(int i=1; i<=n; i++)
        cin >> b[i];
    for(int i=1; i<=n; i++)
        cin >> c[i];
    int d[2] = {0, 0};
    for(int i=1; i<=n; i++)
        a[b[i]].push_back(c[i]), d[b[i]]++;
    sort(a[0].begin(), a[0].end(), cmp);
    sort(a[1].begin(), a[1].end(), cmp);
    ll Ans = 0;
    if(d[0] > d[1]) {
        for(int i=d[1]-1; i>=0; i--)
            Ans += 2*a[0][i], Ans += 2*a[1][i];
        for(int i=d[1]; i<d[0]; i++)
            Ans += a[0][i];
    }
    if(d[0] < d[1]) {
        for(int i=d[0]-1; i>=0; i--)
            Ans += 2*a[0][i], Ans += 2*a[1][i];
        for(int i=d[0]; i<d[1]; i++)
            Ans += a[1][i];
    }
    if(d[0] == d[1]) {
        for(int i=d[0]-1; i>=0; i--)
            Ans += 2*a[0][i], Ans += 2*a[1][i];
        if(a[0][d[0]-1] > a[1][d[0]-1]) Ans -= a[1][d[0]-1];
        else Ans -= a[0][d[0]-1];
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






