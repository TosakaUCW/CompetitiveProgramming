#include <stdio.h>
#include <algorithm>

const int N = 2e5 + 5;
const int M = N << 1;

int n, q;
int k, a[N];
int head[N], num_edge;
int size[N], depth[N], fa[N], dfn[N];

struct Node
{
    int next, to;
} edge[M];

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

void dfs1(int u, int fa)
{
    size[u] = 1, depth[u] = depth[fa] + 1, dfn[u] = ++dfn[0], ::fa[u] = fa;
    for (int i = head[u], v; i; i = edge[i].next)
        if ((v = edge[i].to) != fa)
            dfs1(v, u), size[u] += size[v];
}

bool cmp(int a, int b) { return depth[a] < depth[b]; }

bool belong(int x, int y) { return dfn[x] <= dfn[y] and dfn[y] < dfn[x] + size[x]; }

int main()
{
    n = read(), q = read();
    for (int i = 1, u, v; i < n; i++)
        u = read(), v = read(), add_edge(u, v), add_edge(v, u);
    for (dfs1(1, 1); q--;)
    {
        bool flag = true;
        k = read();
        for (int i = 1; i <= k; i++)
            a[i] = fa[read()];
        std::sort(a + 1, a + 1 + k, cmp);
        for (int i = 1; i < k and flag; i++)
            if (!belong(a[i], a[i + 1]))
                flag = false;
        puts(flag ? "YES" : "NO");
    }
    return 0;
}