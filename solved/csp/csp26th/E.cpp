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

const int maxn = 1e4+100;

struct Point {
    double x, y;
    Point(double xx = 0, double yy = 0) {
        x = xx, y = yy;
    }
};

typedef Point Vector;

Vector operator - (Point A, Point B) {
    return Vector(A.x - B.x, A.y - B.y);
}

Point operator + (Point A, Vector B) {
    return Point(A.x + B.x, A.y + B.y);
}

Point a[maxn];

int n;

Vector rotate(Vector A, double rad) {
    return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad));
}

int main() {
    // freopen("nh.in", "r", stdin);
    // freopen("zhy.out", "w", stdout);
    n = read(); int T = read();
    for(int i=1; i<=n; i++)
        scanf("%lf%lf", &a[i].x, &a[i].y);
    while(T--) {
        int ms = read(), l = read(), r = read();
        if(ms == 1) {
            double x, y; scanf("%lf%lf", &x, &y);
            for(int i=l; i<=r; i++)
                a[i].x += x, a[i].y += y;
        }
        if(ms == 2) {
            double x, y, z; scanf("%lf%lf%lf", &x, &y, &z);
            Point C = Point(x, y);
            for(int i=l; i<=r; i++) {
                Vector v = a[i] - C;
                v = rotate(v, z);
                a[i] = C + v;
            }
        }
        if(ms == 3) {
            double x, y, z; scanf("%lf%lf%lf", &x, &y, &z);
            for(int i=l; i<=r; i++) {
                double xd = a[i].x - x;
                double yd = a[i].y - y;
                a[i].x = x + xd*z;
                a[i].y = y + yd*z;
            }
        }
        if(ms == 6) {
            double x = 0, y = 0;
            for(int i=l; i<=r; i++)
                x += a[i].x, y += a[i].y;
            x /= (r-l+1), y /= (r-l+1);
            printf("%.6lf %.6lf\n", x, y);
        }
        if(ms == 7) {
            double ans = 0, x, y;
            scanf("%lf%lf", &x, &y);
            for(int i=l; i<=r; i++)
                ans += pow(a[i].x - x, 2) + pow(a[i].y - y, 2);
            printf("%.6lf\n", ans);
        }
    }
    return 0;
}










