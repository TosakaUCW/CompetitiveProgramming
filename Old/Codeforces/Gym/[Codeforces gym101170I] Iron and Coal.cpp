#include <bits/stdc++.h>
// #define int long long
#define fi first
#define se second
#define ins insert
#define pb push_back
#define flu fflush(stdout)
#define pii std::pair<int, int>
using std::swap, std::vector, std::string, std::queue, std::cin, std::cout;
int read(int x = 0, bool f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e6 + 5;
const int INF = INT_MAX / 3;

int n, m, k, ans = INF;
vector<int> a, b, c;
vector<int> g1[N], g2[N];
int dis[3][N];

void bfs(int i, auto &S, auto &g)
{
    std::queue<int> Q;
    for (auto x : S) Q.push(x), dis[i][x] = 0;
    for (int u; !Q.empty(); )
    {
        u = Q.front(), Q.pop();
        for (auto v : g[u])
            if (dis[i][v] == INF)
                dis[i][v] = dis[i][u] + 1, Q.push(v);
    }
}

void solve()
{
    n = read(), m = read(), k = read();
    a.pb(1);
    for (int i = 1; i <= m; i++) b.pb(read());
    for (int i = 1; i <= k; i++) c.pb(read());
    for (int i = 1; i <= n; i++)
        for (int j = read(), x; j--; )
            k = read(), g1[i].pb(k), g2[k].pb(i);
    for (int i = 1; i <= n; i++) dis[0][i] = dis[1][i] = dis[2][i] = INF;
    bfs(0, a, g1), bfs(1, b, g2), bfs(2, c, g2);
    for (int i = 1; i <= n; i++) ans = std::min(ans, dis[0][i] + dis[1][i] + dis[2][i]);
    if (ans == INF) puts("impossible");
    else printf("%d\n", ans);
}

signed main() { return solve(), 0; }