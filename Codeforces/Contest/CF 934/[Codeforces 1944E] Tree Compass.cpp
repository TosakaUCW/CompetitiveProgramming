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
const int N = 1e6 + 5;
// const int INF = 1e18;
int n, m, a[N];

void solve()
{
    n = read();
    vector<vector<int>> g(n);
    for (int i = 1, u, v; i < n; i++)
        u = read() - 1, v = read() - 1,
        g[u].pb(v), g[v].pb(u);
    vector<int> fa(n);
    auto find = [&](int rt)
    {
        vector<int> dep(n, -1);
        fa[rt] = -1, dep[rt] = 0;
        std::queue<int> Q;
        Q.push(rt);
        for (int u; !Q.empty(); )
        {
            u = Q.front(); Q.pop();
            for (auto v : g[u])
                if (dep[v] == -1)
                    dep[v] = dep[u] + 1, Q.push(v), fa[v] = u;
        }
        return std::max_element(dep.begin(), dep.end()) - dep.begin();
    };
    int X = find(0);
    int Y = find(X);
    vector<int> a;
    for (int i = Y; i != -1; i = fa[i]) a.pb(i);
    vector<pii> ans;
    int d = a.size();
    if (d & 1)
    {
        int p = a[d / 2];
        for (int i = 0; i <= d / 2; i++)
            ans.pb({p, i});
    }
    else
    {
        int p = a[d / 2], q = a[(d - 1) / 2];
        for (int i = 1; i <= d / 2; i += 2)
            ans.pb({p, i}), ans.pb({q, i});
    }
    cout << ans.size() << '\n';
    for (auto [x, y] : ans) cout << x + 1 << ' ' << y << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("D.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}