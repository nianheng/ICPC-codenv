#include<bits/stdc++.h>

#define mp(x, y) make_pair(x, y)
#define qmin(x, y) (x = min(x, y))
#define qmax(x, y) (x = max(x, y))

using ll = long long;
using namespace std;

typedef pair<int, int> pii;
typedef array<int, 2> arr;

const int maxn = 4e3+100, maxd = 12, maxo = 1<<maxd;
const int inf = 0x3f3f3f3f;
//const ll P = ;

struct node {
    int ch[maxd], fail, val;
};
node p[maxn];
int pn = 1;
int m = maxd;

int n;

inline string inits(string s) {
    string t = s.substr(0, 1);
    int sn = s.length();
    int nw = 0;
    for(int i=1; i<sn; i++) {
        char c = s[i];
        if(nw != t.length()-1 && t[nw+1] == c) {
            nw++; continue;
        }
        if(nw != 0 && t[nw-1] == c) {
            nw--; continue;
        }
        if(nw == 0) {
            t = string(1, c) + t;
            continue;
        }
        if(nw == t.length()-1) {
            t.append(string(1, c));
            nw++; continue;
        }
        return "?";
    }
    vector<int> vis(m);
    for(auto c : t) {
        vis[c - 'a']++;
        if(vis[c - 'a'] == 2) return "?";
    }
    return t;
}

void trieins(string s, int z) {
    int nw = 1;
    for(auto c : s) {
        int x = c - 'a';
        if(p[nw].ch[x] == 0)
            p[nw].ch[x] = ++pn;
        nw = p[nw].ch[x];
    }
    p[nw].val += z;
}

void buildAC() {
    for(int i=0; i<m; i++)
        p[0].ch[i] = 1;
    queue<int> q; q.push(1);
    while(!q.empty()) {
        int x = q.front(); q.pop();
        p[x].val += p[p[x].fail].val;
        for(int i=0; i<m; i++) {
            if(p[x].ch[i]) {
                p[p[x].ch[i]].fail = p[p[x].fail].ch[i];
                q.push(p[x].ch[i]);
            }
            else p[x].ch[i] = p[p[x].fail].ch[i];
        }
    }
}

void ACdp() {
    vector<vector<int> > f(maxo, vector<int> (pn+1, -inf));
    vector<vector<array<int, 3> > > g(maxo, vector<array<int, 3> > (pn+1, {0, 0, 0}));
    f[0][1] = 0;
    for(int o=0; o<maxo; o++) {
        for(int x=1; x<=pn; x++) {
            if(f[o][x] == -inf) continue;
            for(int i=0; i<m; i++) {
                int y = p[x].ch[i];
                if(o>>i&1) continue;
                int e = o | (1<<i);
                int nxf = f[o][x] + p[y].val;
                if(nxf > f[e][y])
                    f[e][y] = nxf, g[e][y] = {o, x, i};
            }
        }
    }
    int Ans = -inf; array<int, 2> sta = {0, 0};
    for(int x=1; x<=pn; x++) {
        if(f[maxo-1][x] > Ans)
            Ans = f[maxo-1][x], sta = {maxo-1, x};
    }
    string s;
    while(true) {
        if(g[sta[0]][sta[1]][1] == 0) break;
        s = string(1, 'a' + g[sta[0]][sta[1]][2]) + s;
        sta = {g[sta[0]][sta[1]][0], g[sta[0]][sta[1]][1]};
    }
    cout << s << '\n';
}

int main() {
//    freopen("nh.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++) {
        int z; string s;
        cin >> z >> s;
        s = inits(s);
        if(s == "?")
            continue;
        trieins(s, z);
        reverse(s.begin(), s.end());
        trieins(s, z);
    }
    buildAC();
    ACdp();
    return 0;
}






