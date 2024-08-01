#include <bits/stdc++.h>
#define int long long
#define pb push_back
using std::cin, std::cout, std::string;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 1e6 + 5;
const int INF = 1 << 30;
// const long long INF = 1LL << 60;
int a[N];
std::vector<int> g[N];
int dep[N], ans;
void dfs(int u, int fa)
{
    int f = 1;
    for (auto v : g[u])
        if (v != fa)
            f = 0, dep[v] = dep[u] + 1, dfs(v, u);
    if (f) ans += dep[u] + 1 + (dep[u] - 1) * dep[u] / 2;
}
void solve()
{
    int n = read();
    for (int i = 0; i <= n; i++) g[i].clear();
    ans = 0;
    for (int i = 1; i < n; i++)
    {
        int u = read(), v = read();
        g[u].pb(v), g[v].pb(u);
    }
    dep[1] = 1, dfs(1, 0);
    cout << ans << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("D.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}