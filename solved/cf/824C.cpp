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
    int n;
    string s;
    cin >> n >> s;
    vector<int> vis(26), a;
    for(auto c : s) {
        int z = c - 'a';
        if(!vis[z]) {
            vis[z] = 1;
            a.push_back(z);
        }
    }
    fill(vis.begin(), vis.end(), 0);
    vector<int> f(26, -1);
    for(auto c : a) {
        if(f[c] != -1) continue;
        for(int i=0; i<26; i++) {
            if(vis[i] || i == c) continue;
            int x = i, cnt = 0;
            while(x != -1 && x != c)
                x = f[x], cnt++;
            if(x == c && cnt != 25) continue;
            f[c] = i; vis[i] = 1;
            break;
        }
    }
    for(auto &c : s)
        c = 'a' + f[c - 'a'];
    cout << s << '\n';
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






