#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <string>
#include <iostream>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 3e5 + 5;

int n, m, q, fath[N];
std::vector<std::pair<int, int>> g[N];
std::vector<int> a[N][2];
int fa[N], oud[N], dep[N], idx[N], cnt[N];

#define pb emplace_back
int find(int x) { return x == fath[x] ? x : fath[x] = find(fath[x]); }
void dfs(int u, int fa)
{
    ::fa[u] = fa, dep[u] = dep[fa] + 1;
    for (auto [v, id] : g[u]) if (v ^ fa) idx[v] = id, dfs(v, u);
}

int main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++) fath[i] = i;
    for (int i = 1, u, v, x, y; i <= m; i++)
    {
        u = read(), v = read(), x = find(u), y = find(v);
        if (x ^ y) fath[x] = y, g[u].pb(v, i), g[v].pb(u, i);
    } 
    dfs(1, 0), q = read();
    for (int i = 1; i <= q; i++)
    {
        int u = read(), v = read();
        while (dep[u] > dep[v]) a[i][0].pb(u), cnt[idx[u]] ^= 1, u = fa[u];
        while (dep[v] > dep[u]) a[i][1].pb(v), cnt[idx[v]] ^= 1, v = fa[v];
        while (u ^ v)
            a[i][0].pb(u), cnt[idx[u]] ^= 1, u = fa[u],
            a[i][1].pb(v), cnt[idx[v]] ^= 1, v = fa[v];
        a[i][0].pb(u);
        std::reverse(a[i][1].begin(), a[i][1].end());
        a[i][0].insert(a[i][0].end(), a[i][1].begin(), a[i][1].end());
    } 
    for (int i = 1; i <= n; i++)
        for (auto [v, id] : g[i]) 
            oud[i] ^= cnt[id];
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += oud[i];
    ans >>= 1;
    if (ans) printf("NO\n%d", ans);
    else
    {
        puts("YES");
        for (int i = 1; i <= q; i++)
        {
            printf("%d\n", a[i][0].size());
            for (auto x : a[i][0]) printf("%d ", x);
            puts("");
        }
    }
    return 0;
}
