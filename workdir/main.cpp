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

void solve() {
    int n;
    cin >> n;
    vector<arr> a(n+1);
    for(int i=1; i<=n; i++)
        cin >> a[i][0];
    for(int i=1; i<=n; i++)
        cin >> a[i][1];
    auto check = [&](int len) {
        for(int i=1; i<=n; i++)
            if(abs(a[i][0] - a[i][1]) != len && a[i][0] + a[i][1] != len)
                return 0;
        return 1;
    };
    function<void(int)> work = [&](int len) {
        int P0 = 0, P1 = len;
        vector<int> pos(n+1);
        for(int i=1; i<=n; i++) {
            if(a[i][1] - a[i][0] == len)
                pos[i] = -a[i][0];
            else
                pos[i] = a[i][0];
        }
        printf("YES\n");
        for(int i=1; i<=n; i++)
            printf("%d ", pos[i]);
        printf("\n");
        printf("%d %d\n", P0, P1);
    };
    for(int i=1; i<=n; i++) {
        int len = abs(a[i][1] - a[i][0]);
        if(check(len)) {
            work(len);
            return;
        }
        len = a[i][1] + a[i][0];
        if(check(len)) {
            work(len);
            return;
        }
    }
    printf("NO\n");
    return;
}

int main() {
    freopen("nh.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}






