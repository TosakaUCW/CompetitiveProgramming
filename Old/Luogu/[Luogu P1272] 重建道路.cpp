#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 150 + 5;

int n, p;
int head[N], num_edge;
int son[N], f[N][N];
bool have_ind[N];

struct Node
{
    int next, to;
} edge[N];

void add_edge(int u, int v) { edge[++num_edge] = Node{head[u], v}, head[u] = num_edge; }

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

int dfs(int u)
{
    int sum = 1;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to;
        sum += dfs(v);
        for (int j = sum; j; j--)
            for (int k = 1; k < j; k++)
                f[u][j] = std::min(f[u][j], f[u][j - k] + f[v][k] - 1);
    }
    return sum;
}

int main()
{
    memset(f, 0x7f, sizeof f);
    n = read(), p = read();
    for (int i = 1, u, v; i < n; i++)
        u = read(), v = read(), son[u]++, have_ind[v] = true, add_edge(u, v);
    int root;
    for (int i = 1; i <= n; i++)
    {
        if (!have_ind[i])
            root = i;
        f[i][1] = son[i];
    }
    dfs(root);
    int ans = f[root][p];
    for (int i = 1; i <= n; i++)
        if (f[i][p] < ans)
            ans = f[i][p] + 1;
    printf("%d", ans);
    return 0;
}