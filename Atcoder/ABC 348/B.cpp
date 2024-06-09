#include <bits/stdc++.h>
// #define int long long
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
using ull = unsigned long long;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 2e5 + 5;
vector<int> g[N];
ull ans[N], sumc[N], c[N];
ull Ans = 1ull << 63;
void dfs1(int u, int fa, ull dep)
{
    sumc[u] = c[u];
    for (int v : g[u]) if (v ^ fa) dfs1(v, u, dep + 1), sumc[u] += sumc[v];
    ans[1] += c[u] * dep;
}
void dfs2(int u, int fa)
{
    for (int v : g[u]) if (v ^ fa)  ans[v] = ans[u] - sumc[v] + (sumc[1] - sumc[v]), dfs2(v, u);
}
void solve()
{
    int n = read();
    for (int u, v, i = 1; i < n; i++)
        u = read(), v = read(), g[u].pb(v), g[v].pb(u);
    for (int i = 1; i <= n; i++) c[i] = read();
    dfs1(1, 0, 0), dfs2(1, 0);
    for (int i = 1; i <= n; i++) Ans = std::min(Ans, ans[i]);
    cout << Ans;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif
    for (int T = 1; T--; solve());
    return 0;
}