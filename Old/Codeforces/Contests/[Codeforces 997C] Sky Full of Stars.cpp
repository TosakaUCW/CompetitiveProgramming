#include <stdio.h>
#include <algorithm>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 1e6 + 5;
const int P = 998244353;

int n, ans, res;
int inv[N], fac[N];

int pow(int x, int k, int res = 1)
{
    for (x = (x + P) % P, k = k % (P - 1); k; k >>= 1, x = x * x % P)
        if (k & 1)
            res = res * x % P;
    return res;
}

int C(int n, int m) { return fac[n] * inv[m] % P * inv[n - m] % P; }

signed main()
{
    n = read(), fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = fac[i - 1] * i % P;
    inv[n] = pow(fac[n], P - 2);
    for (int i = n; i; i--)
        inv[i - 1] = inv[i] * i % P;
    for (int i = 1; i <= n; i++)
    {
        int tmp = C(n, i) * pow(pow(3, i * n), P - 2) % P * (pow(1 - pow(pow(3, n - i), P - 2), n) - 1 + P) % P;
        if (i & 1)
            ans = (ans - tmp + P) % P;
        else
            ans = (ans + tmp + P) % P;
    }
    for (int i = 1; i <= n; i++)
    {
        int tmp = C(n, i) * pow(3, n * (n - i) + i) % P;
        if (i & 1)
            res = (res - tmp + P) % P;
        else
            res = (res + tmp + P) % P;
    };
    ans = (ans * -pow(3, n * n + 1) - 2 * res + P) % P;
    printf("%lld", (ans + P) % P);
    return 0;
}