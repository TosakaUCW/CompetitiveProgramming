#include <stdio.h>
#include <algorithm>
#include <memory.h>

typedef long long ll;

const ll N = 1e5 + 5;
const ll INF = 1 << 30;

ll n, ans = INF;
ll head[N], num_edge;
ll c[N], depth[N], size[N];
ll f[N];

struct Node
{
    ll next, to, dis;
} edge[N << 1];

void add_edge(ll u, ll v, ll dis) { edge[++num_edge] = Node{head[u], v, dis}, head[u] = num_edge; }

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

void dfs1(ll u, ll fa)
{
    size[u] = c[u];
    for (ll i = head[u]; i; i = edge[i].next)
    {
        ll v = edge[i].to;
        if (v == fa)
            continue;
        dfs1(v, u);
        size[u] += size[v];
        f[u] += size[v] * edge[i].dis + f[v];
    }
}

void dfs2(ll u, ll fa)
{
    ans = std::min(ans, f[u]);
    for (ll i = head[u]; i; i = edge[i].next)
    {
        ll v = edge[i].to;
        if (v == fa)
            continue;
        f[v] = f[u] + (size[1] - size[v]) * edge[i].dis - size[v] * edge[i].dis;
        dfs2(v, u);
    }
}

signed main()
{
    n = read();
    for (ll i = 1; i <= n; i++)
        c[i] = read();
    for (ll i = 1, u, v, dis; i < n; i++)
        u = read(), v = read(), dis = read(), add_edge(u, v, dis), add_edge(v, u, dis);
    dfs1(1, 0);
    ans = f[1];
    memset(f, 0, sizeof f);
    f[1] = ans;
    dfs2(1, 0);
    printf("%lld", ans);
    return 0;
}