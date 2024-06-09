#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

const int N = 3e3 + 5;
const int M = N << 1;
const int INF = 1 << 30;

int n, m, ans = INF;
int s1, s2, t1, t2;
int head[N], num_edge;
bool vis[N];
int dis[4][N];
std::queue<int> Q;

struct Node
{
    int next, to;
} edge[M];

void add_edge(int u, int v) { edge[++num_edge] = Node{head[u], v}, head[u] = num_edge; }

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

void bfs(int s, int opt)
{
    memset(vis, false, sizeof vis);
    Q.push(s), vis[s] = true, dis[opt][s] = 0;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int i = head[u], v; i; i = edge[i].next)
            if (!vis[v = edge[i].to])
                Q.push(v), dis[opt][v] = dis[opt][u] + 1, vis[v] = true;
    }
}

int main()
{
    memset(dis, 0x3f, sizeof dis);
    n = read(), m = read();
    for (int i = 1, u, v; i <= m; i++)
        u = read(), v = read(), add_edge(u, v), add_edge(v, u);
    s1 = read(), t1 = read(), s2 = read(), t2 = read();
    bfs(1, 1), bfs(s1, 2), bfs(s2, 3);
    for (int i = 1; i <= n; i++)
        if (dis[1][i] + dis[2][i] <= t1 and dis[1][i] + dis[3][i] <= t2)
            ans = std::min(ans, dis[1][i] + dis[2][i] + dis[3][i]);
    printf("%d", ans == INF ? -1 : num_edge / 2 - ans);
    return 0;
}