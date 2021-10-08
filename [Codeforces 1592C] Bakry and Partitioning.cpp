#include <stdio.h>
#include <algorithm>
#include <vector>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57) f = ch == 45, ch = getchar ();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 2e5 + 5;

int n, k, sum, cnt, a[N];
std::vector<int> g[N];

int dfs(int u, int fa)
{
    int res = a[u];
    for (int v : g[u])
       if (v ^ fa)
       {
           int t = dfs(v, u);
           if (t == sum) cnt++;
           else res ^= t;
       } 
    return res;
}

void solve()
{
    n = read(), k = read(), sum = cnt = 0;
    for (int i = 1; i <= n; i++) a[i] = read(), sum ^= a[i], g[i].clear();
    for (int i = 1, u, v; i < n; i++)
        u = read(), v = read(),
        g[u].push_back(v), g[v].push_back(u);
    if (!sum) puts("YES");
    else if (k >= 3) dfs(1, 0), puts(cnt >= 2 ? "YES" : "NO");
    else puts("NO");
}

int main()
{
    for (int T = read(); T--; solve());
    return 0;
}
