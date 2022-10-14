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

ll gcd(ll x, ll y) {
    return y ? gcd(y, x%y) : x;
}

void solve() {
    int n; cin >> n;
    ll mx = 0, G = 0;
    for(int i=1; i<=n; i++) {
        ll x, y; cin >> x >> y;
        qmax(mx, y);
        G = gcd(G, x - y);
    }
    vector<ll> ans;
    for(ll d = 1; d*d<=G; d++)
        if(G%d == 0){
            if(d > mx) ans.push_back(d);
            if(d*d == G) break;
            if(G/d > mx) ans.push_back(G/d);
        }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << "\n";
}

int main() {
//    freopen("nh.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}