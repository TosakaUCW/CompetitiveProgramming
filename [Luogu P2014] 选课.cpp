#include <stdio.h>
#include <algorithm>

#define Rep(i, x, y) for (register int i = x; i <= y; i++)

const int N = 300 + 5;

int n, m, ans, num_edge;
int head[N], f[N][N];

struct Node
{
    int next, to;
} edge[N];

void add_edge(int u, int v)
{
    edge[++num_edge].next = head[u];
    edge[num_edge].to = v;
    head[u] = num_edge;
}

void DFS(int u)
{
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        DFS(v);
        for (int j = m; j; j--)
            for (int k = 0; k < j; k++)
                f[u][j] = std::max(f[u][j], f[v][k] + f[u][j - k - 1]);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    Rep(i, 1, n)
    {
        int u;
        scanf("%d%d", &u, &f[i][0]);
        add_edge(u, i);
    }
    DFS(0);
    printf("%d", f[0][m]);
    return 0;
}