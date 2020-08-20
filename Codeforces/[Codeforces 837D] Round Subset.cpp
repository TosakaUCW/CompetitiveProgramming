#include <stdio.h>
#include <algorithm>
#include <memory.h>

typedef long long ll;

const ll N = 3e2 + 5;
const ll M = 1e5 + 5;

ll n, k, ans;
ll a[N], sum[N];
ll val[N][2], f[N][M];

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
    memset(f, 0xcf, sizeof f);
    n = read(), k = read();
    for (ll i = 1; i <= n; i++)
    {
        a[i] = read();
        while (a[i] % 2 == 0)
            val[i][0]++, a[i] /= 2;
        while (a[i] % 5 == 0)
            val[i][1]++, a[i] /= 5;
        sum[i] = sum[i - 1] + val[i][1];
    }
    f[0][0] = 0;
    for (ll p = 1; p <= n; p++)
        for (ll j = sum[p]; j >= val[p][1]; j--)
            for (ll i = std::min(p, k); i >= 1; i--)
                f[i][j] = std::max(f[i][j], f[i - 1][j - val[p][1]] + val[p][0]);
    for (ll i = 0; i <= k; i++)
        for (ll j = 0; j <= sum[n]; j++)
            ans = std::max(ans, std::min(j, f[i][j]));
    printf("%lld", ans);
    return 0;
}