#include <stdio.h>
#include <algorithm>

const int N = 3e5 + 5;
const int M = N << 1;

int n, m, ans;
int head[N], num_edge;
int size[N], f[N];

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

void dfs1(int u, int fa)
{
    for (int i = head[u], v; i; i = edge[i].next)
        if ((v = edge[i].to) != fa)
            dfs1(v, u), size[u]++;
}

void dfs2(int u, int fa)
{
    int res1 = 0, res2 = 0;
    f[u] = 1;
    for (int i = head[u], v; i; i = edge[i].next)
        if ((v = edge[i].to) != fa)
        {
            dfs2(v, u);
            f[u] = std::max(f[u], f[v] + 1 + std::max(0, size[u] - 1));
            if (f[v] > res1)
                res2 = res1, res1 = f[v];
            else if (f[v] > res2)
                res2 = f[v];
        }
    ans = std::max(ans, res1 + res2 + 1 + (u != 1) + std::max(0, size[u] - 2));
}

int main()
{
    n = read(), m = read();
    for (int i = 1, u, v; i <= m; i++)
        u = read(), v = read(), add_edge(u, v), add_edge(v, u);
    return dfs1(1, 0), dfs2(1, 0), printf("%d", ans), 0;
}