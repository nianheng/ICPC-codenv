#include<bits/stdc++.h>

#define mp(x, y) make_pair(x, y)
#define qmin(x, y) (x = min(x, y))
#define qmax(x, y) (x = max(x, y))

using ll = long long;
using namespace std;

typedef pair<int, int> pii;
typedef array<int, 2> arr;

const int maxn = 1e3+100;
//const ll P = ;

int n, m;

int main() {
//    freopen("nh.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<vector<int> > a(n+1, vector<int> (m, 0));
    for(int i=1; i<=n; i++)
        for(int d=0; d<m; d++)
            cin >> a[i][d];
    vector<vector<int> > v(3, vector<int>(3, 0));
    for(int w=0; w<3; w++) v[w][w] = w;
    for(int w=0; w<3; w++)
        for(int h=0; h<3; h++)
            for(int k=0; k<3; k++)
                if(w != h && w != k && h != k)
                    v[w][h] = k;
    map<vector<int>, int> pos;
    for(int i=1; i<=n; i++)
        pos[a[i]] = i;
    vector<int> cnt(n+1);
    for(int i=1; i<=n; i++)
        for(int j=i+1; j<=n; j++) {
            vector<int> h(m, 0);
            for(int d=0; d<m; d++)
                h[d] = v[a[i][d]][a[j][d]];
            int x = pos[h];
            cnt[x]++;
        }
    ll Ans = 0;
    for(int i=1; i<=n; i++)
        if(cnt[i]) Ans += 1ll * cnt[i] * (cnt[i] - 1);
    printf("%lld\n", Ans/2);
    return 0;
}






