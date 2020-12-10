#include <stdio.h>
#include <algorithm>

const int N = 16000 + 5;
const int INF = 1 << 30;

int n, num_edge, ans;
int v[N], f[N], head[N];

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
    f[u] = v[u];
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v != fa)
        {
            dfs(v, u);
            f[u] += std::max(0, f[v]);
        }
    }
    ans = std::max(ans, f[u]);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &v[i]);
    for (int i = 2; i <= n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    dfs(1, 0);
    printf("%d", ans);
    return 0;
}