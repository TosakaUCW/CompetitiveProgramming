#include <stdio.h>
#include <string.h>
#include <iostream>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 5e2 + 5;
int n, m, g[N][N];
int tim, vis[N], match[N];
int dfs(int u)
{
    for (int v = 1; v <= n; v++)
        if (g[u][v] and vis[v] != tim)
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
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    while (std::cin >> n >> m)
    {
        memset(match, 0, sizeof match);
        memset(g, 0, sizeof g);
        for (int u, v; m--; ) u = read(), v = read(), g[u][v] = 1;
        int ans = 0;
        for (int i = 1; i <= n; i++) tim++, ans += dfs(i);
        printf("%d\n", ans);
    }
    return 0;
}