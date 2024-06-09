#include <stdio.h>
#include <algorithm>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 2e5 + 5;
const int P = 998244353;

int n, ans, a[N], sum[N], poww[N], inv[N];

int pow(int x, int k)
{
    int res = 1;
    for (; k; k >>= 1, x = x * x % P)
        if (k & 1)
            res = res * x % P;
    return res;
}

signed main()
{
    n = read(), poww[0] = 1;
    for (int i = 1; i <= n; i++)
        a[i] = read(),
        poww[i] = poww[i - 1] * 2 % P,
        ans = (ans + a[i] * a[i] % P) % P;
    inv[n] = pow(poww[n], P - 2);
    for (int i = n - 1; i >= 1; i--)
        inv[i] = inv[i + 1] * 2 % P;
    std::sort(a + 1, a + 1 + n);
    for (int i = n; i >= 1; i--)
        sum[i] = (sum[i + 1] + a[i] * poww[i - 1] % P) % P;
    for (int i = 1; i < n; i++)
        ans = (ans + a[i] * inv[i] % P * sum[i + 1] % P) % P;
    printf("%lld", ans);
    return 0;
}