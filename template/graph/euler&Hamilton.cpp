//经过所有边恰好一次的路径叫做欧拉路径，如果起点终点相同，则为欧拉回路
//同理经过所有点恰好一次的路径叫做哈密顿路径，闭合则为哈密顿回路
//有向图欧拉路：所有点入度=出度，或者恰好有一个点入度-出度=1，有一个点出度-入度=1，其他点入度=出度
//有向图欧拉回路：所有点入度=出度
//无向图欧拉路：恰好有两个点度数为奇数
//无向图欧拉回路：所有点的度数均为偶数
//如果一个有向图的有向边视为无向边后是联通的且满足上述条件，则必有欧拉路/回路
//求最短哈密顿回路：旅行商问题

#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;

int n, m;
int cur[maxn], du[maxn];
vector<int> e[maxn];
stack<int> st;

void dfs(int x) {
    for(int sz=e[x].size(); cur[x]<sz;) {
        cur[x]++;//使用cur数组优化
        dfs(e[x][cur[x]-1]);
    }
    st.push(x);//必须最后入栈，不能写成一开始入队列
}

//要求欧拉回路的话就稍微改一改，判断必须入度等于出度即可
void eulerpath() {
    memset(cur, 0, sizeof(cur));
    for(int i=1; i<=n; i++)
        sort(e[i].begin(), e[i].end());//题目要求字典序最小的话需要排序
    int S = -1, T = -1;
    for(int i=1; i<=n; i++) {
        if(du[i]==0) continue;
        if(du[i]>1||du[i]<-1) {
            printf("No\n");
            return;
        }
        if(du[i]==1) {
            if(T!=-1) {
                printf("No\n");
                return;
            }
            T = i;
        }
        else {
            if(S!=-1) {
                printf("No\n");
                return;
            }
            S = i;
        }
    }
    if(S==-1&&T==-1)
        S = T = 1;
    if(S==-1||T==-1)  {
        printf("No\n");
        return;
    }
    dfs(S);
    while(!st.empty())
        printf("%d ", st.top()), st.pop();
    return;
}

int main() {
//	freopen("nh.in", "r", stdin);
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; i++) {
        int x, y;scanf("%d%d", &x, &y);
        e[x].push_back(y);
        du[x]--, du[y]++;
    }
    eulerpath();
    return 0;
}









