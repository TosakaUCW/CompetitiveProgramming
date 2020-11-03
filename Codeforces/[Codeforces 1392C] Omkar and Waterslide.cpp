#include <stdio.h>
#include <algorithm>
#include <memory.h>

typedef long long ll;

const ll N = 2e5 + 5;
const ll INF = 2147483647;

ll n, ans;
ll a[N], g[N];

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
        n = read(), ans = 0;
        for (int i = 1; i <= n; i++)
            a[i] = read();
        for (int i = 2; i <= n; i++)
            if (a[i] < a[i - 1])
                ans += a[i - 1] - a[i];
        printf("%lld\n", ans);
    }
    return 0;
}