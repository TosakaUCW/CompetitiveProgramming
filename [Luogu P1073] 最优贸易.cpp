#include <stdio.h>
#include <algorithm>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 1e5;
const int M = 1e7;
const int INF = 1 << 30;

int n, m, num_edge;
int v[N + 5], head[N + 5];
int min[N + 5], f[N + 5];

struct Node
{
    int next, to;
} edge[M + 5];

void add_edge(int u, int v)
{
    ++num_edge;
    edge[num_edge].next = head[u];
    edge[num_edge].to = v;
    head[u] = num_edge;
}

void DFS(int u, int cost, int fa)
{
    bool flag = true;
    cost = std::min(cost, v[u]);
    if (min[u] > cost)
    {
        min[u] = cost;
        flag = false;
    }
    int max = std::max(f[fa], v[u] - cost);
    if (f[u] < max)
    {
        f[u] = max;
        flag = false;
    }
    if (flag)
        return;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        DFS(v, cost, u);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    Rep(i, 1, n)
    {
        scanf("%d", &v[i]);
        min[i] = INF;
    }
    Rep(i, 1, m)
    {
        int u, v, opt;
        scanf("%d%d%d", &u, &v, &opt);
        add_edge(u, v);
        if (opt == 2)
            add_edge(v, u);
    }
    DFS(1, INF, 0);
    printf("%d", f[n]);
    return 0;
}