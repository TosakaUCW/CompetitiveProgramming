#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

const int N = 1e7 + 5;

int n, m, st;
long long ans, dis[N];
int head[N], num_edge;
bool vis[N];

struct Node
{
    int next, to, dis;
} edge[N];
struct node
{
    int cur;
    long long dis;
    bool friend operator<(node A, node B) {
        return A.dis > B.dis;
    };
};

std::priority_queue<node> Q;

void add_edge(int u, int v, int dis)
{
    edge[++num_edge] = Node{ head[u], v, dis };
    head[u] = num_edge;
}

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

void dijkstra(int s)
{
    Q.push(node{ s, 0 });
    dis[s] = 0;
    while (!Q.empty())
    {
        node X = Q.top();
        Q.pop();
        if (vis[X.cur])
            continue;
        vis[X.cur] = true;
        for (int i = head[X.cur]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (dis[X.cur] + edge[i].dis < dis[v])
            {
                dis[v] = dis[X.cur] + edge[i].dis;
                if (!vis[v])
                    Q.push(node{ v, dis[v] });
            }
        }
    }
}

int main()
{
    memset(dis, 0x3f, sizeof dis);
    n = read(), m = read(), st=read();
    for (int i = 1, u, v, dis; i <= m; i++)
        u = read(), v = read(), dis = read(),
        add_edge(u, v, dis), add_edge(v + n, u + n, dis);
    dijkstra(st);
    dijkstra(n + st);
    for (int i = 1; i <= n; i++)
        if (i != st)
            ans = std::max(ans, dis[i] + dis[i + n]);
    printf("%lld\n", ans);
    return 0;
}