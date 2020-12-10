#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 3e5 + 5;
const int M = 6e5 + 5;
const int K = 25;

int n;
int a[N];
int head[N], num_edge;
int depth[N], fa[N][K + 1];
int c[N], ans[N];

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

void dfs1(int u, int fath)
{
    depth[u] = depth[fath] + 1, fa[u][0] = fath;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fath)
            continue;
        dfs1(v, u);
    }
}

int dfs2(int u, int fath)
{
    ans[u] = c[u];
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fath)
            continue;
        ans[u] += dfs2(v, u);
    }
    return ans[u];
}

int lca(int x, int y)
{
    if (depth[x] < depth[y])
        std::swap(x, y);
    for (int i = K; ~i; i--)
        if (depth[fa[x][i]] >= depth[y])
            x = fa[x][i];
    if (x == y)
        return x;
    for (int i = K; ~i; i--)
        if (fa[x][i] != fa[y][i])
            x = fa[x][i], y = fa[y][i];
    return fa[x][0];
}

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1, u, v; i < n; i++)
        u = read(), v = read(), add_edge(u, v), add_edge(v, u);
    dfs1(1, 0);
    for (int j = 1; j <= K; j++)
        for (int i = 1; i <= n; i++)
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
    for (int i = 1, k; i < n; i++)
        k = lca(a[i], a[i + 1]), c[k]--, c[fa[k][0]]--, c[a[i]]++, c[a[i + 1]]++;
    dfs2(1, 0);
    for (int i = 1; i <= n; i++)
        printf("%d\n", ans[i] - (i != a[1]));
    return 0;
}