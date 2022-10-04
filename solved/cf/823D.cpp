#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef array<int, 2> arr;

#define qmin(x, y) (x = min(x, y))
#define qmax(x, y) (x = max(x, y))
#define mp(x, y) make_pair(x, y)

inline int read() {
    int tmp = 0, fh = 1;
    char ch = getchar();
    while(!isdigit(ch)) {
        if(ch == '-') fh = -1;
        ch = getchar();
    }
    while(isdigit(ch))
        tmp = (tmp<<1) + (tmp<<3) + ch - '0', ch = getchar();
    return tmp * fh;
}


//const int maxn = ;

int n;
string a, b;

int main() {
//    freopen("nh.in", "r", stdin);
    int T = read();
    while(T--) {
        n = read();
        cin >> a >> b;
        std::reverse(b.begin(), b.end());
        vector<vector<int> > vis(26, vector<int>(26, 0));
        for(int i=0; i<n; i++) {
            int x = a[i] - 'a';
            int y = b[i] - 'a';
            if(x > y) swap(x, y);
            vis[x][y]++;
        }
        int err = 0, fd = 0;
        for(int i=0; i<26; i++)
            for(int j=0; j<26; j++)
                if(vis[i][j]&1) {
                    if(i != j || fd) {
                        err = 1; break;
                    }
                    fd = 1;
                }
        if(err) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}







