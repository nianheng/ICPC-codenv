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

const int maxn = 510;

class cha {
    public:
        string name;
        set<string> opt, fhz, fnam;
        set<string> usrs, libs;
        int dopt, dfhz, dfnam;
        cha(){name.clear(), opt.clear(), fhz.clear(),fnam.clear();
        dopt = dfhz = dfnam = 0;}
        bool check(string Opt, string Fhz, string Fnam) {
            if(!dopt && opt.find(Opt) == opt.end()) return 0;
            if(!dfhz && fhz.find(Fhz) == fhz.end()) return 0;
            if(!dfnam && fnam.find(Fnam) == fnam.end()) return 0;
            return 1;
        }
        bool incha(string nam, int type) {
            if(!type) return usrs.find(nam) != usrs.end();
            return libs.find(nam) != libs.end();
        }
}c[maxn];

int n, m, q;
string tlib[maxn];

int main() {
    // freopen("nh.in", "r", stdin);
    cin >> n >> m >> q;
    for(int i=1; i<=n; i++) {
        cin >> c[i].name;
        int nv; cin >> nv;
        while(nv--) {
            string tmp;
            cin >> tmp;
            c[i].opt.insert(tmp);
            if(tmp == "*")
                c[i].dopt = 1;
        }
        int no; cin >> no;
        while(no--) {
            string tmp;
            cin >> tmp;
            c[i].fhz.insert(tmp);
            if(tmp == "*")
                c[i].dfhz = 1;
        }
        int nn; cin >> nn;
        if(nn == 0) c[i].dfnam = 1;
        while(nn--) {
            string tmp;
            cin >> tmp;
            c[i].fnam.insert(tmp);
        }
    }
    for(int i=1; i<=m; i++) {
        string nam; cin >> nam;
        int x = 0;
        for(int j=1; j<=n; j++)
            if(c[j].name == nam) {
                x = j;
                break;
            }
        int ns; cin >> ns;
        while(ns--) {
            string typ, tmp;
            cin >> typ >> tmp;
            if(!x) continue;
            if(typ == "u") c[x].usrs.insert(tmp);
            else c[x].libs.insert(tmp);
        }
    }
    for(int i=1; i<=q; i++) {
        string nam; cin >> nam;
        int ng; cin >> ng;
        for(int j=1; j<=ng; j++)
            cin >> tlib[j];
        string topt, tfhz, tfnam;
        cin >> topt >> tfhz >> tfnam;
        int ok = 0;
        for(int j=1; !ok && j<=n; j++) {
            int isin = c[j].incha(nam, 0);
            for(int k=1; !isin && k<=ng; k++)
                isin = c[j].incha(tlib[k], 1);
            if(!isin) continue;
            if(c[j].check(topt, tfhz, tfnam))
                ok = 1;
        }
        printf("%d\n", ok);
    }
    return 0;
}










