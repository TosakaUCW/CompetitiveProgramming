#include <stdio.h>
#include <memory.h>
#include <algorithm>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 1e3;
const int M = 1e3;
int n, m, a[N + 5], rank[N + 5], ans;
int h, t, queue[10 * M + 5];
int num_edge, head[N + 5], ind[N + 5];
bool vis[N + 5], used[N + 5][N + 5];

struct Node
{
    int next, to;
} edge[1000 * M + 5];

inline void add_edge(int from, int to)
{
    num_edge++;
    edge[num_edge].next = head[from];
    edge[num_edge].to = to;
    head[from] = num_edge;
    used[from][to] = true;
    ind[to]++;
}

inline void push(int x)
{
    queue[++t] = x;
}

void topo_sort()
{
    h = 1, t = 0;
    Rep(i, 1, n) if (!ind[i])
    {
        push(i);
        rank[i] = 1;
    }
    while (h <= t)
    {
        int u = queue[h];
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            ind[v]--;
            rank[v] = rank[u] + 1;
            ans = std::max(ans, rank[v]);
            if (!ind[v])
                push(v);
        }
        h++;
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    Rep(i, 1, m)
    {
        memset(vis, false, sizeof(vis));
        int s;
        scanf("%d", &s);
        Rep(j, 1, s)
        {
            scanf("%d", &a[j]);
            vis[a[j]] = true;
        }
        Rep(j, a[1], a[s])
        {
            if (vis[j])
                continue;
            Rep(k, 1, s) if (!used[a[k]][j])
                add_edge(a[k], j);
        }
    }
    topo_sort();
    printf("%d", ans);
    return 0;
}
