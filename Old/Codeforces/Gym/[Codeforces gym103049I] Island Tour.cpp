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

const int N = 4e2 + 5;

int n;
int d[N], a[N], b[N], c[N];
pii t1[N], t2[N];
bool ab[N][N], ac[N][N], bc[N][N];

bool solve(int *a, int *b, int i, int j)
{
    for (int t = 0, x = 0, y = 0; t < n; t++)
        t1[i] = {x, x + a[i]}, x += a[i] + d[i], i = i % n + 1,
        t2[j] = {y, y + b[j]}, y += b[j] + d[j], j = j % n + 1;
    for (int i = 1; i <= n; i++)
        if (t1[i].fi < t2[i].se and t2[i].fi < t1[i].se)
            return 0;
    return 1;
}

void solve()
{
    n = read();
    for (int i = 1; i <= n; i++)
        d[i] = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
        b[i] = read();
    for (int i = 1; i <= n; i++)
        c[i] = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            ab[i][j] = solve(a, b, i, j),
            bc[i][j] = solve(b, c, i, j),
            ac[i][j] = solve(a, c, i, j);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (ab[i][j] and bc[j][k] and ac[i][k])
                    return printf("%d %d %d\n", i, j, k), void();
    puts("impossible");
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("I.in", "r", stdin);
#endif
    solve();
#ifndef ONLINE_JUDGE
    std::cerr << (double)clock() / CLOCKS_PER_SEC << 's' << std::endl;
#endif
    return 0;
}