#include <stdio.h>
#include <algorithm>
#include <memory.h>

typedef long long ll;

const ll N = 16 + 1;

ll n, k, ans;
ll a[N], f[N][1 << N];

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
    for (ll i = 0; i < n; i++)
        a[i] = read();
    for (ll i = 0; i < n; i++)
        f[i][1 << i] = 1;
    for (ll sta = 0; sta < (1 << n); sta++)
        for (ll i = 0; i < n; i++)
        {
            if (!((1 << i) & sta))
                continue;
            for (ll j = 0; j < n; j++)
            {
                if ((1 << j) & sta)
                    continue;
                if (abs(a[j] - a[i]) > k)
                    f[j][sta | (1 << j)] += f[i][sta];
            }
        }
    for (ll i = 0; i < n; i++)
        ans += f[i][(1 << n) - 1];
    printf("%lld", ans);
    return 0;
}