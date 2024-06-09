#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <math.h>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 100 + 5;
const double eps = 1e-5;
typedef std::pair<double, double> pii;
#define x first
#define y second
int n, m, k;
pii a[N], b[N];
double dist[N][N];
int tim, vis[N], match[N], g[N][N];
int dfs(int u)
{
    for (int v = m + 1; v <= 2 * m; v++)
        if (g[u][v] and vis[v] != tim)
        {
            vis[v] = tim;
            if (!match[v] or dfs(match[v])) { match[v] = u; return 1; }
        }
    return 0;
}
bool judge(double x)
{
    memset(match, 0, sizeof match), memset(g, 0, sizeof g);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (dist[i][j] <= x) g[i][j + m] = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) tim++, ans += dfs(i);
    return ans >= n - k;
}
void solve()
{
    n = read(), m = read(), k = read();
    for (int i = 1; i <= n; i++) std::cin >> a[i].x >> a[i].y;
    for (int i = 1; i <= m; i++) std::cin >> b[i].x >> b[i].y;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dist[i][j] = sqrt(pow(a[i].x - b[j].x, 2) + pow(a[i].y - b[j].y, 2));
    if (n - k > m) return printf("Too bad.\n\n"), void();
    double L = 0, R = 1e9;
    for (int cnt = 100; cnt--; )
    {
        double mid = (L + R) / 2;
        if (judge(mid)) R = mid;
        else L = mid;
    }
    printf("%.3lf\n\n", L);
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    int T = read();
    for (int i = 1; i <= T; printf("Case #%d:\n", i++), solve());
    return 0;
}