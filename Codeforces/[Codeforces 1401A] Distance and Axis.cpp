#include <stdio.h>

typedef long long ll;

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
        ll n = read(), k = read();
        if (k >= n)
            printf("%lld\n", k - n);
        else
            printf("%lld\n", (n - k) % 2);
    }
    return 0;
}