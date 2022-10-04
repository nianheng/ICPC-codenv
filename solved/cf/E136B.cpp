#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; scanf("%d", &n);
    int sum = 0, ok = 0;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) {
        int x; scanf("%d", &x);
        if(x == 0) continue;
        if(x <= sum) ok = 1;
        sum += x; a[i] = x;
    }
    if(!ok) {
        for(int i=1; i<=n; i++)
            a[i] += a[i-1], printf("%d ", a[i]);
        printf("\n");
    }
    else
        printf("-1\n");
    return;
}

int main() {
//    freopen("nh.in", "r", stdin);
    int T; scanf("%d", &T);
    while(T--) {
        solve();
    }
    return 0;
}