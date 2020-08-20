#include <stdio.h>
#include <algorithm>
#include <math.h>

typedef long long ll;

ll T;
ll a, b, c, x, y, d, k, tx, ty;

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, x, y);
    ll z = x;
    x = y, y = z - a / b * y;
    return d;
}

int main()
{
    scanf("%lld", &T);
    while (T--)
    {
        scanf("%lld%lld%lld", &a, &b, &c);
        d = exgcd(a, b, x, y);
        if (c % d)
        {
            puts("-1");
            continue;
        }
        x = x * c / d, y = y * c / d;
        tx = b / d;
        ty = a / d;
        // xmin ymax
        k = ceil((1.0 - x) / tx);
        x += k * tx, y -= k * ty;
        if (y <= 0)
        {
            ll ymin = y + 1LL * ty * ceil((1.0 - y) / ty);
            printf("%lld %lld\n", x, ymin);
        }
        else
        {
            printf("%lld ", (y - 1) / ty + 1);
            printf("%lld ", x);
            printf("%lld ", (y - 1) % ty + 1);
            printf("%lld ", x + (y - 1) / ty * tx);
            printf("%lld\n", y);
        }
    }
    return 0;
}