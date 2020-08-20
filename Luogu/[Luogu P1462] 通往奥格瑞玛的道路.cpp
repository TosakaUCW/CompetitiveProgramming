#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

typedef long long ll;

const ll N = 1e6 + 5;
const ll M = 5e6 + 5;

ll n, m, HP;
ll head[N], num_edge;
ll val[N], dis[N];
bool vis[N];

struct Node
{
    ll next, to, dis;
} edge[M];
struct MyStruct
{
    ll cur, dis;
    bool friend operator<(MyStruct A, MyStruct B) { return A.dis > B.dis; }
};

std::priority_queue<MyStruct> Q;

void add_edge(ll u, ll v, ll dis)
{
    edge[++num_edge].next = head[u];
    head[u] = num_edge;
    edge[num_edge].to = v;
    edge[num_edge].dis = dis;
}

bool judge(ll x)
{
    if (val[1] > x or val[n] > x)
        return false;
    memset(vis, 0, sizeof vis);
    memset(dis, 127 / 3, sizeof dis);
    while (!Q.empty())
        Q.pop();
    Q.push(MyStruct{1, 0});
    dis[1] = 0;
    while (!Q.empty())
    {
        ll u = Q.top().cur;
        Q.pop();
        vis[u] = true;
        for (ll i = head[u]; i; i = edge[i].next)
        {
            ll v = edge[i].to;
            ll dist = edge[i].dis;
            if (vis[v] or val[v] > x)
                continue;
            if (dis[v] > dis[u] + dist)
                dis[v] = dis[u] + dist, Q.push(MyStruct{v, dis[v]});
        }
    }
    return dis[n] <= HP;
}

signed main()
{
    ll L = 0, R = 0, res = -1;
    scanf("%lld%lld%lld", &n, &m, &HP);
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &val[i]), R = std::max(R, val[i]);
    for (ll i = 1, u, v, dis; i <= m; i++)
        scanf("%lld%lld%lld", &u, &v, &dis), add_edge(u, v, dis), add_edge(v, u, dis);
    while (L <= R)
    {
        ll mid = (L + R) / 2;
        if (judge(mid))
            res = mid, R = mid - 1;
        else
            L = mid + 1;
    }
    if (res == -1)
        puts("AFK");
    else
        printf("%lld", res);
    return 0;
}