#include <bits/stdc++.h>
using i64 = long long;
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define pb push_back
using std::cin, std::cout, std::string, std::vector, std::min, std::max, std::swap;
i64 read(i64 x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 || ch > 57) f = ch == 45, ch = getchar();
    while (48 <= ch && ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 5e5 + 5;
const int M = N << 5;

#define mid (l + r >> 1)
typedef unsigned long long ull;

int ls[M], rs[M], rt[N], nodecnt;
ull sum2[M], sum[M], cnt[M], res[M];
void pushup(int p)
{
    int ls = ::ls[p], rs = ::rs[p];
    cnt[p] = cnt[ls] + cnt[rs];
    sum[p] = sum[ls] + sum[rs];
    sum2[p] = sum2[ls] + sum2[rs];
    res[p] = res[ls] + res[rs] + ull(2) * (sum2[rs] * cnt[ls] - sum[rs] * sum[ls]);
}
void modify(int &p, int l, int r, ull k)
{
    if (!p) p = ++nodecnt;
    sum2[p] += k * k, sum[p] += k, cnt[p] += 1;
    if (l == r) return;
    if (k <= mid) modify(ls[p], l, mid, k);
    else modify(rs[p], mid + 1, r, k);
    pushup(p);
}
int merge(int p, int q, int l, int r)
{
    if (!p or !q) return p | q;
    sum2[p] += sum2[q], sum[p] += sum[q], cnt[p] += cnt[q];
    if (l == r) return p;
    ls[p] = merge(ls[p], ls[q], l, mid);
    rs[p] = merge(rs[p], rs[q], mid + 1, r);
    pushup(p);
    return p;
}

void solve()
{
    int n = read();
    vector<vector<int>> g(n + 1);
    vector<int> a(n + 1);
    vector<ull> ans(n + 1);
    for (int i = 1, u, v; i < n; i++)
        u = read(), v = read(), g[u].pb(v), g[v].pb(u);
    for (int i = 1; i <= n; i++) a[i] = read();
    ull res = 0;
    std::function<void(int, int)> dfs = [&](int u, int fa)
    {
        for (int v : g[u])
        {
            if (v == fa) continue;
            dfs(v, u);
            rt[u] = merge(rt[u], rt[v], 1, 1e6);
        }
        modify(rt[u], 1, 1e6, a[u]);
        ans[u] = ::res[rt[u]];
        res ^= ::res[rt[u]];
    };
    dfs(1, 0);
    cout << res;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    solve();
    return 0;
}