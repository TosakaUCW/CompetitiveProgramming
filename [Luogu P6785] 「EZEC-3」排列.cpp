#include <stdio.h>
#include <algorithm>
#include <memory.h>

typedef long long ll;

const ll N = 1e6 + 5;

ll n, k, ans, len;
ll a[N];
bool haveAns;

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
    n = read(), k = read();
    for (ll i = 1, x, y; i <= n; i++)
        x = read(), y = read(), a[x] += y;
    if (k == 0)
        for (ll i = 0; i <= N - 5; i++)
        {
            if (a[i] < 2)
                continue;
            haveAns = true;
            ans = std::max(ans, i * a[i]);
        }
    else
        for (ll i = 0, j = k; j <= N - 5; i++, j++)
        {
            if (!a[i] or !a[j])
                continue;
            haveAns = true;
            ans = std::max(ans, (j + i) * std::min(a[i], a[j]));
        }
    if (haveAns)
        printf("%lld", ans);
    else
        puts("NO");
    return 0;
}