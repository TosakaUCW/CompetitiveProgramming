#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 2e3 + 5;
const int P = 1e9 + 9;

int n, m, k, ans;
int a[N], b[N], last[N];
int fac[N], inv[N], f[N][N], g[N];

int pow(int x, int k, int res = 1)
{
    for (x %= P; k; x = x * x % P, k >>= 1)
        if (k & 1)
            res = res * x % P;
    return res;
}

int C(int i, int j) { return fac[i] * inv[j] % P * inv[i - j] % P; }

signed main()
{
    n = read(), m = read();
    if ((n + m) & 1)
        return puts("0"), 0;
    k = (n + m) / 2, fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % P;
    inv[n] = pow(fac[n], P - 2);
    for (int i = n; i >= 1; i--)
        inv[i - 1] = inv[i] * i % P;
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
        b[i] = read();
    std::sort(a + 1, a + 1 + n), std::sort(b + 1, b + 1 + n);
    for (int i = 1, p = 0; i <= n; last[i++] = p)
        while (p < n and b[p + 1] < a[i])
            p++;
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        f[i][0] = f[i - 1][0];
        for (int j = 1; j <= i; j++)
            f[i][j] = (f[i - 1][j] + f[i - 1][j - 1] * std::max(0LL, last[i] - j + 1) % P) % P;
    }
    for (int i = 0; i <= n; i++)
        g[i] = f[n][i] * fac[n - i] % P;
    for (int i = k; i <= n; i++)
        if ((i - k) & 1)
            (ans += P - C(i, k) * g[i] % P) %= P;
        else
            (ans += C(i, k) * g[i] % P) %= P;
    return printf("%lld", ans), 0;
}