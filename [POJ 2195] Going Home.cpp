#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 3e2 + 5;
const int INF = 1 << 30;
char map[N][N];
struct Point { int x, y; };
std::vector<Point> a, b;
int n, m, k, s, t;
int ans, cost[N][N], dis[N];
std::vector<int> g[N];
int cap[N][N], pre[N];
bool vis[N];
#define pb push_back
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
            if (cap[u][v] and dis[u] + cost[u][v] < dis[v])
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
    ans += min * dis[t];
    // std::cout << min << ' ' << dis[t] << '\n';
}


void solve()
{
    memset(cap, 0, sizeof cap);
    memset(cost, 0, sizeof cost);
    for (int i = 1; i <= n; i++, getchar())
        for (int j = 1; j <= m; j++)
            std::cin >> map[i][j];
    a.clear(), b.clear(), ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (map[i][j] == 'm')
                a.push_back({i, j});
            else if (map[i][j] == 'H')
                b.push_back({i, j});

    k = a.size(), s = 0, t = 2 * k + 1;
    // printf("%d\n", k);
    for (int i = 0; i < k; i++)
        for (int j = 0, tmp; j < k; j++)
        {
            int u = i + 1, v = j + 1 + k;
            cost[u][v] = abs(a[i].x - b[j].x) + abs(a[i].y - b[j].y),
            cap[u][v] = 1, cost[v][u] = -cost[u][v];
            // printf("%d %d %d %d\n", u, v, cap[u][v], cost[u][v]);
        }
    for (int i = 1; i <= k; i++) cap[s][i] = 1;
    for (int i = k + 1; i <= 2 * k; i++) cap[i][t] = 1;
    // printf("s:%d t:%d\n", s, t);
    while (SPFA()) update();
    printf("%d\n", ans);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    while (std::cin >> n >> m and n + m) solve();
    return 0;
}