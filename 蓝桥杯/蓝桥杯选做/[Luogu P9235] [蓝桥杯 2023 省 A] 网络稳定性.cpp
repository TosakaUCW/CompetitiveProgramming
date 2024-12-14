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
const int N = 6e5 + 5;
// const int INF = 1e18;
int n, m, q;
int fa[N], hd[N], cnt;
struct Node
{
    int u, v, dis;
    bool friend operator < (Node a, Node b) { return a.dis > b.dis; }
};
struct Edge { int nxt, to, dis; } e[N];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
void add(int u, int v, int dis) { e[++cnt] = {hd[u], v, dis}, hd[u] = cnt; }
int dep[N], f[N][25], g[N][25];
void dfs(int u)
{
    for (int i = hd[u], v; i; i = e[i].nxt)
        if (!dep[v = e[i].to])
            dep[v] = dep[u] + 1, f[v][0] = u, g[v][0] = e[i].dis, dfs(v);
}
int LCA(int x, int y)
{
    int res = 1999999;
    if (dep[x] > dep[y]) std::swap(x, y);
    for (int i = 23; i >= 0; i--)
        if (dep[f[y][i]] >= dep[x])
            res = std::min(res, g[y][i]), y = f[y][i];
    if (x == y) return res;
    for (int i = 23; i >= 0; i--)
        if (f[x][i] >= 1 and f[x][i] != f[y][i])
            res = std::min(res, std::min(g[x][i], g[y][i])),
            x = f[x][i], y = f[y][i];
    res = std::min(res, std::min(g[x][0], g[y][0]));
    return res;
}
void solve()
{
    n = read(), m = read(), q = read();
    vector<Node> edge;
    for (int i = 1; i <= m; i++)
    {
        int u = read(), v = read(), dis = read();
        edge.pb({u, v, dis});
    }
    std::sort(edge.begin(), edge.end());
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (auto [u, v, dis] : edge)
    {
        int fx = find(u);
        int fy = find(v);
        if (fx != fy)
            fa[fy] = fx, add(u, v, dis), add(v, u, dis);
    }
    for (int i = 1; i <= n; i++) if (!dep[i]) dep[i] = 1, dfs(i);
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i <= n; i++)
            if (dep[i] - (1 << j) >= 1)
                f[i][j] = f[f[i][j - 1]][j - 1],
                g[i][j] = std::min(g[i][j - 1], g[f[i][j - 1]][j - 1]);
    while (q--)
    {
        int x = read(), y = read();
        if (find(x) != find(y)) puts("-1");
        else cout << LCA(x, y) << '\n';
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif
    for (int T = 1; T--; solve());
    return 0;
}