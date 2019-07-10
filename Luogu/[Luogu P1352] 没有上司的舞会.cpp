#include <stdio.h>
#include <algorithm>

const int N = 6000 + 5;

int n;
int ind[N], val[N], head[N], num_edge;
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

void dfs(int u)
{
    f[u][1] = val[u];
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        dfs(v);
        f[u][1] += f[v][0];
        f[u][0] += std::max(f[v][1], f[v][0]);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &val[i]);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        ind[u]++;
        add_edge(v, u);
    }
    for (int i = 1; i <= n; i++)
        if (!ind[i])
        {
            dfs(i);
            printf("%d", std::max(f[i][0], f[i][1]));
            break;
        }
    return 0;
}