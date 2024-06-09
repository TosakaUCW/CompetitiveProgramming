#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <math.h>

#define int long long

const int N = 5e2 + 5;
const int M = 1e4 + 5;
const int INF = 1LL << 60;

int n, m;
int head[N], num_edge;
int max[2][N][N], fa[N];

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

struct Node
{
    int next, to, dis;
} edge[M];
struct Edge
{
    int u, v, dis;
    bool flag;
    void input() { u = read(), v = read(), dis = read(); }
    bool friend operator<(Edge a, Edge b) { return a.dis < b.dis; }
} e[M];

void add_edge(int u, int v, int dis) { edge[++num_edge] = Node{head[u], v, dis}, head[u] = num_edge; }

int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }

void dfs(int top, int u, int fa)
{
    for (int i = head[u], v; i; i = edge[i].next)
        if ((v = edge[i].to) != fa)
        {
            max[0][top][v] = max[0][top][u], max[1][top][v] = max[1][top][u];
            int w = edge[i].dis;
            if (w > max[0][top][v])
                max[1][top][v] = max[0][top][v],
                max[0][top][v] = w;
            else if (w < max[0][top][v] and w > max[1][top][v])
                max[1][top][v] = w;
            dfs(top, v, u);
        }
}

signed main()
{
    n = read(), m = read();
    for (int i = 1; i <= m; i++)
        e[i].input();
    std::sort(e + 1, e + 1 + m);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    int tot = 0;
    for (int i = 1; i <= m; i++)
    {
        int dx = find(e[i].u), dy = find(e[i].v);
        if (dx ^ dy)
            fa[dx] = dy, add_edge(e[i].u, e[i].v, e[i].dis), add_edge(e[i].v, e[i].u, e[i].dis), e[i].flag = true, tot += e[i].dis;
    }
    for (int i = 1; i <= n; i++)
        dfs(i, i, 0);
    int ans = INF;
    for (int i = 1; i <= m; i++)
        if (!e[i].flag)
        {
            int u = e[i].u, v = e[i].v;
            if (e[i].dis > max[0][u][v])
                ans = std::min(ans, tot + e[i].dis - max[0][u][v]);
            else if (e[i].dis > max[1][u][v])
                ans = std::min(ans, tot + e[i].dis - max[1][u][v]);
        }
    return printf("%lld", ans), 0;
}