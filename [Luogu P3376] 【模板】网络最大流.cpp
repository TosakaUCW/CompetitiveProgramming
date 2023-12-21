#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#define int long long
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 2e2 + 5;
int n, m, s, t, ans;
std::vector<int> g[N];
int dis[N][N], min[N], pre[N];
bool vis[N];
#define pb emplace_back
bool bfs()
{
    memset(vis, 0, sizeof vis);
    std::queue<int> q;
    q.push(s), vis[s] = 1, min[s] = 2147483647;
    for (int u; !q.empty(); )
    {
        u = q.front(), q.pop();
        for (int v : g[u])
            if (!vis[v] and dis[u][v] > 0)
            {
                min[v] = std::min(min[u], dis[u][v]);
                vis[v] = 1, q.push(v), pre[v] = u;
                if (v == t) return 1;
            }
    }
    return 0;
}
void update()
{
    for (int x = t; x != s; x = pre[x])
        dis[x][pre[x]] += min[t], dis[pre[x]][x] -= min[t];
    ans += min[t];
}
void solve()
{
    n = read(), m = read(), s = read(), t = read();
    for (int u, v, dis; m--; )
        u = read(), v = read(), dis = read(),
        g[u].pb(v), g[v].pb(u), ::dis[u][v] += dis;
    while (bfs()) update();
    printf("%lld", ans);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = 1; T--; solve());
    return 0;
}