#include<bits/stdc++.h>

#define mp(x, y) make_pair(x, y)
#define qmin(x, y) (x = min(x, y))
#define qmax(x, y) (x = max(x, y))

using ll = long long;
using namespace std;

typedef pair<int, int> pii;
typedef array<int, 2> arr;

const int maxn = 2e5+100, maxm = 2e6+100, maxd = 26;

struct node {
    int ch[maxd], fail;
    int len;
    int cnt;
    vector<int> id;
};
node p[maxn];
int pn = 1;
int m = maxd;
//const ll P = ;
int N, Len;

inline void trieins(string s, int id) {
    int x = 1;
    for(auto tmp : s) {
        int c = tmp - 'a';
        if(!p[x].ch[c])
            p[x].ch[c] = ++pn, p[pn].len = p[x].len+1, qmax(Len, p[pn].len);
        x = p[x].ch[c];
    }
    p[x].id.push_back(id);
}

void ACbuild() {
    for(int i=0; i<m; i++)
        p[0].ch[i] = 1;
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(int i=0; i<m; i++) {
            if(p[x].ch[i]) {
                p[p[x].ch[i]].fail = p[p[x].fail].ch[i];
                q.push(p[x].ch[i]);
            }
            else p[x].ch[i] = p[p[x].fail].ch[i];
        }
    }
}

void work() {
    string s; cin >> s;
    int x = 1;
    for(auto tmp : s) {
        int c = tmp - 'a';
        x = p[x].ch[c];
        p[x].cnt++;
    }
    vector<int> rk;
    vector<vector<int> > gb(Len+1);
    for(x=1; x<=pn; x++)
        gb[p[x].len].push_back(x);
    for(int i=Len; i>=0; i--)
        for(auto h : gb[i])
            rk.push_back(h);
    for(auto x : rk) {
        int y = p[x].fail;
        p[y].cnt += p[x].cnt;
    }
    vector<int> ans(N+1);
    for(x=2; x<=pn; x++)
        for(auto h : p[x].id)
            ans[h] = p[x].cnt;
    for(int i=1; i<=N; i++)
        printf("%d\n", ans[i]);
}

int main() {
//    freopen("nh.in", "r", stdin);
//    freopen("zhy.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    N = n;
    for(int i=1; i<=n; i++) {
        string s; cin >> s;
        trieins(s, i);
    }
    ACbuild();
    work();
    return 0;
}






