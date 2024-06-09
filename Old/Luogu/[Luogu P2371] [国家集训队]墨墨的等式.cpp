#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

typedef long long ll;

const ll N = 5e5 + 5;
const ll M = 6e6 + 5;
const ll INF = (1LL << 63) - 1;

ll n, l, r, w;
ll a[N], dis[N];
ll head[N], num_edge;
bool inQ[N];

struct Node
{
    ll next, to, dis;
} edge[M];

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

void SPFA(ll s)
{
    memset(dis, 0x3f, sizeof dis);
    std::queue<ll> Q;
    dis[s] = 0, Q.push(s), inQ[s] = true;
    while (!Q.empty())
    {
        ll u = Q.front();
        Q.pop(), inQ[u] = false;
        for (ll i = head[u]; i; i = edge[i].next)
        {
            ll v = edge[i].to, dist = edge[i].dis;
            if (dis[v] > dis[u] + dist)
            {
                dis[v] = dis[u] + dist;
                if (!inQ[v])
                    Q.push(v), inQ[v] = true;
            }
        }
    }
}

ll query(ll x)
{
    ll res = 0;
    for (ll i = 0; i < w; i++)
        if (dis[i] <= x)
            res += (x - dis[i]) / w + 1;
    return res;
}

signed main()
{
    n = read(), l = read(), r = read();
    w = INF;
    for (ll i = 1; i <= n; i++)
        a[i] = read(), w = std::min(w, a[i]);
    for (ll i = 0; i < w; i++)
        for (ll j = 1; j <= n; j++)
            if (a[j] != w)
                add_edge(i, (i + a[j]) % w, a[j]);
    SPFA(0);
    printf("%lld", query(r) - query(l - 1));
    return 0;
}