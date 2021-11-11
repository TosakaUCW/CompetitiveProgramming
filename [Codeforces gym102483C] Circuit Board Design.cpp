#include <bits/stdc++.h>
// #define int long long
#define fi first
#define se second
#define ins insert
#define pb push_back
#define flu fflush(stdout)
#define pii std::pair<double, double>
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

const int N = 1e3 + 5;
const int P = 998244353;
const double pi = acos(-1.0);

int n, k;
double x[N], y[N];
vector<int> g[N];

void dfs(int u, int fa)
{
    for (auto v : g[u])
        if (v ^ fa)
        {
            x[v] = x[u] + cos(pi / (n - 1) * k);
            y[v] = y[u] + sin(pi / (n - 1) * k);
            k++;
            dfs(v, u);
        }
}

void solve()
{
    n = read();
    for (int i = 1, u, v; i < n; i++)
        u = read(), v = read(),
        g[u].pb(v), g[v].pb(u);
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        printf("%.7f %.7f\n", x[i], y[i]);
}

signed main()
{
#ifndef ONLINE_JUDGE
    // freopen("my_input.in", "r", stdin);
#endif
    // std::cout << pi << '\n';
    solve();
#ifndef ONLINE_JUDGE
    std::cerr << (double)clock() / CLOCKS_PER_SEC << 's' << std::endl;
#endif
    return 0;
}