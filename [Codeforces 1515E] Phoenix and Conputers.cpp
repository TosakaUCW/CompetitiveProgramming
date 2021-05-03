#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

using std::swap;

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 4e2 + 5;

int n, P, ans;
int pow[N], f[N][N], inv[N], fac[N];

int poww(int x, int k, int res = 1)
{
    for (x = (x + P) % P, k = k % (P - 1); k; k >>= 1, x = x * x % P)
        if (k & 1)
            res = res * x % P;
    return res;
}

int C(int n, int m) { return fac[n] * inv[m] % P * inv[n - m] % P; }

signed main()
{
    n = read(), P = read(), pow[0] = fac[0] = f[1][1] = 1, f[2][1] = 2;
    for (int i = 1; i <= n; i++)
        pow[i] = pow[i - 1] * 2LL % P,
        fac[i] = fac[i - 1] * i % P;
    inv[n] = poww(fac[n], P - 2);
    for (int i = n; i; i--)
        inv[i - 1] = inv[i] * i % P;
    for (int i = 3; i <= n; i++)
        for (int j = 1; j <= (i + 1) / 2; j++)
        {
            if (j != 1)
                for (int k = 1; k <= i - 2; k++)
                    f[i][j] = (f[i][j] + f[k][j - 1] * C(i - j + 1, i - k - 1) % P * pow[i - k - 2] % P) % P;
            else
                f[i][j] = pow[i - 1];
            if (i == n)
                ans = (ans + f[i][j]) % P;
        }
    return printf("%lld", ans), 0;
}
