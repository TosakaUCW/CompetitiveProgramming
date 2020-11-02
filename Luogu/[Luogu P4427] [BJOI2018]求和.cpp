#include <stdio.h>
#include <algorithm>

typedef long long ll;

const ll N = 3e5 + 5;
const ll M = N << 1;
const ll K = 50 + 5;
const ll P = 998244353;

ll n;
ll head[N], num_edge;
ll sum[N][K];
ll fa[N], son[N], size[N], depth[N], top[N], dfn[N], idx[N];

struct Node
{
    ll next, to;
} edge[M];

void add_edge(ll u, ll v) { edge[++num_edge] = Node{head[u], v}, head[u] = num_edge; }

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

ll pow(ll x, ll k)
{
    ll res = 1;
    for (x %= P; k; (x *= x) %= P, k >>= 1)
        if (k & 1)
            (res *= x) %= P;
    return (res + P) % P;
}

void dfs1(ll u, ll fa)
{
    ::fa[u] = fa, size[u] = 1, depth[u] = depth[fa] + 1;
    for (ll i = 0; i <= 50; i++)
        (sum[u][i] = sum[fa][i] + pow(depth[u], i)) %= P;
    for (ll i = head[u], v; i; i = edge[i].next)
        if ((v = edge[i].to) != fa)
            dfs1(v, u),
                size[u] += size[v], son[u] = size[v] > size[son[u]] ? v : son[u];
}

void dfs2(ll u)
{
    dfn[u] = ++dfn[0], idx[dfn[u]] = u, top[u] = u == son[fa[u]] ? top[fa[u]] : u;
    if (!son[u])
        return;
    dfs2(son[u]);
    for (ll i = head[u], v; i; i = edge[i].next)
        if ((v = edge[i].to) != fa[u] and v != son[u])
            dfs2(v);
}

ll lca(ll x, ll y)
{
    for (; top[x] != top[y]; x = fa[top[x]])
        if (depth[top[x]] < depth[top[y]])
            std::swap(x, y);
    return depth[x] < depth[y] ? x : y;
}

signed main()
{
    n = read();
    for (ll i = 1, u, v; i < n; i++)
        u = read(), v = read(), add_edge(u, v), add_edge(v, u);
    depth[0] = -1, dfs1(1, 0), dfs2(1);
    for (int m = read(), x, y, k, z; m--;)
    {
        x = read(), y = read(), k = read(), z = lca(x, y);
        // ll ans = (sum[x][k] + sum[y][k]) % P - sum[z][k] - sum[fa[z]][k];
        ll ans = (sum[x][k] + sum[y][k]) % P;
        ans -= (sum[z][k] + sum[fa[z]][k]) % P;
        printf("%lld\n", (ans + P) % P);
    }
    return 0;
}