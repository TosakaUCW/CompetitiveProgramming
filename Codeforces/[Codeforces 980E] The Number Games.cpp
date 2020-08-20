#include <stdio.h>
#include <algorithm>

const int N = 1e6 + 5;
const int M = 25;

int n, k;
int head[N], num_edge;
int depth[N], fa[N][M + 5];
bool used[N];

struct Node
{
    int next, to;
} edge[N << 1];

void add_edge(int u, int v)
{
    edge[++num_edge].next = head[u];
    head[u] = num_edge;
    edge[num_edge].to = v;
}

void dfs(int u, int fath)
{
    depth[u] = depth[fath] + 1, fa[u][0] = fath;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fath)
            continue;
        dfs(v, u);
    }
}

int get(int x)
{
    for (int i = M; i >= 0; i--)
        if (!used[fa[x][i]] and fa[x][i])
            x = fa[x][i];
    return x;
}

int main()
{
    scanf("%d%d", &n, &k), k = n - k;
    for (int i = 1, u, v; i < n; i++)
        scanf("%d%d", &u, &v), add_edge(u, v), add_edge(v, u);
    dfs(n, 0);
    for (int j = 1; j <= M; j++)
        for (int i = 1; i <= n; i++)
            fa[i][j] = fa[fa[i][j - 1]][j - 1];
    for (int i = n; i >= 1 and k; i--)
        if (!used[i])
        {
            int x = i, y = get(i);
            if (depth[x] - depth[y] + 1 <= k)
            {
                k -= depth[x] - depth[y] + 1;
                for (int cur = x; cur != y; cur = fa[cur][0])
                    used[cur] = true;
                used[y] = true;
            }
        }
    for (int i = 1; i <= n; i++)
        if (!used[i])
            printf("%d ", i);
    return 0;
}