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

struct Point {
    ll x, y;
    Point(ll X = 0, ll Y = 0){
        x = X, y = Y;
    }
};

typedef Point Vector;

ll operator * (Vector A, Vector B) {
    return A.x * B.x + A.y * B.y;
}

ll operator ^ (Vector A, Vector B) {
    return A.x * B.y - A.y * B.x;
}

int vecPos(Vector A) {
    if(A.y < 0 || (A.y == 0 && A.x < 0))
        return 1;
    return 0;
}

bool operator < (Vector A, Vector B) {
    int pa = vecPos(A), pb = vecPos(B);
    if(pa != pb) return pa < pb;
    return (A ^ B) > 0;
}

ll getlen(Vector A) {
    return sqrt(A * A);
}

int main() {
    freopen("nh.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<pair<Vector, int>> v(n);
    for(int i=0; i<n; i++)
        cin >> v[i].first.x >> v[i].first.y, v[i].second = i;
    sort(v.begin(), v.end());
    arr Ans = {0, 1};
    auto check = [&](Vector A1, Vector A2, Vector B1, Vector B2) {
        return A1 * A2 * getlen(B1) * getlen(B2) > B1 * B2 * getlen(A1) * getlen(A2);
    };
    for(int i=0; i<n; i++) {
        int d = i + 1;
        if(d == n) d = 0;
        if(check(v[i].first, v[d].first, v[Ans[0]].first, v[Ans[1]].first))
            Ans = {i, d};
    }
    printf("%d %d\n", v[Ans[0]].second + 1, v[Ans[1]].second + 1);
    return 0;
}






