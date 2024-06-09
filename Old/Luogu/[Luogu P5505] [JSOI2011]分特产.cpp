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
const int P = 1e9 + 7;

int n, m, ans;
int a[N];
int fac[N], inv[N], f[N], g[N];

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
    for (int i = 1; i <= m; i++)
        a[i] = read();
    fac[0] = 1;
    for (int i = 1; i < N; i++)
        fac[i] = fac[i - 1] * i % P;
    inv[N - 1] = pow(fac[N - 1], P - 2);
    for (int i = N - 1; i >= 1; i--)
        inv[i - 1] = inv[i] * i % P;
    for (int i = 0; i < n; i++)
    {
        int x = C(n, i);
        for (int j = 1; j <= m; j++)
            (x *= C(n - i + a[j] - 1, a[j])) %= P;
        if (i & 1)
            ans = (ans - x + P) % P;
        else
            ans = (ans + x) % P;
    }
    return printf("%lld", ans), 0;
}