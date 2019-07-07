#include <stdio.h>
#include <algorithm>

const int N = 1e4 + 5;
const int M = 2e4 + 5;
const int LOG2N = 15;

int n, root, m;
int head[N], num_edge;
int size[N], sum[N], ans[N];

struct Node
{
    int next, to;
} edge[M];

void add_edge(int u, int v)
{
    edge[++num_edge].next = head[u];
    edge[num_edge].to = v;
    head[u] = num_edge;
}

void dfs(int u, int father)
{
    size[u] = 1;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v != father)
        {
            dfs(v, u);
            size[u] += size[v];
            sum[u] += size[v] * size[v];
        }
    }
    ans[u] = size[u] * size[u] - sum[u];
}

int main()
{
    scanf("%d%d%d", &n, &root, &m);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs(root, 0);
    for (int i = 1; i <= m; i++)
    {
        int x;
        scanf("%d", &x);
        printf("%d\n", ans[x]);
    }
    return 0;
}