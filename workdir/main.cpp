#include<bits/stdc++.h>

#define mp(x, y) make_pair(x, y)
#define qmin(x, y) (x = min(x, y))
#define qmax(x, y) (x = max(x, y))

using ll = long long;
using namespace std;

typedef pair<int, int> pii;
typedef array<int, 2> arr;

const int maxn = 3e5+100;
//const ll P = ;

int a[maxn];
int cnt;

arr dfs(int l, int r) {
    if(l == r) return {a[l], a[r]};
    int mid = l+r>>1;
    arr lz = dfs(l, mid);
    arr rz = dfs(mid+1, r);
    if(lz[0] == -1 || rz[0] == -1)
        return {-1, -1};
    if(lz[1]+1 == rz[0])
        return {lz[0], rz[1]};
    if(rz[1]+1 == lz[0]) {
        cnt++;
        return {rz[0], lz[1]};
    }
    return {-1, -1};
}

void solve() {
    int n; cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    int mx = 0;
    while(n >> mx) mx++;
    cnt = 0;
    if(dfs(1, n)[0] == -1)
        printf("-1\n");
    else
        printf("%d\n", cnt);
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






