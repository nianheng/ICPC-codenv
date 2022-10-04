#include<bits/stdc++.h>

#define mp(x, y) make_pair(x, y)
#define qmin(x, y) (x = min(x, y))
#define qmax(x, y) (x = max(x, y))

using ll = long long;
using namespace std;

typedef pair<int, int> pii;
typedef array<int, 2> arr;

const int maxn = 1e5+100;
const ll P = 998244353;

ll jc[maxn], ijc[maxn];

inline ll poww(ll x, ll y) {
    ll tmp = 1;
    while(y) {
        if(y&1) tmp = tmp*x%P;
        x = x*x%P, y>>=1;
    }
    return tmp;
}

inline void initjc() {
    jc[0] = 1;
    for(int i=1; i<maxn; i++)
        jc[i] = jc[i-1]*i%P;
    ijc[maxn-1] = poww(jc[maxn-1], P-2);
    for(int i=maxn-2; i>=0; i--)
        ijc[i] = ijc[i+1]*(i+1)%P;
}

inline ll C(ll n, ll m) {
    return jc[n] * ijc[m] % P * ijc[n-m] % P;
}

void solve() {
    int n; cin >> n;
    vector<ll> a(n+3), pre(n+3), suf(n+3);
    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i=1; i<=n; i++)
        pre[i] = a[i] + pre[i-1];
    for(int i=n; i>=1; i--)
        suf[i] = suf[i+1] + a[i];
    int l = 0, r = n+1;
    ll Ans = 1;
    int fc = 0;
    auto work = [&](int l, int r) {
        if(!fc) {
            fc = 1;
            l++, r--;
            if(a[l] != 0 || a[r] != 0)
                return 1ll;
        }
        int cl = 1, cr = 1;
        int L = l, R = r;
        l++;
        while(l <= n && a[l] == 0)
            cl++, l++;
        r--;
        while(r > 0 && a[r] == 0)
            cr++, r--;
        if(l > r) {
            int cnt = R-L+1;
            ll Tmp = 1;
            for(int i=2; i<=cnt; i+=2)
                Tmp = (Tmp + C(cnt, i))%P;
            return Tmp;
        }
        ll Tmp = 1;
        for(int i=1; i<=min(cl, cr); i++)
            Tmp = (Tmp + C(cl, i) * C(cr, i) % P) % P;
        return Tmp;
    };
    while(1) {
        Ans = Ans * work(l, r) % P;
        l++; while(l <= n && a[l] == 0) l++;
        r--; while(r > 0 && a[r] == 0) r--;
        if(l >= r) break;
        while(1) {
            while(l <= n && pre[l] < suf[r]) l++;
            while(r > 0 && suf[r] < pre[l]) r--;
            if(pre[l] == suf[r] || l >= r) break;
        }
        if(l >= r) break;
    }
    printf("%lld\n", Ans % P);
}

int main() {
//    freopen("nh.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    initjc();
    int T; cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}






