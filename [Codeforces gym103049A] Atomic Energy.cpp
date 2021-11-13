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

const int N = 1e2 + 5;
const int M = 1e6 + 5;
const int P = 998244353;

int n, q;
int f[M];

void solve()
{
    memset(f, 0x3f, sizeof f), f[0] = 0;
    n = read(), q = read();
    for (int i = 1; i <= n; i++)
        f[i] = read();

    int k = 1;
    for (int i = 2; i <= n; i++)
        if (f[k] * i > f[i] * k)
            k = i;

    for (int i = n + 1; i < M; i++)
        for (int j = 1; j <= n; j++)
            f[i] = std::min(f[i], f[i - j] + f[j]);

    while (q--)
    {
        int x = read();
        if (x < M)
            printf("%lld\n", f[x]);
        else
        {
            int tot = (x - (M - 1) + k - 1) / k;
            int ans = tot * f[k];
            x -= tot * k;
            printf("%lld\n", ans + f[x]);
        }
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif
    solve();
#ifndef ONLINE_JUDGE
    std::cerr << (double)clock() / CLOCKS_PER_SEC << 's' << std::endl;
#endif
    return 0;
}