#include <memory.h>
#include <stdio.h>
#include <algorithm>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 1e5;
const int M = 2e5;
const int INF = 1 << 30;

int n, m;
int num_edge, head[N + 5], dis[N + 5];
bool flag, inStack[N + 5];

struct Node
{
    int next, to, dis;
} edge[M + 5];

void add_edge(int u, int v, int dis)
{
    num_edge++;
    edge[num_edge].next = head[u];
    edge[num_edge].to = v;
    edge[num_edge].dis = dis;
    head[u] = num_edge;
}

void SPFA(int u)
{
    inStack[u] = true;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        int dist = edge[i].dis;
        if (dis[v] < dis[u] + dist)
        {
            dis[v] = dis[u] + dist;
            if (!inStack[v])
                SPFA(v);
        }
    }
    inStack[u] = false;
}

int main()
{
    scanf("%d%d", &n, &m);
    Rep(i, 1, m)
    {
        int u, v, dist;
        scanf("%d%d%d", &u, &v, &dist);
        add_edge(u - 1, v, dist);
    }
    Rep(i, 1, n)
    {
        if (i != n)
            add_edge(i, i - 1, -1);
        if (i != 0)
        {
            dis[i] = -INF;
            add_edge(i - 1, i, 0);
        }
    }
    SPFA(0);
    printf("%d", dis[n]);
    return 0;
}