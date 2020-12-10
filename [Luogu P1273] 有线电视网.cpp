#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 3e3 + 5;
const int M = 1e5 + 5;

int n, m;
int head[N], num_edge;
int size[N], f[N][N];

struct Node
{
    int next, to, dis;
} edge[M];

void add_edge(int u, int v, int dis) { edge[++num_edge] = Node{head[u], v, dis}, head[u] = num_edge; }

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

int dfs(int u, int fa)
{
    if (u >= n - m + 1 and u <= n)
        return size[u] = 1;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to, dis = edge[i].dis;
        size[u] += dfs(v, u);
        for (int j = size[u]; ~j; j--)
            for (int k = 0; k <= size[v]; k++)
                f[u][j] = std::max(f[u][j], f[u][j - k] + f[v][k] - dis);
    }
    return size[u];
}

int main()
{
    memset(f, 0xcf, sizeof f);
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        f[i][0] = 0;
    for (int i = 1; i <= n - m; i++)
        for (int j = 1, k = read(), v, dis; j <= k; j++)
            v = read(), dis = read(), add_edge(i, v, dis);
    for (int i = n - m + 1; i <= n; i++)
        f[i][1] = read();
    dfs(1, 0);
    for (int i = m; ~i; i--)
        if (f[1][i] >= 0)
        {
            printf("%d", i);
            break;
        }
    return 0;
}