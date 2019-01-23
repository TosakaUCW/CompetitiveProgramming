#include <stdio.h>

typedef long long LL;

const int N = 2e5 + 5;
const int M = 4e5 + 5;

int n, num_edge;
int depth[N], head[N], size[N];
LL ans, x;

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

void DFS(int u, int fa)
{
    size[u] = 1;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fa)
            continue;
        depth[v] = depth[u] + 1;
        DFS(v, u);
        size[u] += size[v];
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v), add_edge(v, u);
    }
    DFS(1, 0);
    for (int i = 1; i <= n; i++)
    {
        ans += (LL)size[i] * (n - size[i]);
        if (depth[i] & 1)
            x++;
    }
    ans += x * (n - x);
    printf("%lld", ans / 2);
    return 0;
}