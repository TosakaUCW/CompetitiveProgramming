#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 3e5 + 5;
const int M = 25;

int n, m;
int head[N], num_edge;
int depth[N], fa[N][M + 5], dis[N];
int d[N], tot, res, max_dis;

struct Node
{
    int next, to, dis;
} edge[N << 1];
struct node
{
    int u, v, lca, dis;
} e[N << 1];

void add_edge(int u, int v, int dis)
{
    edge[++num_edge].next = head[u];
    head[u] = num_edge;
    edge[num_edge].to = v;
    edge[num_edge].dis = dis;
}

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

void dfs(int u, int fath)
{
    depth[u] = depth[fath] + 1;
    fa[u][0] = fath;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (fath == v)
            continue;
        dis[v] = dis[u] + edge[i].dis;
        dfs(v, u);
    }
}

int lca(int x, int y)
{
    if (depth[x] < depth[y])
        std::swap(x, y);
    for (int j = M; j >= 0 and depth[x] != depth[y]; j--)
        if (depth[fa[x][j]] >= depth[y])
            x = fa[x][j];
    if (x == y)
        return x;
    for (int j = M; j >= 0; j--)
        if (fa[x][j] != fa[y][j])
            x = fa[x][j], y = fa[y][j];
    return fa[x][0];
}

void dfs2(int u, int fath)
{
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fath)
            continue;
        dfs2(v, u);
        d[u] += d[v];
    }
    if (d[u] == tot and dis[u] - dis[fath] > res)
        res = dis[u] - dis[fath];
}

bool judge(int x)
{
    tot = 0, res = 0;
    memset(d, 0, sizeof d);
    for (int i = 1; i <= m; i++)
        if (e[i].dis > x)
        {
            d[e[i].u]++;
            d[e[i].v]++;
            d[e[i].lca] -= 2;
            tot++;
        }
    dfs2(1, 0);
    return x + res >= max_dis;
}

int main()
{
    n = read(), m = read();
    for (int i = 1, u, v, dis; i < n; i++)
        u = read(), v = read(), dis = read(), add_edge(u, v, dis), add_edge(v, u, dis);
    dfs(1, 0);
    for (int j = 1; j <= M; j++)
        for (int i = 1; i <= n; i++)
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
    for (int i = 1; i <= m; i++)
    {
        e[i].u = read(), e[i].v = read();
        e[i].lca = lca(e[i].u, e[i].v);
        e[i].dis = dis[e[i].u] + dis[e[i].v] - 2 * dis[e[i].lca];
        max_dis = std::max(max_dis, e[i].dis);
    }
    int L = 0, R = max_dis, ans = 0;
    while (L <= R)
    {
        int mid = (L + R) / 2;
        if (judge(mid))
            ans = mid, R = mid - 1;
        else
            L = mid + 1;
    }
    printf("%d", ans);
    return 0;
}