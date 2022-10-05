//思路是先建一个超级源点S到所有点连0边跑spfa
//跑完得到S到每个点的最短路 h[i]
//更新图中边权为 w[i][j] = h[i] + w[i][j] - h[j]
//再从每个点开始跑dij即可
#include <bits/stdc++.h>

using namespace std;

#define qmin(x,y) (x=min(x,y))
#define qmax(x,y) (x=max(x,y))
#define mp(x,y) make_pair(x,y)

typedef long long ll;
typedef pair<ll,int> pii;

const int maxn = 3100, maxm = 1e4+100;
//const ll P = ;

int n, m;
int h[maxn], vis[maxn], cnt[maxn];
ll f[maxn][maxn], inf;
vector<pii> e[maxn];
queue<int> qx;
priority_queue<pii, vector<pii>, greater<pii> > q;

void spfa() {
    for(int i=1; i<=n; i++)
        qx.push(i), vis[i] = 1;
    while(!qx.empty()) {
        int x = qx.front(); qx.pop();
        int xz = h[x]; vis[x] = 0;
        for(pii tmp : e[x]) {
            int y = tmp.first, yz = xz + tmp.second;
            if(yz >= h[y]) continue;
            h[y] = yz;
            if(!vis[y]) {
                vis[y] = 1;
                cnt[y]++;
                if(cnt[y] == n) {
                    printf("-1\n");
                    exit(0);
                }
                qx.push(y);
            }
        }
    }
    for(int x=1; x<=n; x++)
        for(pii &tmp : e[x])
            tmp.second = h[x] + tmp.second - h[tmp.first];
}

void dij(int s) {
    memset(f[s], 0x3f, sizeof(f[s]));
    inf = f[s][s];
    f[s][s] = 0, q.push(mp(0, s));
    while(!q.empty()) {
        pii tmp = q.top(); q.pop();
        int x = tmp.second; ll xz = tmp.first;
        if(xz > f[s][x]) continue;
        for(pii tmp : e[x]) {
            int y = tmp.first; ll yz = xz + tmp.second;
            if(yz >= f[s][y]) continue;
            f[s][y] = yz, q.push(mp(yz, y));
        }
    }
    ll Ans = 0;
    for(int i=1; i<=n; i++)
        Ans += i*(f[s][i]!=inf?(f[s][i] + h[i] - h[s]):1e9);
    printf("%lld\n", Ans);
}

int main(){
//    freopen("nh.in","r",stdin);
//    freopen("zhy.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        e[x].push_back(mp(y, z));
    }
    spfa();
    for(int i=1; i<=n; i++)
        dij(i);
    return 0;
}











