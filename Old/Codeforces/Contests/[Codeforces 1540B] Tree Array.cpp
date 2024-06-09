#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define ins insert
#define pb emplace_back
#define flu fflush(stdout)
#define pii std::pair<int, int>
using std::map;
using std::priority_queue;
using std::queue;
using std::set;
using std::stack;
using std::string;
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

const int N = 200 + 5;
const int P = 1e9 + 7;

int n, k, f[N][N], ans;
vector<int> g[N];
int fa[N], dep[N], siz[N], son[N], top[N];

void dfs1(int u, int fa)
{
    siz[u] = 1, ::fa[u] = fa, dep[u] = dep[fa] + 1, son[u] = 0;
    for (auto v : g[u])
        if (v ^ fa)
            dfs1(v, u), siz[u] += siz[v], son[u] = siz[v] > siz[son[u]] ? v : son[u];
}

void dfs2(int u)
{
    top[u] = u == son[fa[u]] ? top[fa[u]] : u;
    if (son[u])
        dfs2(son[u]);
    for (auto v : g[u])
        if (v ^ son[u] and v ^ fa[u])
            dfs2(v);
}

int LCA(int x, int y)
{
    for (; top[x] ^ top[y]; x = fa[top[x]])
        if (dep[top[x]] < dep[top[y]])
            std::swap(x, y);
    return dep[x] < dep[y] ? x : y;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("my_input.in", "r", stdin);
#endif
    n = read(), k = pow(2, P - 2, P);
    for (int i = 1; i <= n; i++)
        f[0][i] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            f[i][j] = k * (f[i - 1][j] + f[i][j - 1]) % P;
    for (int i = 1, x, y; i < n; i++)
        x = read(), y = read(), g[x].pb(y), g[y].pb(x);
    for (int i = 1; i <= n; i++)
    {
        dfs1(i, 0), dfs2(i);
        for (int x = 1; x <= n; x++)
            for (int y = 1; y < x; y++)
            {
                int k = LCA(x, y);
                ans = (ans + f[dep[x] - dep[k]][dep[y] - dep[k]]) % P;
            }
        // printf("%lld\n", ans);
    }
    printf("%lld", ans * pow(n, P - 2, P) % P);
    return 0;
}