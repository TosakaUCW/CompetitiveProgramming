#include <bits/stdc++.h>
// #define int long long
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 2e5 + 5;
// const int INF = 1e18;
int n, ans, c[N], siz[N], cnt[N], ccnt[N], son[N];
vector<int> g[N];
void dfs(int u)
{
    siz[u] = 1;
    for (auto v : g[u]) dfs(v), siz[u] += siz[v], son[u] = siz[v] > siz[son[u]] ? v : son[u];
}
void add(int u, int k)
{
    --ccnt[cnt[c[u]]], cnt[c[u]] += k, ++ccnt[cnt[c[u]]];
    for (auto v : g[u]) add(v, k);
}
void go(int u, bool f)
{
    for (auto v : g[u]) if (v ^ son[u]) go(v, 0);
    if (son[u]) go(son[u], 1);
    --ccnt[cnt[c[u]]], cnt[c[u]]++, ++ccnt[cnt[c[u]]];
    for (auto v : g[u]) if (v ^ son[u]) add(v, 1);
    if (ccnt[cnt[c[u]]] * cnt[c[u]] == siz[u]) ++ans;
    if (!f) add(u, -1);
}
void solve()
{
    n = read();
    for (int i = 1; i <= n; i++) c[i] = read(), g[read()].pb(i);
    dfs(1), go(1, 1), printf("%d", ans);
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("D.in", "r", stdin);
#endif
    for (int T = 1; T--; solve());
    return 0;
}