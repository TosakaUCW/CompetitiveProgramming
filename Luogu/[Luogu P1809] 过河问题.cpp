#include <stdio.h>
#include <algorithm>

typedef long long ll;

const ll N = 1e5 + 5;

ll n, ans, a[N], f[N];

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
        a[i] = read();
    std::sort(a + 1, a + 1 + n);
    f[1] = a[1], f[2] = a[2];
    for (int i = 3; i <= n; i++)
        f[i] = std::min(f[i - 1] + a[1] + a[i], f[i - 2] + a[1] + a[i] + a[2] * 2);
    printf("%lld", f[n]);
    return 0;
}