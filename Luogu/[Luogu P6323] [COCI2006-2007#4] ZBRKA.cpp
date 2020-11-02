#include <stdio.h>
#include <algorithm>
#include <memory.h>

typedef long long ll;

const ll K = 1e4 + 5;
const ll P = 1e9 + 7;

ll n, m;
ll f[2][K], sum[2][K];

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

signed main()
{
    n = read(), m = read();
    for (ll cnt = 1, i = 1; cnt <= n; cnt++, i ^= 1)
    {
        f[i][0] = sum[i][0] = 1;
        for (ll j = 1; j <= m; j++)
        {
            if (j - cnt >= 0)
                f[i][j] = ((sum[i ^ 1][j] % P - sum[i ^ 1][j - cnt] % P) + P) % P;
            else
                f[i][j] = sum[i ^ 1][j] % P;
            (sum[i][j] = (sum[i][j - 1] % P + f[i][j] % P) % P + P) %= P;
        }
    }
    printf("%lld", (f[n % 2][m] + P) % P);
    return 0;
}