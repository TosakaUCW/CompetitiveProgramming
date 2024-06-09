#include <bits/stdc++.h>
// #define int long long
#define fi first
#define se second
#define ins insert
#define pb push_back
#define flu fflush(stdout)
#define pii std::pair<int, int>
using std::map;
using std::priority_queue;
using std::queue;
using std::set;
using std::stack;
using std::string;
using std::swap;
using std::unordered_map;
using std::unordered_set;
using std::vector;
int read(int x = 0, bool f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
int pow(int x, int k, int P, int res = 1)
{
    for (; k; k >>= 1, x = x * x % P)
        if (k & 1)
            res = res * x % P;
    return res;
}

const int N = 1e5 + 5;
const int P = 998244353;

int n, m, t;
vector<int> g[N], ans;
std::set<int> S, T[N];

void dfs(int u, int st)
{
    if (T[u].size() > 1 or T[u].count(st))
        return;
    T[u].ins(st);
    for (auto v : g[u])
        dfs(v, st);
}

void solve()
{
    n = read(), m = read(), t = read();
    for (int i = 1, u, v; i <= m; i++)
    {
        u = read(), v = read();
        if (v == t)
            S.ins(u);
        else
            g[v].pb(u);
    }
    for (auto u : S)
        dfs(u, u);
    for (auto u : S)
        if (T[u].size() == 1)
            ans.pb(u);
    printf("%d\n", ans.size());
    std::sort(ans.begin(), ans.end());
    for (auto u : ans)
        printf("%d\n", u);
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("K.in", "r", stdin);
#endif
    solve();
#ifndef ONLINE_JUDGE
    std::cerr << (double)clock() / CLOCKS_PER_SEC << 's' << std::endl;
#endif
    return 0;
}