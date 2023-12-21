#include <vector>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#define int long long
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 16 + 5;

int n, ans;
int g[N][N];
bool used[N];
void dfs(int u, int res)
{
    if (u > n)
        return ans = std::max(ans, res), void();
    for (int v = u + 1; v <= n; v++)
        if (!used[u] and !used[v])
            used[u] = used[v] = 1, dfs(u + 1, res + g[u][v]), used[u] = used[v] = 0;
    dfs(u + 1, res);
}
signed main()
{
    n = read();
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            g[i][j] = g[j][i] = read();
    dfs(1, 0);
    printf("%lld", ans);
    return 0;
}