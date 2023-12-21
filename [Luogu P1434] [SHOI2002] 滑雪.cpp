#include <stdio.h>
#include <algorithm>
#include <iostream>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 1e3 + 5;
int n, m, ans;
int a[N][N], f[N][N];
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int dfs(int x, int y)
{
    if (f[x][y]) return f[x][y];
    // printf("%d %d\n", x, y);
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx < 1 or xx > n or yy < 1 or yy > m)
            continue;
        if (a[xx][yy] < a[x][y])
            f[x][y] = std::max(f[x][y], 1 + dfs(xx, yy));
    }
    return f[x][y];
}
signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans = std::max(ans, dfs(i, j));
    printf("%d", ans + 1);
    return 0;
}