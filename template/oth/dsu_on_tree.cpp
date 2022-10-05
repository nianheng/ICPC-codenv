#include<bits/stdc++.h>

using namespace std;

#define qmin(x,y) (x=min(x,y))
#define qmax(x,y) (x=max(x,y))
#define mp(x,y) make_pair(x,y)

typedef long long ll;
typedef pair<int,int> pii;

namespace fast_IO {
    inline ll read() {
        ll ans = 0, fh = 1;
        char ch = getchar();
        while(ch<'0' || ch>'9') {
            if(ch == '-') fh = 0;
            ch = getchar();
        }
        while(ch>='0' && ch<='9')
            ans = (ans<<1) + (ans<<3) + (ch^48), ch = getchar();
        if(fh) return ans;
        else return -ans;
    }
}

using namespace fast_IO;

const int maxn = 1e5+100, maxm = 1.1e6+100;
//const ll P = ;

int n;
int a[maxn], son[maxn], siz[maxn];
int f[maxm][18][2];
ll Ans;

vector<int> e[maxn];

inline void add(int x, int y) {
    e[x].push_back(y);
    e[y].push_back(x);
}

//dfs1求重儿子
void dfs1(int x, int Fa) {
    siz[x] = 1, son[x] = 0;
    for(int y : e[x]) {
        if(y == Fa) continue;
        dfs1(y, x);
        if(son[x] == 0 || siz[y] > siz[son[x]])
            son[x] = y;
        siz[x] += siz[y];
    }
}

inline void ins(int x, int A, int ms) {
    for(int i=17; i>=0; i--)
        f[A][i][(x>>i)&1] += ms;
}

inline void calc(int x, int A) {
    for(int i=17; i>=0; i--)
        Ans += (1ll<<i) * f[A][i][((x>>i)&1)^1];
}

void query(int x, int Fa, int Tp) {
    calc(x, a[x]^Tp);//统计单点
    for(int y : e[x]) {
        if(y == Fa) continue;
        query(y, x, Tp);//统计子树
    }
}

void revise(int x, int Fa, int ms) {
    ins(x, a[x], ms);//修改单点
    for(int y : e[x]) {
        if(y == Fa) continue;
        revise(y, x, ms);//修改子树
    }
}

void dsu(int x, int Fa, int ms) {
    //先处理完所有轻儿子的答案，并不保留中间数组
    for(int y : e[x]) {
        if(y == Fa || y == son[x]) continue;
        dsu(y, x, 0);
    }
    if(son[x]) dsu(son[x], x, 1);//处理重儿子的答案，保留中间数组
    for(int y : e[x]) {
        if(y == Fa || y == son[x]) continue;
        query(y, x, a[x]), revise(y, x, 1);//一个个处理轻儿子的答案
    }
    ins(x, a[x], 1);//统计当前单点的答案；
    if(!ms) revise(x, Fa, -1);//删除掉当前子树的中间数组
}

int main(){
//    freopen("nh.in","r",stdin);
//    freopen("zhy.out","w",stdout);
    n = read();
    for(int i=1; i<=n; i++)
        a[i] = read();
    for(int i=1; i<n; i++) {
        int x = read(), y = read();
        add(x, y);
    }
    dfs1(1, 0);
    dsu(1, 0, 0);
    printf("%lld\n", Ans);
    return 0;
}











