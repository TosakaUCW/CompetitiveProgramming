#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

const int N = 1e5 + 5;

int n, m, q;
int head[N], num_edge;
int dis[N][2];

struct Node
{
    int next, to;
} edge[N << 1];

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

void add_edge(int u, int v)
{
    edge[++num_edge].next = head[u];
    head[u] = num_edge;
    edge[num_edge].to = v;
}
void bfs(int st)
{
    std::queue<int> Q;
    memset(dis, 0x3f, sizeof dis);
    dis[st][st % 2] = 0;
    Q.push(st);
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (dis[v][1] > dis[u][0] + 1)
                dis[v][1] = dis[u][0] + 1, Q.push(v);
            if (dis[v][0] > dis[u][1] + 1)
                dis[v][0] = dis[u][1] + 1, Q.push(v);
        }
    }
}

int main()
{
    n = read(), m = read(), q = read();
    for (int i = 1, u, v; i <= m; i++)
        u = read(), v = read(), add_edge(u, v), add_edge(v, u);
    bfs(1);
    for (int i = 1, a, x; i <= q; i++)
    {
        a = read(), x = read();
        if (dis[a][!(x % 2)] <= x)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}