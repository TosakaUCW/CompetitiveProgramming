// luogu-judger-enable-o2
#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <queue>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 1e6;
const int M = 1e6;
const int INF = 1e9;

int n, m, s, t, ans;
int num_edge = -1;
int depth[N + 5], head[N + 5], cur[N + 5];

struct Node
{
    int next = -1, to, dis;
} edge[M + 5];

void add_edge(int u, int v, int dis)
{
    num_edge++;
    edge[num_edge].next = head[u];
    edge[num_edge].to = v;
    edge[num_edge].dis = dis;
    head[u] = num_edge;
}

int dfs(int u, int dis)
{
    if (u == t)
        return dis;
    for (int &i = cur[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if (edge[i].dis != 0 and depth[v] == depth[u] + 1)
        {
            int k = dfs(v, std::min(dis, edge[i].dis));
            if (k > 0)
            {
                edge[i].dis -= k;
                edge[i ^ 1].dis += k;
                return k;
            }
        }
    }
    return 0;
}

bool bfs()
{
    std::queue<int> q;
    while (!q.empty())
        q.pop();
    memset(depth, 0, sizeof(depth));
    depth[s] = 1;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (edge[i].dis > 0 and depth[v] == 0)
            {
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }
    }
    if (depth[t] != 0)
        return true;
    return false;
}

void Dinic()
{
    while (bfs())
    {
        Rep(i, 1, n)
            cur[i] = head[i];
        while (int k = dfs(s, INF))
            ans += k;
    }
}

int main()
{
    memset(head, -1, sizeof(head));
    scanf("%d%d%d%d", &n, &m, &s, &t);
    Rep(i, 1, m)
    {
        int u, v, dis;
        scanf("%d%d%d", &u, &v, &dis);
        add_edge(u, v, dis);
        add_edge(v, u, 0);
    }
    Dinic();
    printf("%d", ans);
    return 0;
}