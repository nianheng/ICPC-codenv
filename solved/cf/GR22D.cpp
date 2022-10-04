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
    int n; cin >> n;
    vector<vector<int> > v(n+2);
    int L = 0, R = n+1;
    for(int i=1; i<=n; i++) {
        int x; cin >> x;
        int y = i;
        v[x].push_back(y);
        if(x > y) swap(x, y);
        L = max(L, x);
        R = min(R, y);
    }
    int x = 0;
    if(v[x].empty()) x = n+1;
    printf("%d\n", L);
    while(1) {
        if(v[x].empty()) {
            printf("\n");
            return;
        }
        int y = 0;
        while(y < v[x].size() && v[v[x][y]].size() == 0)
            y++;
        if(y == v[x].size()) {
            for(auto z : v[x])
                printf("%d ", z);
            printf("\n");
            return;
        }
        swap(v[x][y], v[x][v[x].size()-1]);
        for(auto z : v[x])
            printf("%d ", z);
        x = v[x][v[x].size()-1];
    }
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






