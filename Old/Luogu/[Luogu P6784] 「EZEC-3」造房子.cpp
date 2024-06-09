#include <stdio.h>
#include <algorithm>

typedef long long ll;

ll a, b, c, res, delta;

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
    a = read(), b = read(), c = read();
    if (a > b)
        std::swap(a, b);
    delta = b - a;
    if (c >= delta)
        c = (c - delta) / 2 + b;
    else
        c = a + c;
    for (res = 1; c - res >= 0; c -= res, res++)
        ;
    printf("%lld", res - 1);
    return 0;
}