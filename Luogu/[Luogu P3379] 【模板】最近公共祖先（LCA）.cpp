#include <math.h>
#include <stdio.h>
#include <algorithm>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 5e5;
const int LOG2N = 23;

int n, m, s;
int num_edge, head[N + 5], depth[N + 5];

struct Edge
{
    int next, to;
} edge[2 * N + 5];

struct LeastCommonAncestor
{
    int fa[N + 5][LOG2N], log2[N + 5];

    void prepare()
    {
        Rep(i, 1, n)
            log2[i] = log2[i - 1] + (1 << log2[i - 1] == i);
        dfs(s, 0);
    }

    void dfs(int u, int father)
    {
        depth[u] = depth[father] + 1;
        fa[u][0] = father;
        for (int i = 1; (1 << i) <= depth[u]; i++)
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        for (int i = head[u]; i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (v != father)
                dfs(v, u);
        }
    }

    int query(int x, int y)
    {
        if (depth[x] < depth[y])
            std::swap(x, y);
        while (depth[x] > depth[y])
        {
            int k = depth[x] - depth[y];
            x = fa[x][log2[k] - 1];
        }
        if (x == y)
            return x;
        for (int k = log2[depth[x]] - 1; k >= 0; k--)
            if (fa[x][k] != fa[y][k])
            {
                x = fa[x][k];
                y = fa[y][k];
            }
        return fa[x][0];
    }
} lca;

void add_edge(int from, int to)
{
    ++num_edge;
    edge[num_edge].next = head[from];
    edge[num_edge].to = to;
    head[from] = num_edge;
}

int main()
{
    scanf("%d%d%d", &n, &m, &s);
    Rep(i, 2, n)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    lca.prepare();
    Rep(i, 1, m)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        int ans = lca.query(x, y);
        printf("%d\n", ans);
    }
    return 0;
}