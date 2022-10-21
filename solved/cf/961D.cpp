#include<bits/stdc++.h>

#define mp(x, y) make_pair(x, y)
#define qmin(x, y) (x = min(x, y))
#define qmax(x, y) (x = max(x, y))

using ll = long long;
using namespace std;

typedef pair<int, int> pii;
typedef array<int, 2> arr;

const int maxn = 1e5+100;
//const ll P = ;

int n;
arr a[maxn];

arr operator - (arr A, arr B) {
    return {A[0] - B[0], A[1] - B[1]};
}

ll operator ^ (arr A, arr B) {
    return 1ll*A[0]*B[1] - 1ll*A[1]*B[0];
}

bool work(arr A, arr B, arr C) {
    arr v = A - B;
    arr w = A - C;
    return (v ^ w) == 0ll;
}

void check(arr A, arr B) {
    vector<arr> las;
    for(int i=1; i<=n; i++)
        if(!work(A, B, a[i]))
            las.push_back(a[i]);
    if(las.size() <= 2) {
        printf("YES\n");
        exit(0);
    }
    for(int i=2; i<las.size(); i++)
        if(!work(las[0], las[1], las[i]))
            return;
    printf("YES\n");
    exit(0);
}

int main() {
//    freopen("nh.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i][0] >> a[i][1];
    if(n <= 4) {
        printf("YES\n");
        return 0;
    }
    check(a[1], a[2]);
    check(a[1], a[3]);
    check(a[2], a[3]);
    printf("NO\n");
    return 0;
}






