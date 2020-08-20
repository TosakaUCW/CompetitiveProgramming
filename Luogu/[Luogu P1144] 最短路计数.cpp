#include <memory.h>
#include <stdio.h>
#include <queue>
#include <algorithm>

const int N = 1e6 + 5;
const int M = 2e6 + 5;
const int P = 1e5 + 3;

int n, m;
int head[N], num_edge;
int ans[N], depth[N];
bool vis[N];

struct Node
{
    int next, to;
} edge[M];

void add_edge(int u, int v)
{
    edge[++num_edge].next = head[u];
    edge[num_edge].to = v;
    head[u] = num_edge;
}

void bfs(int s)
{
    std::queue<int> Q;
    Q.push(s), depth[s] = 1, vis[s] = true, ans[s] = 1;
    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (!vis[v])
                Q.push(v), depth[v] = depth[u] + 1, vis[v] = true;
            if (depth[v] == depth[u] + 1)
                (ans[v] += ans[u]) %= P;
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v), add_edge(v, u);
    }
    bfs(1);
    for (int i = 1; i <= n; i++)
        printf("%d\n", ans[i]);
    return 0;
}