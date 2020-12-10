#include <memory.h>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

typedef long long ll;

const ll N = 1e7 + 5;
const ll P = 998244353;

ll n, ans;
ll head[N], num_edge;
ll tot;
bool vis[N], yes[N];

struct Node
{
    ll next, to, dis;
} edge[N << 1];

struct node
{
    ll x, y;
} a[N];

ll pow(ll x, ll k)
{
    ll ans = 1;
    x %= P;
    while (k)
    {
        if (k & 1)
            (ans *= x) %= P;
        (x *= x) %= P;
        k >>= 1;
    }
    return ans % P;
}

void add_edge(ll u, ll v, ll dis)
{
    edge[++num_edge].next = head[u];
    head[u] = num_edge;
    edge[num_edge].to = v;
    edge[num_edge].dis = dis;
}

node dfs(ll cur, bool flag)
{
    yes[cur] = flag, vis[cur] = true;
    node ans, t;
    ans.x = yes[cur];
    ans.y = !yes[cur];
    for (ll i = head[cur]; i; i = edge[i].next)
    {
        ll v = edge[i].to;
        ll dis = edge[i].dis;
        if (vis[v])
        {
            if (yes[cur] ^ dis ^ yes[v])
                continue;
            else
            {
                puts("No answer");
                exit(0);
            }
        }
        else
        {
            t = dfs(v, !(flag ^ dis));
            ans.x += t.x;
            ans.y += t.y;
        }
    }
    return ans;
}

signed main()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; i++)
    {
        ll k, opt;
        scanf("%lld%lld", &k, &opt);
        add_edge(i, k, opt);
        add_edge(k, i, opt);
    }
    for (ll i = 1; i <= n; i++)
        if (!vis[i])
            a[++tot] = dfs(i, 1);
    printf("%lld\n", pow(2, tot) % P);
    ans = 0;
    for (ll i = 1; i <= tot; i++)
        ans += std::max(a[i].x, a[i].y);
    printf("%lld\n", ans % P);
    ans = 0;
    for (ll i = 1; i <= tot; i++)
        ans += std::min(a[i].x, a[i].y);
    printf("%lld\n", ans % P);
    return 0;
}