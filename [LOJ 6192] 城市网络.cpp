#include <stdio.h>
#include <algorithm>
#include <vector>
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 2e5 + 5;
int n, q, a[N], to[N], f[N][21], d[N];
std::vector<int> g[N];
void dfs(int u, int fa)
{
    int x = fa;
    for (int i = 20; i >= 0; i--)
        if (f[x][i] and a[f[x][i]] <= a[u])
            x = f[x][i];
    f[u][0] = a[x] > a[u] ? x : f[x][0], d[u] = d[fa] + 1;
    for (int i = 1; f[f[u][i - 1]][i - 1]; i++)
        f[u][i] = f[f[u][i - 1]][i - 1];
    for (int v : g[u]) if (v ^ fa) dfs(v, u);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("tree1.in", "r", stdin);
    freopen("tree2.out", "w", stdout);
#endif
    n = read(), q = read();
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1, u, v; i < n; i++)
        u = read(), v = read(),
        g[u].emplace_back(v), g[v].emplace_back(u);
    for (int i = 1, u; i <= q; i++)
        u = read(), to[n + i] = read(), a[n + i] = read(),
        g[n + i].emplace_back(u), g[u].emplace_back(n + i);
    dfs(1, 0);
    for (int i =  n + 1; i <= n + q; i++)
    {
        int res = 0, x = i;
        for (int j = 20; j >= 0; j--)
            if (d[f[x][j]] >= d[to[i]])
                res += 1 << j, x = f[x][j];
        printf("%d\n", res);
    }
    return 0;
}