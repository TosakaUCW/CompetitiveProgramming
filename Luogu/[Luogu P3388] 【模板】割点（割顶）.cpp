#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <vector>

const int N = 1e7 + 5;

int n, m, ans;
int head[N], num_edge;

int timer;
int dfn[N], low[N];
bool cut[N];

struct Node
{
    int next, to;
} edge[N];

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

void tarjan(int u, int fa)
{
    dfn[u] = low[u] = ++timer;
    int child = 0;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (!dfn[v])
        {
            tarjan(v, fa);
            low[u] = std::min(low[u], low[v]);
            if (low[v] >= dfn[u] and u != fa)
                cut[u] = true;
            if (u == fa)
                child++;
        }
        low[u] = std::min(low[u], dfn[v]);
    }
    if (child >= 2 and u == fa)
        cut[u] = true;
}

int main()
{
    n = read(), m = read();
    for (int i = 1, u, v; i <= m; i++)
        u = read(), v = read(), add_edge(u, v), add_edge(v, u);
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i, i);
    for (int i = 1; i <= n; i++)
        ans += cut[i];
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++)
        if (cut[i])
            printf("%d ", i);
    return 0;
}