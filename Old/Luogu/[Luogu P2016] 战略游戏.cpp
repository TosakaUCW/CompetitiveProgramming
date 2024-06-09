#include <stdio.h>
#include <algorithm>

const int N = 1500 + 5;

int n;
int head[N], num_edge;
int f[N][2];

struct Node
{
    int next, to;
} edge[2 * N];

void add_edge(int u, int v)
{
    edge[++num_edge].next = head[u];
    edge[num_edge].to = v;
    head[u] = num_edge;
}

void dfs(int u, int fa)
{
    f[u][0] = 0, f[u][1] = 1;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fa)
            continue;
        dfs(v, u);
        f[u][0] += f[v][1];
        f[u][1] += std::min(f[v][0], f[v][1]);
    }
}

int main()
{
    scanf("%d", &n);
    for (int u = 1; u <= n; u++)
    {
        int k;
        scanf("%*d%d", &k);
        for (int i = 1; i <= k; i++)
        {
            int v;
            scanf("%d", &v);
            add_edge(u, v + 1), add_edge(v + 1, u);
            ;
        }
    }
    dfs(1, 0);
    printf("%d", std::min(f[1][0], f[1][1]));
    return 0;
}