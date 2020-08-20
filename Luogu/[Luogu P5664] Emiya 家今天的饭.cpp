#include <memory.h>
#include <stdio.h>
#include <algorithm>

typedef long long ll;

const ll N = 1e2 + 5;
const ll M = 2e3 + 5;
const ll P = 998244353;

ll n, m;
ll s[N], a[N][M];
ll f[N][M], ans;

ll calc(ll x)
{
    memset(f, 0, sizeof f);
    f[0][n] = 1;
    for (ll i = 1; i <= n; i++)
        for (ll j = n - i; j <= n + i; j++)
        {

            (f[i][j] = f[i - 1][j]) % P;
            (f[i][j] += f[i - 1][j - 1] * a[i][x] % P) %= P;
            (f[i][j] += f[i - 1][j + 1] * (s[i] - a[i][x] + P) % P) %= P;
            // printf("%d ", f[i][j]);
            // 1 1 1 2 3 3 1 0 2 1 0 2 3 3 1 0 1 1 1 1 2 3 2 1 3
            // 1 1 1 2 3 3 1 0 2 1 0 2 3 3 1 0 6
        }
    ll res = 0;
    for (ll i = 1; i <= n; i++)
        (res += f[n][n + i]) %= P;
    return res % P;
}

int main()
{
    scanf("%lld%lld", &n, &m);
    ans = 1;
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= m; j++)
            scanf("%lld", &a[i][j]), (s[i] += a[i][j]) %= P;
    for (ll i = 1; i <= n; i++)
        (ans *= (s[i] + 1)) %= P;
    ans--;
    // for (int i = 1; i <= n; i++)
    // printf("%d ", s[i]);
    for (ll i = 1; i <= m; i++)
        (ans = ans - calc(i) + P) %= P;
    printf("%lld", ans);
    return 0;
}