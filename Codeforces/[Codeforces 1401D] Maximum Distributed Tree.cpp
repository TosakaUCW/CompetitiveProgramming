#include <stdio.h>
#include <algorithm>
#include <memory.h>

typedef long long ll;

const ll N = 1e6 + 5;
const ll M = 2e6 + 5;
const ll P = 1e9 + 7;

ll n, m, ans;
ll p[N], size[N], tot[N];
ll head[N], num_edge;

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

void dfs(ll u, ll fa)
{
    size[u] = 1;
    for (ll i = head[u], v; i; i = edge[i].next)
        if ((v = edge[i].to) != fa)
            dfs(v, u), size[u] += size[v];
    tot[u] = size[u] * (n - size[u]);
}

signed main()
{
    for (ll T = read(); T--; num_edge = ans = 0, memset(head, 0, sizeof head))
    {
        n = read();
        for (ll i = 1, u, v; i < n; i++)
            u = read(), v = read(), add_edge(u, v), add_edge(v, u);
        m = read();
        for (ll i = 1; i <= m; i++)
            p[i] = read();
        dfs(1, 0);
        for (ll i = m + 1; i < n; i++)
            p[i] = 1;
        std::sort(p + 1, p + 1 + std::max(n - 1, m));
        for (ll i = n; i <= m; i++)
            p[n - 1] = p[n - 1] * p[i] % P;
        std::sort(tot + 2, tot + 1 + n);
        for (ll i = n - 1; i >= 1; i--)
            ans = (ans + p[i] % P * tot[i + 1] % P) % P;
        printf("%lld\n", (ans + P) % P);
    }
    return 0;
}