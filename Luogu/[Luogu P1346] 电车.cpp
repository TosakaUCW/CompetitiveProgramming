#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

const int N = 1e5 + 5;

int n, s, t;
int dis[N], head[N], num_edge;
bool vis[N];

struct Node
{
    int next, to, dis;
} edge[N];

struct node
{
    int cur, dis;
    bool friend operator<(node a, node b) { return a.dis > b.dis; }
};

std::priority_queue<node> Q;

void add_edge(int u, int v, int dis)
{
    edge[++num_edge].next = head[u];
    head[u] = num_edge;
    edge[num_edge].to = v;
    edge[num_edge].dis = dis;
}

void dijkstra(int s)
{
    memset(dis, 127, sizeof dis);
    dis[s] = 0;
    Q.push(node{s, dis[s]});
    while (!Q.empty())
    {
        int u = Q.top().cur;
        Q.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            int dist = edge[i].dis;
            if (dis[u] + dist < dis[v])
            {
                dis[v] = dis[u] + dist;
                if (!vis[v])
                    Q.push(node{v, dis[v]});
            }
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &s, &t);
    for (int i = 1, x, y; i <= n; i++)
    {
        scanf("%d", &x);
        for (int j = 1; j <= x; j++)
            scanf("%d", &y), add_edge(i, y, j == 1 ? 0 : 1);
    }
    dijkstra(s);
    printf("%d", dis[t] == dis[n + 1] ? -1 : dis[t]);
    return 0;
}