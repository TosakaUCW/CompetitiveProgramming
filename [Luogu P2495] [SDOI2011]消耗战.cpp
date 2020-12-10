#include <stdio.h>
#include <algorithm>
#include <memory.h>

typedef long long ll;

const int N = 3e5 + 5;
const int M = N << 1;
const ll INF = 1LL << 60;

int n, m;
int dfin[N], dfou[N], top[N], son[N], fa[N], depth[N], size[N];
long long f[N], min[N];
int head[N], num_edge;
int a[N], stack[N];
bool b[N];

struct Node
{
    int next, to, dis;
} edge[M];

void add_edge(int u, int v, int dis = 0) { edge[++num_edge] = Node{head[u], v, dis}, head[u] = num_edge; }

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
    ::fa[u] = fa, size[u] = 1, depth[u] = depth[fa] + 1;
    for (int i = head[u], v; i; i = edge[i].next)
        if ((v = edge[i].to) != fa)
            min[v] = std::min(min[u], (ll)edge[i].dis), dfs1(v, u), size[u] += size[v], son[u] = size[v] > size[son[u]] ? v : son[u];
}

void dfs2(int u)
{
    dfin[u] = ++dfin[0], top[u] = u == son[fa[u]] ? top[fa[u]] : u;
    if (son[u])
        dfs2(son[u]);
    for (int i = head[u], v; i; i = edge[i].next)
        if ((v = edge[i].to) != fa[u] and v != son[u])
            dfs2(v);
    dfou[u] = ++dfin[0];
}

int lca(int x, int y)
{
    for (; top[x] != top[y]; x = fa[top[x]])
        if (dfin[top[x]] < dfin[top[y]])
            std::swap(x, y);
    return dfin[x] < dfin[y] ? x : y;
}

bool cmp(int x, int y)
{
    int k1 = x > 0 ? dfin[x] : dfou[-x];
    int k2 = y > 0 ? dfin[y] : dfou[-y];
    return k1 < k2;
}

int main()
{
    n = read();
    for (int i = 1, u, v, dis; i < n; i++)
        u = read(), v = read(), dis = read(), add_edge(u, v, dis), add_edge(v, u, dis);
    min[1] = INF, dfs1(1, 0), dfs2(1);
    for (m = read(); m--;)
    {
        int k = read();
        for (int i = 1; i <= k; i++)
            a[i] = read(), b[a[i]] = true, f[a[i]] = min[a[i]];
        std::sort(a + 1, a + 1 + k, cmp);
        for (int i = 1; i < k; i++)
        {
            int LCA = lca(a[i], a[i + 1]);
            if (!b[LCA])
                a[++k] = LCA, b[LCA] = true;
        }
        for (int i = 1, tmp = k; i <= tmp; i++)
            a[++k] = -a[i];
        if (!b[1])
            a[++k] = 1, a[++k] = -1;
        std::sort(a + 1, a + 1 + k, cmp);
        for (int i = 1, top = 0; i <= k; i++)
            if (a[i] > 0)
                stack[++top] = a[i];
            else
            {
                int u = stack[top--];
                if (u != 1)
                {
                    int fa = stack[top];
                    f[fa] += std::min(f[u], min[u]);
                }
                else
                    printf("%lld\n", f[1]);
                f[u] = b[u] = 0;
            }
    }
    return 0;
}