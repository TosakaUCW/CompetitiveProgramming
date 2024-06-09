#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 1e6 + 5;
const int M = N << 1;
const int INF = 2147483647;

int n, m;
int mx = INF, my = 1, ans1, ans2;
int val[N], f[N], g[N];
int head[N], num_edge;

struct Node
{
    int next, to;
} edge[M];

void add_edge(int u, int v) { edge[++num_edge] = Node{head[u], v}, head[u] = num_edge; }

void dfs(int u, int fa)
{
    if (val[u] == 1)
        f[u] = 1;
    else if (val[u] == 2)
        g[u] = 1;
    for (int i = head[u], v; v = edge[i].to; i = edge[i].next)
        if (v != fa)
        {
            dfs(v, u);
            ans1 = std::max(ans1, f[u] + f[v]);
            ans2 = std::max(ans2, std::max(g[v] ? g[v] + f[u] : -INF, g[u] ? f[v] + g[u] : -INF));
            if (val[u] == 1)
            {
                f[u] = std::max(f[u], f[v] + 1);
                if (g[v])
                    g[u] = std::max(g[u], g[v] + 1);
            }
            else if (val[u] == 2)
                g[u] = std::max(g[u], f[v] + 1);
        }
    ans1 = std::max(ans1, f[u]),
    ans2 = std::max(ans2, g[u]);
}

void update(int x, int y)
{
    if (x * my < y * mx)
        mx = x, my = y;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif // !ONLINE_JUDGE
    n = read();
    for (int i = 1, u, v; i < n; i++)
        u = read(), v = read(), add_edge(u, v), add_edge(v, u);
    for (int i = 1; i <= n; i++)
        val[i] = read(), mx = std::min(mx, val[i]);
    dfs(1, 0);
    if (ans1)
        update(1, ans1);
    if (ans2)
        update(2, ans2);
    int k = std::__gcd(mx, my);
    return printf("%lld/%lld", mx / k, my / k), 0;
}