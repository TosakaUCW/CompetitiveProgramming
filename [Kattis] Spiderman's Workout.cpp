#include <stdio.h>
#include <algorithm>
#include <string.h>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 1e3 + 5;
const int INF = 0x3f3f3f3f;
int n, f[N][N], g[N][N];
void dfs(int i, int j) { if (~g[i][j]) dfs(i - 1, g[i][j]), putchar(g[i][j] > j ? 'D' : 'U'); }
void solve()
{
    memset(f, 0x3f, sizeof f), memset(g, -1, sizeof g);
    n = read(), f[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0, x = read(); j <= 1e3; j++)
        {
            if (j - x >= 0 and f[i - 1][j - x] != INF and f[i][j] > std::max(f[i - 1][j - x], j))
                f[i][j] = std::max(f[i - 1][j - x], j), g[i][j] = j - x;
            if (j + x <= 1e3 and f[i - 1][j + x] != INF and f[i][j] > f[i - 1][j + x])
                f[i][j] = f[i - 1][j + x], g[i][j] = j + x;
        }
    if (f[n][0] == INF) puts("IMPOSSIBLE");
    else dfs(n, 0), puts("");
}
signed main()
{
    for (int T = read(); T--; solve());
    return 0;
}