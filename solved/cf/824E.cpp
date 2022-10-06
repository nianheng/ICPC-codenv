#include<bits/stdc++.h>

#define mp(x, y) make_pair(x, y)
#define qmin(x, y) (x = min(x, y))
#define qmax(x, y) (x = max(x, y))

using ll = long long;
using namespace std;

#define int long long

typedef pair<int, int> pii;
typedef array<int, 2> arr;

//const int maxn = ;
//const ll P = ;

const int inf = 1e9;

void solve() {
    int n; cin >> n;
    vector<vector<int> > a(2, vector<int>(n, 0));
    for(int i=0; i<n; i++)
        cin >> a[0][i];
    for(int i=0; i<n; i++)
        cin >> a[1][i];
    sort(a[0].begin(), a[0].end());
    sort(a[1].begin(), a[1].end());
    auto check = [&](int len) {
        vector<multiset<int> > st(2);
        st[0] = multiset<int> (a[0].begin(), a[0].end());
        st[1] = multiset<int> (a[1].begin(), a[1].end());
        vector<int> ans;
        while(1) {
            if(st[0].empty()) break;
            int x = 1;
            if(*st[0].rbegin() > *st[1].rbegin())
                x = 0;
            int val = *st[x].rbegin();
            if(val >= len) {
                if(st[x^1].find(val - len) == st[x^1].end())
                    return false;
                st[x^1].erase(st[x^1].find(val - len));
                st[x].erase(st[x].find((val)));
                if(x == 0)
                    ans.push_back(inf + val);
                else
                    ans.push_back(inf - val + len);
                continue;
            }
            else {
                if(st[x^1].find(len - val) == st[x^1].end())
                    return false;
                st[x^1].erase(st[x^1].find(len - val));
                st[x].erase(st[x].find(val));
                if(x == 0)
                    ans.push_back(inf + val);
                else
                    ans.push_back(inf - val + len);
            }
        }
        int mx = max(inf + len, *max_element(ans.begin(), ans.end()));
        if(mx > inf*2) {
            mx -= inf * 2;
            for(auto &x : ans) {
                if(x - mx < 0)
                    return false;
                else
                    x -= mx;
            }
            cout << "YES\n";
            for(int i=0; i<n; i++)
                cout << ans[i] << " \n"[i == n-1];
            cout << inf-mx << " " << inf - mx + len << "\n";
            return true;
        }
        cout << "YES\n";
        for(int i=0; i<n; i++)
            cout << ans[i] << " \n"[i == n-1];
        cout << inf << " " << inf + len << "\n";
        return true;
    };
    if(check(*a[1].rbegin() + *a[0].begin()))
        return;
    for(auto x : a[0])
        if(check(abs(*a[1].rbegin() - x)))
            return;
    cout << "NO\n";
    return;
}

signed main() {
//    freopen("nh.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}






