#include <bits/stdc++.h>
#define fi first
#define se second
#define ins insert
#define pb emplace_back
#define flu fflush(stdout)
#define pii std::pair<int, int>
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
const int INF = 2147483647;

int n, a[N];
long long ans, f[2][N];

void solve()
{
    n = read(), ans = 0;
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = *std::max_element(a + 1, a + 1 + n); i >= 0; i--)
        f[0][i] = f[1][i] = 0;
    vector<int> v[2];
    for (int i = n, k = 0; i >= 1; i--, k ^= 1)
    {
        f[k][a[i]] = 1, v[k].pb(a[i]);
        int las = a[i];
        for (auto x : v[k ^ 1])
        {
            int t = ceil(a[i] * 1.0 / x);
            f[k][a[i] / t] += f[k ^ 1][x];
            if (las != a[i] / t)
                v[k].pb(a[i] / t), las = a[i] / t;
            ans = (ans + 1LL * i * f[k ^ 1][x] * (t - 1) % P) % P;
        }
        for (auto x : v[k ^ 1])
            f[k ^ 1][x] = 0;
        v[k ^ 1].clear();
    }
    printf("%lld\n", ans);
}

signed main()
{
    for (int T = read(); T--; solve())
        ;
    return 0;
}
/*
从右往左扫过去，发现拆的时候决策是唯一的 : 最小元素最大
if a[i] > a[i + 1] then a[i] -> floor(a[i] / ceil(a[i] / a[i + 1]))
e.g. 17 -> 4 4 4 5
考虑一个 dp, f[i][x], a[i] 被拆成最小元素为 x，且以 x 开头的合法序列数量
a[i - 1] 被拆成 y, dp[i - 1][y] += dp[i][x]
*/