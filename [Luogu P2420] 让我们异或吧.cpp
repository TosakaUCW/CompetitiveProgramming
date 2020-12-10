#include <stdio.h>

const int N = 1e5 + 5;

int n;
int head[N], num_edge;
int ans[N];

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
        ans[v] = ans[u] ^ dis;
        dfs(v, u);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int u, v, dis;
        scanf("%d%d%d", &u, &v, &dis);
        add_edge(u, v, dis), add_edge(v, u, dis);
    }
    dfs(1, 0);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        printf("%d\n", ans[u] ^ ans[v]);
    }
    return 0;
}