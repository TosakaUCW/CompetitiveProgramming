#include <stdio.h>
#include <algorithm>
#include <memory.h>

typedef long long ll;

const ll N = 1e6 + 5;

ll n;
ll head[N], num_edge;
ll f[N], depth[N], size[N];
ll ans, res;

struct Node
{
    ll next, to;
} edge[N << 1];

void add_edge(ll u, ll v)
{
    edge[++num_edge] = Node{head[u], v};
    head[u] = num_edge;
}

ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

void dfs_1(ll u, ll fa)
{
    size[u] = 1;
    depth[u] = depth[fa] + 1;
    for (ll i = head[u]; i; i = edge[i].next)
    {
        ll v = edge[i].to;
        if (v != fa)
            dfs_1(v, u), size[u] += size[v];
    }
}

void dfs_2(ll u, ll fa)
{
    for (ll i = head[u]; i; i = edge[i].next)
    {
        ll v = edge[i].to;
        if (v != fa)
            f[v] = f[u] + n - 2 * size[v], dfs_2(v, u);
    }
}

signed main()
{
    n = read();
    for (ll i = 1, u, v; i < n; i++)
        u = read(), v = read(), add_edge(u, v), add_edge(v, u);
    dfs_1(1, 0);
    for (ll i = 1; i <= n; i++)
        f[1] += size[i];
    dfs_2(1, 0);
    for (ll i = 1; i <= n; i++)
        ans = std::max(ans, f[i]);
    printf("%lld", ans);
    return 0;
}