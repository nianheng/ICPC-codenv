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

using ld = long double;

const ld pi = acos(-1);

void solve() {
    int n; cin >> n;
    ld d;
    if(n%2 == 0)
        d = 1 / tan(pi / n / 2);
    else
        d = 0.5 / sin(pi / n / 4);
    printf("%.7Lf\n", d);
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






