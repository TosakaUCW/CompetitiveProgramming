#include <stdio.h>
#include <algorithm>
#include <memory.h>

typedef long long ll;

const ll N = 1e6 + 5;
const ll P = 998244353;

ll n, ans;
ll a[N], b[N];

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
        a[i] = read() * i * (n - i + 1);
    for (ll i = 1; i <= n; i++)
        b[i] = read();
    std::sort(a + 1, a + 1 + n);
    std::sort(b + 1, b + 1 + n);
    std::reverse(b + 1, b + 1 + n);
    for (ll i = 1; i <= n; i++)
    {
        a[i] %= P;
        b[i] %= P;
        ans = (ans + a[i] * b[i] % P) % P;
    }
    printf("%lld", ans % P);
    return 0;
}