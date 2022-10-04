#include<bits/stdc++.h>

using ll = long long;
using namespace std;

inline int sgn(ll x) {
    return x < 0 ? -1 : x > 0;
}

struct Point {
    ll x, y;
    explicit Point(ll X = 0, ll Y = 0) : x(X), y(Y){};
};
typedef Point Vector;

int Vecpos(Vector A) {
    if(sgn(A.y) == -1 || (sgn(A.y) == 0 && sgn(A.x) == -1))
        return 1;
    return 0;
}

Vector operator - (Point A, Point B) {
    return Vector(A.x - B.x, A.y - B.y);
}

Point operator + (Point A, Vector B) {
    return Point(A.x + B.x, A.y + B.y);
}

ll operator * (Vector A, Vector B) {
    return A.x*B.x + A.y*B.y;
}

ll operator ^ (Vector A, Vector B) {
    return A.x*B.y - A.y*B.x;
}

Vector operator * (ll t, Vector A) {
    return Vector(A.x*t, A.y*t);
}

Vector operator * (Vector A, ll t) {
    return Vector(A.x*t, A.y*t);
}

Vector operator / (Vector A, ll t) {
    return Vector(A.x/t, A.y/t);
}

struct Line {
    Point p[2];
    explicit Line(Point p0 = Point(0, 0), Point p1 = Point(0, 0)) {
        p[0] = p0, p[1] = p1;
    }
};

bool onSeg(Point p, Line AB) {
    return sgn((AB.p[0]-p) ^ (AB.p[1]-p)) ==0 && sgn((AB.p[0]-p) * (AB.p[1]-p)) < 0;
}

bool intersect(Line L1, Line L2, bool yg = 1) {
    Point a1 = L1.p[0], a2 = L1.p[1];
    Point b1 = L2.p[0], b2 = L2.p[1];
    ll c1 = (a2 - a1) ^ (b1 - a1);
    ll c2 = (a2 - a1) ^ (b2 - a1);
    ll c3 = (b2 - b1) ^ (a1 - b1);
    ll c4 = (b2 - b1) ^ (a2 - b1);
    if(yg && (!sgn(c1) || !sgn(c2) || !sgn(c3) || !sgn(c4))) {
        bool f1 = onSeg(b1, Line(a1, a2));
        bool f2 = onSeg(b2, Line(a1, a2));
        bool f3 = onSeg(a1, Line(b1, b2));
        bool f4 = onSeg(a2, Line(b1, b2));
        return f1 | f2 | f3 | f4;
    }
    return (sgn(c1)*sgn(c2) < 0 && sgn(c3)*sgn(c4) < 0);
}

bool operator < (Vector A, Vector B) {
    int a = Vecpos(A), b = Vecpos(B);
    if(a != b) return a < b;
    ll tmp = A ^ B;
    if(tmp == 0) return (A*A) < (B*B);
    return tmp > 0;
}

void solve() {
    Point a[2];
    Line h[2];
    for(int i : {0, 1})
        cin >> a[i].x >> a[i].y;
    for(int i : {0, 1})
        for(int j : {0, 1})
            cin >> h[i].p[j].x >> h[i].p[j].y;
    if(intersect(Line(a[0], a[1]), h[0]) == 0 && intersect(Line(a[0], a[1]), h[1]) == 0) {
        printf("0\n");
        return;
    }
    if(((a[0] - a[1])^(h[0].p[0] - h[0].p[1])) == 0 || ((a[0] - a[1])^(h[1].p[0] - h[1].p[1])) == 0) {
        printf("1\n");
        return;
    }
    if(onSeg(h[0].p[0], Line(a[0], a[1])) || onSeg(h[0].p[1], Line(a[0], a[1]))) {
        printf("1\n");
        return;
    }
    if(onSeg(h[1].p[0], Line(a[0], a[1])) || onSeg(h[1].p[1], Line(a[0], a[1]))) {
        printf("1\n");
        return;
    }
    if(!intersect(h[0], h[1], 0)) {
        printf("1\n");
        return;
    }
    for(int i : {0, 1}) {
        if(intersect(Line(a[0], a[1]), h[i]) == 0) {
            printf("1\n");
            return;
        }
    }
    vector<pair<Vector, int> > vt;
    for(int i : {0, 1})
        for(int j : {0, 1}) {
            vt.emplace_back(h[i].p[j] - a[0], i*2 + j);
            vt.emplace_back(h[i].p[j] - a[1], i*2 + j);
        }
    sort(vt.begin(), vt.end());
    for(int i=0; i<4; i++) {
        int l = -1, r = -1;
        for(int j=0; j<8; j++) {
            if(vt[j].second != i) continue;
            if(l == -1) l = j;
            else r = j;
        }
        if((vt[l].first ^ vt[r].first) >= 0) {
            for(int j=l+1; j<r; j++) {
                if((vt[l].first ^ vt[j].first) == 0 || (vt[r].first ^ vt[j].first) == 0)
                    continue;
                printf("1\n");
                return;
            }
            continue;
        }
        else {
            for(int j=0; j<l; j++) {
                if((vt[l].first ^ vt[j].first) == 0 || (vt[r].first ^ vt[j].first) == 0)
                    continue;
                printf("1\n");
                return;
            }
            for(int j=r+1; j<8; j++) {
                if((vt[l].first ^ vt[j].first) == 0 || (vt[r].first ^ vt[j].first) == 0)
                    continue;
                printf("1\n");
                return;
            }
        }
    }
    printf("2\n");
    return;
}

int main() {
//    freopen("nh.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    while(T--) {
        solve();
    }
}