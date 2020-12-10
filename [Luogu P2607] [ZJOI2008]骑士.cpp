#include <stdio.h>
#include <algorithm>
#include <memory.h>

typedef long long ll;

const ll N = 1e6 + 5;

ll n, root;
ll val[N], head[N], num_edge;
ll ans, f[N][2], fa[N];
bool vis[N];

struct Node
{
    ll next, to;
} edge[N << 1];

void add_edge(ll u, ll v)
{
    edge[++num_edge].next = head[u];
    head[u] = num_edge;
    edge[num_edge].to = v;
}

void dfs(ll u)
{
    vis[u] = true;
    f[u][0] = 0, f[u][1] = val[u];
    for (ll i = head[u]; i; i = edge[i].next)
    {
        ll v = edge[i].to;
        if (v == root)
            continue;
        dfs(v);
        f[u][0] += std::max(f[v][0], f[v][1]);
        f[u][1] += f[v][0];
    }
}

void find_circle(ll u)
{
    ll res = 0;
    root = u;
    vis[root] = true;
    while (!vis[fa[root]])
        root = fa[root], vis[root] = true;
    dfs(root), res = f[root][0];
    root = fa[root];
    dfs(root), res = std::max(res, f[root][0]);
    ans += res;
}

signed main()
{
    scanf("%lld", &n);
    for (ll i = 1, v; i <= n; i++)
        scanf("%lld%lld", &val[i], &v), add_edge(v, i), fa[i] = v;
    for (ll i = 1; i <= n; i++)
        if (!vis[i])
            find_circle(i);
    printf("%lld", ans);
    return 0;
}