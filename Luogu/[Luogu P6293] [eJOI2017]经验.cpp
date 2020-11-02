#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

const int N = 1e5 + 5;
const int M = N << 1;

int n;
int w[N], f[N], g[N];
int head[N], num_edge;

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
    int k = 0;
    for (int i = head[u], v; i; i = edge[i].next)
        if ((v = edge[i].to) != fa)
            dfs(v, u), k += std::max(f[v], g[v]);
    f[u] = g[u] = k;
    for (int i = head[u], v; i; i = edge[i].next)
        if ((v = edge[i].to) != fa and w[u] >= w[v])
            f[u] = std::max(f[u], k - std::max(f[v], g[v]) + w[u] - w[v] + f[v]);
        else if (v != fa and w[u] <= w[v])
            g[u] = std::max(g[u], k - std::max(f[v], g[v]) + w[v] - w[u] + g[v]);
}

signed main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        w[i] = read();
    for (int i = 1, u, v; i < n; i++)
        u = read(), v = read(), add_edge(u, v), add_edge(v, u);
    dfs(1, 0);
    return printf("%lld", std::max(f[1], g[1])), 0;
}