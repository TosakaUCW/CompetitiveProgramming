#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 5e5 + 5;
const int M = 25;

int n, m;
int head[N], num_edge;
int depth[N], fa[N][M + 5];

struct Node
{
    int next, to;
} edge[N << 1];

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

void dfs(int u, int fath)
{
    depth[u] = depth[fath] + 1;
    fa[u][0] = fath;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v != fath)
            dfs(v, u);
    }
}

int lca(int x, int y)
{
    if (depth[x] < depth[y])
        std::swap(x, y);
    for (int i = M; ~i; i--)
        if (depth[fa[x][i]] >= depth[y])
            x = fa[x][i];
    if (x == y)
        return x;
    for (int i = M; ~i; i--)
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}

int main()
{
    n = read(), m = read();
    for (int i = 1, u, v; i < n; i++)
        u = read(), v = read(), add_edge(u, v), add_edge(v, u);
    dfs(1, 0);
    for (int j = 1; j <= M; j++)
        for (int i = 1; i <= n; i++)
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
    for (int x, y, z, a, b, c; m; m--)
    {
        x = read(), y = read(), z = read();
        a = lca(x, y), b = lca(x, z), c = lca(y, z);
        printf("%d %d\n", a ^ b ^ c, depth[x] + depth[y] + depth[z] - depth[a] - depth[b] - depth[c]);
    }
    return 0;
}