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

const int N = 50 + 5;
const int M = 500 + 5;
const int P = 5;

int n, m, t, p;
string s;
vector<pii> a[N];
unordered_map<string, int> id;
int f[N][M], g[N][M][P];
// f[i][j] 第 i 门科目，前 j 天能获得的最大分数
// g[i][j][k] 前 i 门科目，前 j 天，挂了 k 科能获得的最大分数

void solve()
{
    id.clear(), memset(f, 0, sizeof f), memset(g, 0xcf, sizeof g);
    n = read();
    for (int i = 1; i <= n; i++)
        std::cin >> s, id[s] = i, a[i].clear();
    m = read();
    for (int i = 1, x, y; i <= m; i++)
        std::cin >> s >> x >> y, a[id[s]].pb({x, y});
    t = read(), p = read();
    for (int i = 1; i <= n; i++)
        for (auto x : a[i])
            for (int j = t; j >= x.se; j--)
                f[i][j] = std::max(f[i][j], std::min(100, f[i][j - x.se] + x.fi));
    g[0][0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = t; j; j--)
            for (int k = t; k >= j; k--)
                for (int h = 0; h <= p; h++)
                    if (f[i][j] >= 60)
                        g[i][k][h] = std::max(g[i][k][h], g[i - 1][k - j][h] + f[i][j]);
                    else if (h)
                        g[i][k][h] = std::max(g[i][k][h], g[i - 1][k - j][h - 1] + f[i][j]);
    int ans = -1;
    for (int i = 1; i <= t; i++)
        for (int j = 0; j <= p; j++)
            ans = std::max(ans, g[n][i][j]);
    printf("%d\n", ans);
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif
    for (int T = read(); T--; solve())
        ;
    return 0;
}