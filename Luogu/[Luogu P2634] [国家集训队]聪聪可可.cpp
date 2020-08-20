#include <stdio.h>
#include <algorithm>
#include <memory.h>

typedef long long ll;

const ll N = 1e5 + 5;

ll n, ans;
ll head[N], num_edge;
ll f[N][3], tmp[3];

struct Node
{
    ll next, to, dis;
} edge[N << 1];

void add_edge(ll u, ll v, ll dis) { edge[++num_edge] = Node{head[u], v, dis % 3}, head[u] = num_edge; }

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

void dfs(int u, int fa)
{
    f[u][0] = 1;
    for (int i = head[u]; i; i = edge[i].next)
    {
        int v = edge[i].to, dis = edge[i].dis;
        if (v == fa)
            continue;
        dfs(v, u);
        for (int j = 0; j < 3; ++j)
            ans += 2 * f[v][j] * f[u][(6 - dis - j) % 3];
        for (int j = 0; j < 3; ++j)
            f[u][(j + dis) % 3] += f[v][j];
    }
}

signed main()
{
    n = read();
    for (ll i = 1, u, v, dis; i < n; i++)
        u = read(), v = read(), dis = read(), add_edge(u, v, dis), add_edge(v, u, dis);
    dfs(1, 0), ans += n;
    printf("%lld/%lld", ans / std::__gcd(ans, n * n), n * n / std::__gcd(ans, n * n));
    return 0;
}