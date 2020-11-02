#include <stdio.h>
#include <algorithm>
#include <memory.h>

typedef long long ll;

const ll N = 1e3 + 5;
const ll P = 1e4;

ll n, m;
ll f[N][N], sum[N][N];

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
    for (ll i = 1; i <= n; i++)
    {
        f[i][0] = sum[i][0] = 1;
        for (ll j = 1; j <= m; j++)
        {
            if (j - i >= 0)
                f[i][j] = sum[i - 1][j] - sum[i - 1][j - i];
            else
                f[i][j] = sum[i - 1][j];
            (sum[i][j] = sum[i][j - 1] + f[i][j]) %= P;
        }
    }
    printf("%lld", (f[n][m] + P) % P);
    return 0;
}