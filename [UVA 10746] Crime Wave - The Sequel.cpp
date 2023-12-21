#include <stdio.h>
#include <algorithm>
#include <queue>
#include <string.h>
#include <iostream>
// #define int long long
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 5e3 + 5;
const int M = 5e4 + 5;
const double INF = 1 << 30;
const double eps = 1e-6;

int n, m, s, t;
double ans, cost[N][N], dis[N];
std::vector<int> g[N];
int cap[N][N], pre[N];
bool vis[N];

#define pb emplace_back
void add(int u, int v, int w, double c) { g[u].pb(v), cap[u][v] = w, cost[u][v] = c; }

bool SPFA()
{
    std::queue<int> Q;
    for (int i = s; i <= t; i++) dis[i] = INF, vis[i] = 0, pre[i] = -1;
    Q.push(s), vis[s] = 1, dis[s] = 0;
    for (int u; !Q.empty(); )
    {
        u = Q.front(), Q.pop(), vis[u] = 0;
        for (int v = s; v <= t; v++)
            if (cap[u][v] and dis[u] + cost[u][v] + eps < dis[v])
            {
                dis[v] = dis[u] + cost[u][v];
                pre[v] = u;
                if (!vis[v]) vis[v] = 1, Q.push(v);
            }
    }
    return pre[t] != -1;
}

void update()
{
    int min = 1 << 30;
    for (int u = t; u != s; u = pre[u])
        min = std::min(min, cap[pre[u]][u]);
    for (int u = t; u != s; u = pre[u])
        cap[pre[u]][u] -= min, cap[u][pre[u]] += min;
    ans += 1.0 * min * dis[t];
    // std::cout << min << ' ' << dis[t] << '\n';
}


void solve()
{
    memset(cap, 0, sizeof cap);
    memset(cost, 0, sizeof cost);
    s = 0, t = n + m + 1, ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int u = j, v = m + i;
            std::cin >> cost[u][v];
            cap[u][v] = 1, cost[v][u] = -cost[u][v];
        }
    for (int i = 1; i <= m; i++) cap[s][i] = 1;
    for (int i = m + 1; i <= n + m; i++) cap[i][t] = 1;
    while (SPFA()) update();
    printf("%.2f\n", ans / n + eps);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (n = read(), m = read(); n or m; solve(), n = read(), m = read());
    return 0;
}