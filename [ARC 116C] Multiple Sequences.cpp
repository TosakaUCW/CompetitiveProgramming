#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 5e5 + 5;
const int P = 998244353;

int n, m, ans;
int fac[N], inv[N];

int pow(int x, int k)
{
    int res = 1;
    for (; k; k >>= 1, x = x * x % P)
        if (k & 1)
            res = res * x % P;
    return res;
}

int C(int n, int m) { return fac[n] * inv[m] % P * inv[n - m] % P; }

signed main()
{
    n = read(), m = read(), fac[0] = 1;
    for (int i = 1; i <= N - 1; i++)
        fac[i] = fac[i - 1] * i % P;
    inv[N - 1] = pow(fac[N - 1], P - 2);
    for (int i = N - 2; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % P;
    for (int i = 1; i <= m; i++)
    {
        int x = i, res = 1;
        for (int p = 2; p * p <= x; p++)
            if (x % p == 0)
            {
                int cnt = 0;
                while (x % p == 0)
                    x /= p, cnt++;
                res = res * C(n + cnt - 1, cnt) % P;
            }
        if (x != 1)
            res = res * n % P;
        ans = (ans + res) % P;
    }
    printf("%lld", ans);
    return 0;
}