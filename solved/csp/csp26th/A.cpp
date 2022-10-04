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

int n;
double a[maxn], s, d;

int main() {
    // freopen("nh.in", "r", stdin);
    n = read();
    for(int i=1; i<=n; i++)
        scanf("%lf", &a[i]), s += a[i];
    s /= n;
    for(int i=1; i<=n; i++)
        d += pow(a[i] - s, 2);
    d /= n;
    d = sqrt(d);
    for(int i=1; i<=n; i++)
        printf("%.5lf\n", (a[i] - s)/d);
    return 0;
}










