#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string.h>
#include <iostream>
#define int long long
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 5e3 + 5;
const int M = 5e4 + 5;

int n, m, s, t, max_flow, min_cost;
struct Node { int ne, to, flow, cost; } e[M << 1];
int hd[N], node = 1, dis[N], flow[N], pre[N];
bool vis[N];
#define pb emplace_back

bool SPFA()
{
    std::queue<int> Q;
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    int INF = dis[0];
    Q.push(s), vis[s] = 1, dis[s] = 0, flow[s] = INF;
    for (int u; !Q.empty(); )
    {
        u = Q.front(), Q.pop(), vis[u] = 0;
        for (int i = hd[u]; i; i = e[i].ne)
        {
            int v = e[i].to, cost = e[i].cost;
            if (e[i].flow and dis[u] + cost < dis[v])
            {
                dis[v] = dis[u] + cost;
                flow[v] = std::min(flow[u], e[i].flow);
                pre[v] = i;
                if (!vis[v]) vis[v] = 1, Q.push(v);
            }
        }
    }
    return dis[t] ^ INF;
}

void update()
{
    for (int x = t; x != s; x = e[pre[x] ^ 1].to)
        e[pre[x]].flow -= flow[t], e[pre[x] ^ 1].flow += flow[t];
    max_flow += flow[t], min_cost += dis[t] * flow[t];
}

void add(int u, int v, int w, int c) { e[++node] = {hd[u], v, w, c}, hd[u] = node; }

void solve()
{
    n = read(), m = read(), s = read(), t = read();
    for (int u, v, w, c; m--; )
        u = read(), v = read(), w = read(), c = read(),
        add(u, v, w, c), add(v, u, 0, -c);
    while (SPFA()) update();
    std::cout << max_flow << ' ' << min_cost;
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = 1; T--; solve());
    return 0;
}