#include <stdio.h>

typedef long long LL;

const int N = 5e4 + 5;
const int M = 2e5 + 5;

int n, m, num_edge, head[N];
LL dis[N];
bool vis[N];

struct Edge
{
    int next, to;
    LL dis;
} edge[M];

void add_edge(int u, int v, LL dist)
{
    edge[++num_edge].next = head[u];
    edge[num_edge].to = v;
    edge[num_edge].dis = dist;
    head[u] = num_edge;
}

class Linear_Base
{
  private:
    static const int LogN = 63;
    LL a[LogN + 5];

  public:
    void insert(LL x)
    {
        for (int i = LogN; i >= 0; i--)
            if (x & (1LL << i))
                if (!a[i])
                {
                    a[i] = x;
                    return;
                }
                else
                    x ^= a[i];
    }
    LL query_max(LL x)
    {
        LL res = x;
        for (int i = LogN; i >= 0; i--)
            if ((res ^ a[i]) > res)
                res ^= a[i];
        return res;
    }
} LB;

void DFS(int u, LL res)
{
    dis[u] = res;
    vis[u] = true;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        LL dist = edge[i].dis;
        if (!vis[v])
            DFS(v, res ^ dist);
        else
            LB.insert(dis[v] ^ res ^ dist);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        LL dist;
        scanf("%d%d%lld", &u, &v, &dist);
        add_edge(u, v, dist);
        add_edge(v, u, dist);
    }
    DFS(1, 0);
    printf("%lld", LB.query_max(dis[n]));
    return 0;
}