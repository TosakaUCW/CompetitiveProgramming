#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e5 + 5;

int n, k;
int head[N], num_edge;
int fa[N], depth[N], node, node_depth;
int max[N], res[N], ans;

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

void dfs_1(int u, int fath)
{
    if (node_depth < depth[u])
        node_depth = depth[u], node = u;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fath)
            continue;
        depth[v] = depth[u] + 1;
        dfs_1(v, u);
    }
}

void dfs_2(int u, int fath)
{
    if (node_depth < depth[u])
        node_depth = depth[u], node = u;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fath)
            continue;
        depth[v] = depth[u] + 1;
        fa[v] = u;
        dfs_2(v, u);
    }
}

void dfs_3(int u, int fath)
{
    max[u] = depth[u];
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fath)
            continue;
        depth[v] = depth[u] + 1;
        dfs_3(v, u);
        max[u] = std::max(max[u], max[v]);
    }
}

bool cmp(int a, int b) { return a > b; }

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1, u, v; i < n; i++)
        scanf("%d%d", &u, &v), add_edge(u, v), add_edge(v, u);
    dfs_1(1, 0);
    memset(depth, 0, sizeof depth);
    node_depth = 0;
    dfs_2(node, 0);
    for (int i = 1, k = (depth[node] + 1) / 2; i <= k; i++)
        node = fa[node];
    memset(depth, 0, sizeof depth);
    dfs_3(node, 0);
    for (int i = 1; i <= n; i++)
        res[i] = max[i] - depth[i];
    std::sort(res + 1, res + 1 + n, cmp);
    for (int i = k + 1; i <= n; i++)
        ans = std::max(ans, res[i] + 1);
    printf("%d", ans);
    return 0;
}