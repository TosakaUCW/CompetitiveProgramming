#include <stdio.h>
#include <algorithm>
#include <memory.h>

typedef long long ll;
#define cnt(x) __builtin_popcountll(x)

const ll N = 10 + 5;

ll n, m;
ll f[N][1 << N][N * N];

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
    for (ll S = (1 << n) - 1; ~S; S--)
    {
        if (S & (S << 1) or S & (S >> 1))
            continue;
        f[1][S][cnt(S)] = 1;
    }
    for (ll i = 2; i <= n; i++)
        for (ll j = (1 << n) - 1; ~j; j--)
            for (ll k = (1 << n) - 1; ~k; k--)
            {
                if (j & k)
                    continue;
                if ((j << 1) & k or (j >> 1) & k)
                    continue;
                if (j & (j >> 1) or k & (k >> 1))
                    continue;
                for (ll p = cnt(j); p <= m; p++)
                    f[i][j][p] += f[i - 1][k][p - cnt(j)];
            }
    ll ans = 0;
    for (ll S = (1 << n) - 1; ~S; S--)
        ans += f[n][S][m];
    printf("%lld", ans);
    return 0;
}