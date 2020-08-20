#include <stdio.h>
#include <algorithm>
#include <memory.h>

typedef long long ll;

const ll N = 2e3 + 5;
const ll P = 1e9 + 7;

ll n, k;
ll fac[N * N];
ll f[N][N];

ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

ll pow(ll x, ll k)
{
    ll res = 1;
    for (x %= P; k; k >>= 1, x = x * x % P)
        if (k & 1)
            res = res * x % P;
    return res;
}

ll C(ll n, ll m) { return ((fac[n] * pow(fac[m], P - 2)) % P * pow(fac[n - m], P - 2) % P); }

signed main()
{
    n = read(), k = read();
    if (k == 1)
    {
        puts("1");
        return 0;
    }
    fac[0] = 1;
    for (ll i = 1; i <= n * k; i++)
        fac[i] = fac[i - 1] * i % P;
    for (ll i = 0; i <= n; i++)
        f[i][0] = 1;
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= i; j++)
            f[i][j] = f[i - 1][j] +
                      f[i][j - 1] * (n - j + 1) % P *
                          C(n * k - i - (j - 1) * (k - 1) - 1, k - 2) % P;
    printf("%lld", f[n][n]);
    return 0;
}