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

const int N = 3e5 + 5;
const int P = 998244353;

int n;
int a[N], sum[N], f[1 << 20];

void solve()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read(), sum[i] = sum[i - 1] ^ a[i];
    memset(f, 0x3f, sizeof f);
    for (int i = n; i >= 0; i--)
        f[sum[i]] = i;
    int all = (1 << 20) - 1;
    for (int S = all; S >= 0; S--)
        for (int j = 0; j < 20; j++)
            if (!(S >> j & 1))
                f[S] = std::min(f[S], f[S | (1 << j)]);
    for (int i = 1; i <= n; i++)
    {
        int x = 0;
        for (int j = 19; j >= 0; j--)
            if (!(sum[i] >> j & 1) and f[x | (1 << j)] <= i)
                x |= (1 << j);
        printf("%d\n", x + (x ^ sum[i]));
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("div9.in", "r", stdin);
    freopen("div.out", "w", stdout);
#endif
    solve();
    return 0;
}