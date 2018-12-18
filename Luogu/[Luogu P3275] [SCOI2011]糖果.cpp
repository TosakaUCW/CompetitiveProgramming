#include <memory.h>
#include <stdio.h>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 1e5;
const int M = 3e5;
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

bool SPFA(int u)
{
    inStack[u] = true;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        int dist = edge[i].dis;
        if (dis[v] < dis[u] + dist)
        {
            dis[v] = dis[u] + dist;
            if (inStack[v])
                return false;
            if (!SPFA(v))
                return false;
        }
    }
    inStack[u] = false;
    return true;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = n; i >= 1; i--)
    {
        dis[i] = -INF;
        add_edge(0, i, 1);
    }
    Rep(i, 1, m)
    {
        int opt, u, v;
        scanf("%d%d%d", &opt, &u, &v);
        switch (opt)
        {
        case 1:
            add_edge(u, v, 0);
            add_edge(v, u, 0);
            break;
        case 2:
            add_edge(u, v, 1);
            break;
        case 3:
            add_edge(v, u, 0);
            break;
        case 4:
            add_edge(v, u, 1);
            break;
        case 5:
            add_edge(u, v, 0);
            break;
        }
        if (opt % 2 == 0 and u == v)
        {
            printf("-1");
            return 0;
        }
    }
    if (!SPFA(0))
        printf("-1");
    else
    {
        long long ans = 0;
        Rep(i, 1, n)
            ans += dis[i];
        printf("%lld", ans);
    }
    return 0;
}