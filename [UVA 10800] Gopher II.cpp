#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <math.h>
#include <iostream>
const int N = 5e5 + 5;
int n, m, ans, s, v, t;
std::vector<int> g[N];
#define pb emplace_back
double x[N], y[N];
int tim, vis[N], match[N];

int dfs(int u)
{
    for (int v : g[u])
        if (vis[v] != tim)
        {
            vis[v] = tim;
            if (!match[v] or dfs(match[v]))
            {
                match[v] = u;
                return 1;
            }
        }
    return 0;
}


signed main()
{
    while (std::cin >> n >> m >> v >> t)
    {
        ans = 0, s = v * t;
        for (int i = 0; i <= 5e4; i++) g[i].clear();
        for (int i = 1; i <= n + m; i++) std::cin >> x[i] >> y[i];
        for (int i = 1; i <= n; i++)
            for (int j = n + 1; j <= n + m; j++)
            {
                double dis = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
                if (dis <= s * s) g[i].pb(j), g[j].pb(i);
            }
        memset(match, 0, sizeof match);
        for (int i = 1; i <= n; i++)
            tim++, ans += dfs(i);
        std::cout << n - ans << '\n';
    }
    return 0;
}