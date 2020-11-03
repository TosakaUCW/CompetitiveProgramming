#include <stdio.h>
#include <algorithm>
#include <memory.h>

typedef long long ll;

const ll N = 2e5 + 5;
const ll INF = 2147483647;

ll n, k;
ll a[N], b[N], ans[N];

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
    for (ll T = read(); T--;)
    {
        ll d1 = -INF, d2 = -INF;
        n = read(), k = read();
        for (ll i = 1; i <= n; i++)
            a[i] = read(), d1 = std::max(d1, a[i]);
        for (ll i = 1; i <= n; i++)
            a[i] = d1 - a[i];
        for (ll i = 1; i <= n; i++)
            d2 = std::max(d2, a[i]);
        for (ll i = 1; i <= n; i++)
            b[i] = d2 - a[i];
        for (ll i = 1; i <= n; i++)
            printf("%lld ", k % 2 ? a[i] : b[i]);
        puts("");
    }
    return 0;
}