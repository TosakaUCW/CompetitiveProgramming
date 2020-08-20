#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

typedef long long ll;

const ll N = 1e7 + 5;
const ll M = 1e7 + 5;
const ll INF = 1e9;

ll n, m;
ll head[N], num_edge;

ll h[N];
ll inQcnt[N];
bool inQ[N];

ll dis[N];
bool vis[N];

struct Node
{
    ll next, to, dis;
} edge[M];
struct node
{
    ll cur;
    ll dis;
    bool friend operator<(node a, node b) { return a.dis > b.dis; }
};

void add_edge(ll u, ll v, ll dis)
{
    edge[++num_edge].next = head[u];
    head[u] = num_edge;
    edge[num_edge].to = v;
    edge[num_edge].dis = dis;
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

bool SPFA(ll st)
{
    for (ll i = 1; i <= n; i++)
        h[i] = INF;
    std::queue<ll> Q;
    while (!Q.empty())
        Q.pop();
    Q.push(st);
    h[st] = 0;
    inQ[st] = true;
    while (!Q.empty())
    {
        ll u = Q.front();
        Q.pop();
        inQ[u] = false;
        for (ll i = head[u]; i; i = edge[i].next)
        {
            ll v = edge[i].to;
            if (h[v] > h[u] + edge[i].dis)
            {
                h[v] = h[u] + edge[i].dis;
                if (!inQ[v])
                    Q.push(v), inQ[v] = true, inQcnt[v]++;
                if (inQcnt[v] > n)
                    return false;
            }
        }
    }
    return true;
}

void dijkstra(ll st)
{
    for (ll i = 1; i <= n; i++)
        dis[i] = INF, vis[i] = false;
    std::priority_queue<node> Q;
    while (!Q.empty())
        Q.pop();
    Q.push(node{st, 0});
    dis[st] = 0;
    while (!Q.empty())
    {
        ll u = Q.top().cur;
        Q.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (ll i = head[u]; i; i = edge[i].next)
        {
            ll v = edge[i].to;
            if (dis[v] > dis[u] + edge[i].dis)
            {
                dis[v] = dis[u] + edge[i].dis;
                if (!vis[v])
                    Q.push(node{v, dis[v]});
            }
        }
    }
    ll ans = 0;
    for (ll j = 1; j <= n; j++)
        if (dis[j] == INF)
            ans += j * INF;
        else
            ans += j * (dis[j] + h[j] - h[st]);
    printf("%lld\n", ans);
}

signed main()
{
    n = read(), m = read();
    for (ll i = 1, u, v, dis; i <= m; i++)
        u = read(), v = read(), dis = read(), add_edge(u, v, dis);
    for (ll i = 1; i <= n; i++)
        add_edge(0, i, 0);
    if (!SPFA(0))
    {
        puts("-1");
        return 0;
    }
    for (ll u = 1; u <= n; u++)
        for (ll i = head[u]; i; i = edge[i].next)
        {
            ll v = edge[i].to;
            edge[i].dis += h[u] - h[v];
        }
    for (ll i = 1; i <= n; i++)
        dijkstra(i);
    return 0;
}