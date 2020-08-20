#include <stdio.h>
#include <algorithm>

const int N = 1e5 + 5;

int n, ans;
int head[N], num_edge;
int a[N], size[N];

struct Node
{
    int next, to, dis;
} edge[N << 1];

void add_edge(int u, int v, int dis) { edge[++num_edge] = Node{head[u], v, dis}, head[u] = num_edge; }

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
    size[u] = 1;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v != fa)
            dfs1(v, u), size[u] += size[v];
    }
}

void dfs2(int u, int fa, int sum)
{
    if (sum > a[u])
        ans += size[u];
    else
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].to, dis = edge[i].dis;
            if (v != fa)
                dfs2(v, u, std::max(0, sum + dis));
        }
}

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int u = 2, v, dis; u <= n; u++)
        v = read(), dis = read(), add_edge(u, v, dis), add_edge(v, u, dis);
    dfs1(1, 0), dfs2(1, 0, 0);
    printf("%d", ans);
    return 0;
}