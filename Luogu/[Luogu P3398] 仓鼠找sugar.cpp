#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e5 + 5;
const int M = 2e5 + 5;
const int K = 25;

int n, q;
int head[N], num_edge;
int f[N][K + 5], depth[N];

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

void dfs(int u, int fa)
{
    depth[u] = depth[fa] + 1, f[u][0] = fa;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v != fa)
            dfs(v, u);
    }
}

int lca(int x, int y)
{
    if (depth[x] < depth[y])
        std::swap(x, y);
    for (int i = K; ~i; i--)
        if (depth[f[x][i]] >= depth[y])
            x = f[x][i];
    if (x == y)
        return x;
    for (int i = K; ~i; i--)
        if (f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    return f[x][0];
}

int dis(int a, int b) { return depth[a] + depth[b] - 2 * depth[lca(a, b)]; }

int main()
{
    n = read(), q = read();
    for (int i = 1, u, v; i < n; i++)
        u = read(), v = read(), add_edge(u, v), add_edge(v, u);
    dfs(1, 0);
    for (int j = 1; j <= K; j++)
        for (int i = 1; i <= n; i++)
            f[i][j] = f[f[i][j - 1]][j - 1];
    while (q--)
    {
        int a = read(), b = read(), c = read(), d = read();
        int x = lca(a, b), y = lca(c, d);
        if (depth[x] > depth[y])
        {
            if (dis(c, x) + dis(d, x) == dis(c, d))
                puts("Y");
            else
                puts("N");
        }
        else
        {
            if (dis(a, y) + dis(b, y) == dis(a, b))
                puts("Y");
            else
                puts("N");
        }
    }
    return 0;
}