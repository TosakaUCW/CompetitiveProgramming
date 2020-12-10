#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>

const int N = 2e5 + 5;
const int M = N << 1;
const int K = 1e5 + 5;

int n, m, k, rt;
int head[N], num_edge;
int size[N], depth[N], fa[N], idx[N], dfn[N], top[N], son[N];
int bel[N];

int maxdep_idx[N], maxdep_val[N];

struct Node
{
    int next, to;
} edge[M];

std::vector<int> col[K];

void add_edge(int u, int v) { return (u and v ? (edge[++num_edge] = Node{head[u], v}, head[u] = num_edge) : (rt = u | v)), void(); }

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

void dfs1(int u, int fa)
{
    size[u] = 1, depth[u] = depth[fa] + 1, ::fa[u] = fa;
    for (int i = head[u], v; i; i = edge[i].next)
        if ((v = edge[i].to) != fa)
            dfs1(v, u), size[u] += size[v], son[u] = size[v] > size[son[u]] ? v : son[u];
}

void dfs2(int u)
{
    dfn[u] = ++dfn[0], idx[dfn[u]] = u, top[u] = u == son[fa[u]] ? top[fa[u]] : u;
    if (son[u])
        dfs2(son[u]);
    for (int i = head[u], v; i; i = edge[i].next)
        if ((v = edge[i].to) != fa[u] and v != son[u])
            dfs2(v);
}

int LCA(int x, int y)
{
    for (; top[x] != top[y]; x = fa[top[x]])
        if (depth[top[x]] < depth[top[y]])
            std::swap(x, y);
    return depth[x] < depth[y] ? x : y;
}

int main()
{
    n = read(), k = read();
    for (int u = 1, v; u <= n; u++)
        bel[u] = read(), v = read(), add_edge(u, v), add_edge(v, u), col[bel[u]].push_back(u);
    dfs1(rt, 0), dfs2(rt);
    for (int i = 1; i <= k; i++)
        for (int j = 0, x; j < col[i].size(); j++)
            if (depth[x = col[i][j]] > maxdep_val[i])
                maxdep_idx[i] = x, maxdep_val[i] = depth[x];
    for (int i = 1, ans = 0; i <= k; printf("%d\n", ans), ans = 0, i++)
        for (int j = 0; j < col[i].size(); j++)
            ans = std::max(ans, depth[maxdep_idx[i]] + depth[col[i][j]] - 2 * depth[LCA(maxdep_idx[i], col[i][j])]);
    return 0;
}