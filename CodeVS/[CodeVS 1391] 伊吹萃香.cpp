#include <math.h>
#include <memory.h>
#include <stdio.h>
#include <algorithm>
#include <queue>

const int N = 5e3 + 5;
const int M = 3e4 + 5;

int n, m;
int color[N], weight[N], cost[N];
int num_edge, head[2 * N], dis[2 * N];
bool vis[2 * N];
std::queue<int> Q;

struct Node
{
    int next, to, dis;
} edge[4 * M];

void add_edge(int u, int v, int dis)
{
    edge[++num_edge].next = head[u];
    edge[num_edge].to = v;
    edge[num_edge].dis = dis;
    head[u] = num_edge;
}

void SPFA()
{
    int s;
    if (color[1] == 0)
        s = 2;
    else
        s = 1;
    memset(dis, 127, sizeof dis);
    Q.push(s);
    dis[s] = 0, vis[s] = true;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        vis[u] = false;
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            int dist = edge[i].dis;
            if (dis[v] > dis[u] + dist)
            {
                dis[v] = dis[u] + dist;
                if (!vis[v])
                    Q.push(v), vis[v] = true;
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &color[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &weight[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &cost[i]);
    for (int i = 1; i <= m; i++)
    {
        int u, v, dis;
        scanf("%d%d%d", &u, &v, &dis);
        if (color[u] == color[v])
        {
            add_edge(2 * u, 2 * v - 1, dis);
            add_edge(2 * u - 1, 2 * v, dis);
        }
        else
        {
            int delta = abs(weight[u] - weight[v]);
            add_edge(2 * u - 1, 2 * v - 1, dis + delta);
            add_edge(2 * u, 2 * v, std::max(0, dis - delta));
        }
    }
    for (int i = 1; i <= n; i++)
    {
        add_edge(2 * i, 2 * i - 1, 0);
        add_edge(2 * i - 1, i * 2, cost[i]);
    }
    SPFA();
    printf("%d", std::min(dis[2 * n], dis[2 * n - 1]));
    return 0;
}