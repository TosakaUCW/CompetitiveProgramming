#include <stdio.h>
#include <algorithm>

const int N = 100 + 5;

int n, m;
int num_edge, head[N];
int f[N][N];

struct Node
{
    int next, to, dis;
} edge[2 * N];

void add_edge(int u, int v, int dis)
{
    edge[++num_edge].next = head[u];
    edge[num_edge].to = v;
    edge[num_edge].dis = dis;
    head[u] = num_edge;
}

void dfs(int u, int fa)
{
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        int dis = edge[i].dis;
        if (v == fa)
            continue;
        dfs(v, u);
        for (int k = m; k >= 1; k--)
            for (int j = 1; j <= k; j++)
                f[u][k] = std::max(f[u][k], f[u][k - j] + f[v][j - 1] + dis);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i < n; i++)
    {
        int u, v, dis;
        scanf("%d%d%d", &u, &v, &dis);
        add_edge(u, v, dis), add_edge(v, u, dis);
    }
    dfs(1, 0);
    printf("%d", f[1][m]);
    return 0;
}