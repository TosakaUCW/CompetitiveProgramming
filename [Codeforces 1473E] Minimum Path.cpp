#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 5e6 + 5;
const int M = 5e6 + 5;

int n, m;
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

void adde(int u, int v, int dis)
{
    add_edge(u, v + 3 * n, dis);
    add_edge(u, v + n, 0), add_edge(u + 2 * n, v + 3 * n, 0);
    add_edge(u, v + 2 * n, 2 * dis), add_edge(u + n, v + 3 * n, 2 * dis);
    for (int i = 0; i < 4; i++)
        add_edge(u + i * n, v + i * n, dis);
}

void dijktsra(int s)
{
    memset(dis, 0x3f, sizeof dis);
    dis[s] = 0, Q.push(node{s, 0});
    for (int u; !Q.empty();)
    {
        u = Q.top().cur, Q.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (int i = head[u], v; v = edge[i].to; i = edge[i].next)
            if (dis[v] > dis[u] + edge[i].dis)
                dis[v] = dis[u] + edge[i].dis, Q.push(node{v, dis[v]});
    }
    for (int i = 2; i <= n; i++)
        printf("%lld ", dis[i + 3 * n]);
}

signed main()
{
    n = read(), m = read();
    for (int i = 1, u, v, dis; i <= m; i++)
        u = read(), v = read(), dis = read(),
        adde(u, v, dis), adde(v, u, dis);
    return dijktsra(1), 0;
}