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

const int N = (1LL << 20) + 5;
const int P = 998244353;

int n, ans;
int a[N], b[N], f[2][N], g[2][N];

int get(int k)
{
    int a_max = f[0][k];
    int a_min = g[0][k];
    int b_max = f[1][k];
    int b_min = g[1][k];
    int res = a_max * b_max;
    res = std::max(res, a_min * b_min);
    res = std::max(res, a_min * b_max);
    res = std::max(res, a_max * b_min);
    return res;
}

void solve()
{
    memset(f, 0, sizeof f), memset(g, 0, sizeof g);
    n = read(), ans = 0;
    for (int i = 0; i < n; i++)
        a[i] = read(), f[0][i] = g[0][i] = a[i];
    for (int i = 0; i < n; i++)
        b[i] = read(), f[1][i] = g[1][i] = b[i];
    for (int S = n - 1; S >= 0; S--)
        for (int i = 0; i < 19; i++)
            if ((S | (1LL << i)) < n)
                for (int j = 0; j < 2; j++)
                    f[j][S] = std::max(f[j][S], f[j][S | (1LL << i)]),
                    g[j][S] = std::min(g[j][S], g[j][S | (1LL << i)]);
    int las = LLONG_MIN;
    for (int i = n - 1; i >= 0; i--)
        ans = (ans + std::max(las, get(i)) + P) % P,
        las = std::max(las, get(i));
    printf("%lld\n", ans % P);
}

signed main()
{
    for (int T = read(); T--; solve())
        ;
    return 0;
}