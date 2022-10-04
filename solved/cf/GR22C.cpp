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

int f[110][110][2];

int work(int x, int y, int op) {
    if(y == 0) return op^1;
    if(x == 0) {
        if(y & 1) y++;
        y /= 2, y &= 1;
        return y == op;
    }
    if(f[x][y][op]) return f[x][y][op] - 1;
    if(work(x-1, y-1, op) && (x == 1 || work(x-2, y, op))) {
        f[x][y][op] = 2;
        return 1;
    }
    if(work(x-1, y-1, op^1) && (y == 1 || work(x, y-2, op^1))) {
        f[x][y][op] = 2;
        return 1;
    }
    f[x][y][op] = 1;
    return 0;
}

void solve() {
    int n; cin >> n;
    vector<int> a(2);
    memset(f, 0, sizeof(f));
    for(int i=1; i<=n; i++) {
        int x; cin >> x;
        a[x%2]++;
    }
    if(work(a[0], a[1], 0))
        printf("Alice\n");
    else printf("Bob\n");
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






