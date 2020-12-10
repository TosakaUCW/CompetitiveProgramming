#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e5 + 5;

int n, m;
int val[N], head[N], num_edge;
int f[N], size[N], ans = 1 << 30;

struct Node
{
    int next, to;
} edge[N];

int add_edge(int u, int v)
{
    edge[++num_edge].next = head[u];
    head[u] = num_edge;
    edge[num_edge].to = v;
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

void dfs(int u, int fa, int depth)
{
    size[u] = val[u];
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fa)
            continue;
        dfs(v, u, depth + 1);
        size[u] += size[v];
    }
    f[1] += depth * val[u];
}

void go(int u, int fa)
{
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fa)
            continue;
        f[v] = f[u] + size[1] - size[v] - size[v];
        go(v, u);
    }
    ans = std::min(ans, f[u]);
}

int main()
{
    n = read();
    for (int i = 1, L, R; i <= n; i++)
    {
        val[i] = read(), L = read(), R = read();
        if (L)
            add_edge(i, L), add_edge(L, i);
        if (R)
            add_edge(i, R), add_edge(R, i);
    }
    dfs(1, 0, 0);
    go(1, 0);
    printf("%d", ans);
    return 0;
}