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

const int maxn = 1e3+100;

struct node {
    int x, y;
}p[maxn];

int n, mx, m;
int a[100][100], an;

inline bool check(int x, int y) {
    int cnt = 0;
    if(x + m > mx || y + m > mx)
        return 0;
    for(int i=1; i<=n; i++) {
        int A = p[i].x-x;
        int B = p[i].y-y;
        if(A<0 || A>m || B<0 || B>m)
            continue;
        if(a[A][B]) cnt++;
        else return 0;
    }
    return cnt == an;
}

int main() {
    // freopen("nh.in", "r", stdin);
    n = read(), mx = read(), m = read();
    for(int i=1; i<=n; i++)
        p[i].x = read(), p[i].y = read();
    for(int i=m; i>=0; i--)
        for(int j=0; j<=m; j++)
            a[i][j] = read(), an += a[i][j];
    int Ans = 0;
    for(int i=1; i<=n; i++)
        if(check(p[i].x, p[i].y))
            Ans++;
    printf("%d\n", Ans);
    return 0;
}










