#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

#define qmin(x, y) (x = min(x, y))
#define qmax(x, y) (x = max(x, y))
#define mp(x, y) make_pair(x, y)

inline int read() {
    int tmp = 0, fh = 1;
    char ch = getchar();
    while(!isdigit(ch)) {
        if(ch == '-')
            fh = -1;
        ch = getchar();
    }
    while(isdigit(ch))
        tmp = (tmp<<1) + (tmp<<3) + (ch^48), ch = getchar();
    return tmp * fh;
}

const int maxn = 6e5+100;

struct node {
    int ax, ay, bx, by;
    double d;
}p[maxn];

int n;
int bn;
map<int, int> bh[2];
set<int> st[maxn];
set<int>::iterator its[maxn];
int pos[maxn];
int ph[maxn];
double du[maxn];
int itn;
map<int, int> itp[maxn];

inline void rev(int o, int d, int h, int type) {
    if(bh[o][d] == 0) bh[o][d] = ++bn;
    o = bh[o][d];
    if(type == 0) {
        itp[o][h] = ++itn;
        st[o].insert(h);
    }
    else {
        itp[o][h] = 0;
        st[o].erase(h);
    }
}

inline void revise(node A, int type) {
    if(A.ax == A.bx) return;
    int x = A.ax, y = A.ay;
    int re = A.by > A.ay ? 1 : -1;
    int ms = A.by > A.ay ? 0 : 1;
    x++, y+=re;
    while(x!=A.bx) {
        rev(1, x, y, type);
        rev(0, y, x, type);
        if(type == 0) {
            int o = itp[bh[1][x]][y];
            int e = itp[bh[0][y]][x];
            pos[o] = pos[e] = ms;
            du[o] = du[e] = A.d;
            ph[o] = bh[0][y];
            ph[e] = bh[1][x];
            its[o] = st[ph[o]].find(x);
            its[e] = st[ph[e]].find(y);
        }
        x++, y+=re;
    }
}

inline int workturn(int d, int ms) {
    if(d == 0)
        return ms;
    return ms^1;
}

inline void solve(int xy, int x, int y, int d, int t, double I) {
    if(d == 1) y += t;
    else y -= t;
    if(xy == 0) swap(x, y);
    int II = I;
    if(II == 0) x = y = 0;
    printf("%d %d %d\n", x, y, II);
}

inline void work(int x, int y, int d, double I, int t) {
    int o = d%2;
    if(d < 2) d = 1;
    else d = 0;
    if(o == 0) swap(x, y);
    int xy = o;
    o = bh[o][x];
    set<int>::iterator it;
    int nx = 1e9+100;
    if(o) {
        it = st[o].lower_bound(y);
        if(d == 0) {
            if(it == st[o].begin()) o = 0;
            else it--;
        }
        else
            if(it == st[o].end()) o = 0;
        if(o) nx = abs((*it) - y);
    }
    if(nx > t) {
        solve(xy, x, y, d, t, I);
        return;
    }
    while(1) {
        y = (*it);
        t -= nx;
        int Itp = itp[o][y];
        o = ph[Itp];
        it = its[Itp];
        int ps = pos[Itp];
        I *= du[Itp];
        int II = I;
        if(II == 0) {
            solve(xy, x, y, d, t, I);
            return;
        }
        d = workturn(d, ps);
        xy^=1;
        swap(x, y);
        nx = 1e9+100;
        if(d == 1) {
            it++;
            if(it != st[o].end()) {
                nx = abs((*it) - y);
            }
            if(nx > t) {
                solve(xy, x, y, d, t, I);
                return;
            }
        }
        else {
            if(it != st[o].begin()) {
                it--;
                nx = abs((*it) - y);
            }
            if(nx > t) {
                solve(xy, x, y, d, t, I);
                return;
            }
        }
    }
}

int main() {
    // freopen("nh.in", "r", stdin);
    int T = read();
    for(int tt=1; tt<=T; tt++) {
        int type = read();
        if(type == 1) {
            p[tt].ax = read(), p[tt].ay = read();
            p[tt].bx = read(), p[tt].by = read();
            scanf("%lf", &p[tt].d);
            if(p[tt].ax > p[tt].bx)
                swap(p[tt].ax, p[tt].bx), swap(p[tt].ay, p[tt].by);
            revise(p[tt], 0);
        }
        if(type == 2) {
            int k = read();
            revise(p[k], 1);
        }
        if(type == 3) {
            int x = read(), y = read(), d = read();
            double I; scanf("%lf", &I);
            int t = read();
            work(x, y, d, I, t);
        }
    }
    return 0;
}










