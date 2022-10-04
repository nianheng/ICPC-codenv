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
    string s; cin >> s;
    string g;
    vector<int> vis(26);
    vector<int> usr(26);
    for(int i=0; i<n; i++) {
        int w = s[i] - 'a';
        if(!vis[w]) {
            for(int j=0; j<26; j++)
                if(!usr[j] && j != w) {
                    usr[j] = i;
                    vis[w] = j;
                    break;
                }
            if(!vis[w]) {
                int las = -1, col = -1;
                for(int j=0; j<26; j++) {
                    if(usr[j] > las)
                        las = usr[j], col = j;
                }
                vis[w] = col, vis[col] = w;
            }
        }
    }
    for(auto c : s)
        g.append(string(1, vis[c - 'a'] + 'a'));
    cout << g << '\n';
}

int main() {
    freopen("nh.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}






