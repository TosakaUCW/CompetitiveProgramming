#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

const int N = 1e6 + 5;
const int M = 1e6 + 5;

int n, m, s, t;
int head[N], num_edge;
int dis[N];
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
    Q.push(node{s, 0});
    dis[s] = 0;
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
    scanf("%d%d%d%d", &n, &m, &s, &t);
    for (int i = 1, u, v, dis; i <= m; i++)
        scanf("%d%d%d", &u, &v, &dis), add_edge(u, v, dis), add_edge(v, u, dis);
    dijkstra(s);
    printf("%d", dis[t]);
    return 0;
}