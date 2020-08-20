#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e5 + 5;

int n, fa[N], rt1, rt2;
int val[N], head[N], num_edge;
double k, ans, f[N][2];

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

int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }

void dfs(int u, int fath)
{
    f[u][0] = 0, f[u][1] = val[u];
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fath)
            continue;
        dfs(v, u);
        f[u][0] += std::max(f[v][0], f[v][1]);
        f[u][1] += f[v][0];
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &val[i]), fa[i] = i;
    for (int i = 1, u, v; i <= n; i++)
    {
        scanf("%d%d", &u, &v), u++, v++;
        int fu = find(u), fv = find(v);
        if (fu != fv)
            fa[fu] = fv, add_edge(u, v), add_edge(v, u);
        else
            rt1 = u, rt2 = v;
    }
    scanf("%lf", &k);
    dfs(rt1, 0), ans = std::max(ans, f[rt1][0]);
    dfs(rt2, 0), ans = std::max(ans, f[rt2][0]);
    printf("%.1lf", ans * k);
    return 0;
}