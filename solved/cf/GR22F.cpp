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
    vector<int> d(n+1);
    for(int i=1; i<=n; i++)
        cin >> d[i];
    vector<int> vis(n+1), fa(n+1), h(n);
    for(int i=0; i<n; i++) h[i] = i+1;
    sort(h.begin(), h.end(), ([&](int x, int y){return d[x] > d[y];}));
    for(int i=1; i<=n; i++) fa[i] = i;
    function<int(int)> getfa = [&](int x) {return fa[x] == x ? x : (fa[x] = getfa(fa[x]));};
    auto merge = [&](int x, int y) {
        fa[getfa(x)] = getfa(y);
    };

    for(int i=0; i<n; i++) {
        int x = h[i];
        if(vis[x]) continue;
        vis[x] = 1;
        while(d[x]--) {
            printf("? %d\n", x);
            fflush(stdout);
            int y; cin >> y;
            merge(x, y);
            if(vis[y]) break;
            else vis[y] = 1;
        }
    }
    printf("!");
    for(int i=1; i<=n; i++)
        printf(" %d", getfa(i));
    printf("\n");
    fflush(stdout);
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

/*
15
2 3 3 4 2 2 1 1 2 3 4 3 2 3 1
 */




