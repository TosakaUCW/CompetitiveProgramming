#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

const int N = 1e5 + 5;
const int M = 2e5 + 5;
const int INF = 2147483647;

int n, m, s;
int head[N], num_edge;
int dis[N];
bool vis[N];

struct Node
{
    int next, to, dis;
} edge[M];
struct node
{
    int cur, dis;
    bool friend operator<(node a, node b) { return a.dis > b.dis; }
};

std::priority_queue<node> Q;

void add_edge(int u, int v, int dis) { edge[++num_edge] = Node{head[u], v, dis}, head[u] = num_edge; }

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

void dijkstra()
{
    for (int i = 1; i <= n; i++)
        dis[i] = INF;
    dis[s] = 0, Q.push(node{s, 0});
    while (!Q.empty())
    {
        int u = Q.top().cur, w = Q.top().dis;
        Q.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (dis[v] > dis[u] + edge[i].dis)
                dis[v] = dis[u] + edge[i].dis, Q.push(node{v, dis[v]});
        }
    }
}

int main()
{
    n = read(), m = read(), s = read();
    for (int i = 1, u, v, dis; i <= m; i++)
        u = read(), v = read(), dis = read(), add_edge(u, v, dis);
    dijkstra();
    for (int i = 1; i <= n; i++)
        printf("%d ", dis[i]);
    return 0;
}