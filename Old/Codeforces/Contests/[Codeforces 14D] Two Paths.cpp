#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e5 + 5;

int n;
int head[N], num_edge;
int ans, res[2], f[N][2];

struct Node
{
    int next, to, from;
} edge[N << 1];

void add_edge(int u, int v)
{
    edge[++num_edge] = Node{head[u], v, u};
    head[u] = num_edge;
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

void dfs(int u, int fa, int del, int x)
{
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fa or v == del)
            continue;
        dfs(v, u, del, x);
        res[x] = std::max(res[x], f[u][x] + f[v][x] + 1);
        f[u][x] = std::max(f[u][x], f[v][x] + 1);
    }
}

int main()
{
    n = read();
    for (int i = 1, u, v; i < n; i++)
        u = read(), v = read(), add_edge(u, v), add_edge(v, u);
    for (int i = 1; i <= num_edge; i += 2)
    {
        res[0] = res[1] = 0;
        memset(f, 0, sizeof f);
        dfs(edge[i].from, 0, edge[i].to, 0);
        dfs(edge[i].to, 0, edge[i].from, 1);
        ans = std::max(ans, res[0] * res[1]);
    }
    printf("%d", ans);
    return 0;
}