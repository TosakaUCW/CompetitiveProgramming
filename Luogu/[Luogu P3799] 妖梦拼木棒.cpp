#include <stdio.h>
#include <algorithm>
#include <memory.h>

typedef long long ll;

const ll N = 1e5 + 5;
const ll P = 1e9 + 7;

ll n, m, ans;
ll a[N], b[N], fac[N];

ll C(ll n) { return ((n * n - n) / 2) % P; }

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
    n = read();
    for (ll i = 1; i <= n; i++)
        a[i] = read(), b[a[i]]++, m = std::max(m, a[i]);
    for (ll i = 1; i <= m; i++)
        for (ll j = i; j <= m; j++)
            if (i == j)
                (ans += C(b[i]) * C(b[i + j])) %= P;
            else
                (ans += b[j] * b[i] * C(b[i + j])) %= P;
    printf("%lld", ans % P);
    return 0;
}