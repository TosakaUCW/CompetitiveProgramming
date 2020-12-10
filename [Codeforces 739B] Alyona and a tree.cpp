#include <stdio.h>

const int N = 2e5 + 5;
const int M = 4e5 + 5;
const int LOGN = 20;

int n, num_edge, head[N];
int ans[N], fa[LOGN + 5][N], val[N];
long long depth[N];

struct Node
{
    int next, to, dist;
} edge[M];

void add_edge(int u, int v, int dist)
{
    edge[++num_edge].next = head[u];
    edge[num_edge].to = v;
    edge[num_edge].dist = dist;
    head[u] = num_edge;
}

void dfs_1(int u)
{
    for (int i = 1; i <= LOGN; ++i)
        fa[i][u] = fa[i - 1][fa[i - 1][u]];
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        int dist = edge[i].dist;
        fa[0][v] = u;
        depth[v] = depth[u] + dist;
        dfs_1(v);
    }
}

void solve(int u)
{
    int x = u;
    for (int i = LOGN; i >= 0; i--)
        if (fa[i][x] and depth[u] - depth[fa[i][x]] <= val[u])
            x = fa[i][x];
    if (x != 1)
        ans[fa[0][x]]--;
    if (u != 1)
        ans[fa[0][u]]++;
}

void dfs_2(int u)
{
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        dfs_2(v);
        ans[u] += ans[v];
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &val[i]);
    for (int i = 2; i <= n; i++)
    {
        int u, dist;
        scanf("%d%d", &u, &dist);
        add_edge(u, i, dist);
    }
    dfs_1(1);
    for (int i = 1; i <= n; i++)
        solve(i);
    dfs_2(1);
    for (int i = 1; i <= n; i++)
        printf("%d ", ans[i]);
    return 0;
}