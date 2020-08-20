#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e6 + 5;

int n, ans;
int head[N], num_edge;

struct Node
{
    int next, to;
} edge[N << 1];

void add_edge(int u, int v)
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
    ans = std::max(ans, depth);
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fa)
            continue;
        dfs(v, u, depth + 1);
    }
}

int main()
{
    n = read();
    for (int i = 1, L, R; i <= n; i++)
    {
        L = read(), R = read();
        if (L)
            add_edge(i, L), add_edge(L, i);
        if (R)
            add_edge(i, R), add_edge(R, i);
    }
    dfs(1, 0, 1);
    printf("%d", ans);
    return 0;
}