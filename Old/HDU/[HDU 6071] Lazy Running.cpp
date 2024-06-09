#include <bits/stdc++.h>
#define int long long
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

const int D = 1e5 + 5;
const int P = 998244353;

int k, d[5], w;
int dis[5][D];
bool vis[5][D];
vector<pii> g[5];
struct Node
{
    int cur, dis, r;
    bool friend operator<(Node a, Node b) { return a.dis > b.dis; }
};

void dijk()
{
    memset(vis, 0, sizeof vis);
    memset(dis, 0x3f, sizeof dis);
    priority_queue<Node> Q;
    Q.push({2, 0, 0}), dis[2][0] = 0;
    for (int u, r; !Q.empty();)
    {
        u = Q.top().cur, r = Q.top().r, Q.pop();
        if (vis[u][r])
            continue;
        vis[u][r] = 1;
        for (auto V : g[u])
        {
            int v = V.fi, nr = (r + V.se) % w, dist = V.se;
            if (dis[v][nr] > dis[u][r] + dist)
            {
                dis[v][nr] = dis[u][r] + dist;
                Q.push({v, dis[v][nr], nr});
            }
        }
    }
}

void solve()
{
    k = read();
    for (int i = 1; i <= 4; i++)
        d[i] = read(), g[i].clear();
    for (int i = 1; i <= 4; i++)
        g[i].pb({i % 4 + 1, d[i]}), g[i % 4 + 1].pb({i, d[i]});
    w = 2 * std::min(d[1], d[2]), dijk();
    int ans = LLONG_MAX;
    for (int i = 0; i <= w; i++)
        if (dis[2][i] > k)
            ans = std::min(ans, dis[2][i]);
        else
        {
            int res = (k - dis[2][i]) / w * w + dis[2][i];
            if ((k - dis[2][i]) % w)
                res += w;
            ans = std::min(ans, res);
        }
    printf("%lld\n", ans);
}

signed main()
{
    for (int T = read(); T--; solve())
        ;
    return 0;
}