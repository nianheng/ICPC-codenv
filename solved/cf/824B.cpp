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

int main() {
//    freopen("nh.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        int x; cin >> x;
        if(n == 1) {
            printf("0\n");
            continue;
        }
        n--;
        x = x*2-1;
        ll Ans = 0;
        for(int i=1; i<=n; i++) {
            int y; cin >> y;
            if(y <= x) continue;
            Ans += (y-1)/x;
        }
        printf("%lld\n", Ans);
    }
    return 0;
}






