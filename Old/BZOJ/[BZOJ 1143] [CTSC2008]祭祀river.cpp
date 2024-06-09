#include <memory.h>
#include <stdio.h>

const int N = 1e3 + 5;
const int M = 1e6 + 5;

int n, m, ans;
int g[N][N], num_edge, head[N];
;
int match[N];
bool used[N];

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

void Floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                g[i][j] |= (g[i][k] & g[k][j]);
}

void build()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (g[i][j])
                add_edge(i, n + j), add_edge(n + j, i);
}

bool dfs(int u)
{
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (!used[v])
        {
            used[v] = true;
            if (!match[v] or dfs(match[v]))
            {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u][v] = true;
    }
    Floyd();
    build();
    for (int i = 1; i <= n; i++)
    {
        memset(used, false, sizeof used);
        if (dfs(i))
            ans++;
    }
    printf("%d", n - ans);
    return 0;
}