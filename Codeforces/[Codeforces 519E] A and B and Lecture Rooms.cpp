#include <math.h>
#include <stdio.h>
#include <algorithm>

const int N = 1e5 + 5;
const int M = 25;

int n, m;
int depth[N], fa[N][M + 5], size[N];
int head[N], num_edge;

struct Node
{
    int next, to;
} edge[N << 1];
struct node
{
    int x, y, res;
};

void add_edge(int u, int v)
{
    edge[++num_edge].next = head[u];
    head[u] = num_edge;
    edge[num_edge].to = v;
}

void dfs(int u, int fath)
{
    size[u] = 1;
    depth[u] = depth[fath] + 1;
    fa[u][0] = fath;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fath)
            continue;
        dfs(v, u);
        size[u] += size[v];
    }
}

node LCA(int x, int y)
{
    if (depth[x] < depth[y])
        std::swap(x, y);
    for (int i = M; i >= 0 and depth[x] != depth[y]; i--)
        if (depth[fa[x][i]] >= depth[y])
            x = fa[x][i];
    if (x == y)
        return node{x, x, x};
    for (int i = M; i >= 0; i--)
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return node{x, y, fa[x][0]};
}

int main()
{
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++)
        scanf("%d%d", &u, &v), add_edge(u, v), add_edge(v, u);
    dfs(1, 0);
    for (int j = 1; j <= M; j++)
        for (int i = 1; i <= n; i++)
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
    scanf("%d", &m);
    for (int i = 1, x, y; i <= m; i++)
    {
        scanf("%d%d", &x, &y);
        if (x == y)
        {
            printf("%d\n", n);
            continue;
        }
        node lca = LCA(x, y);
        int dis = depth[x] + depth[y] - 2 * depth[lca.res];
        if (dis & 1)
        {
            puts("0");
            continue;
        }
        if (depth[x] < depth[y])
            std::swap(x, y);
        int mid = x;
        for (int i = M; i >= 0; i--)
            if (depth[x] - depth[fa[mid][i]] < dis / 2 && depth[fa[mid][i]] > depth[lca.res])
                mid = fa[mid][i];
        if (fa[mid][0] == lca.res)
            printf("%d\n", n - size[lca.x] - size[lca.y]);
        else
            printf("%d\n", size[fa[mid][0]] - size[mid]);
    }
    return 0;
}