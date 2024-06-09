#include <stdio.h>
#include <algorithm>
#include <math.h>

typedef long long ll;

ll tmp[6];
ll a, b, c, x, y, d, tx, k;

ll exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    ll d = exgcd(b, a % b, x, y);
    int t = x;
    x = y, y = t - a / b * y;
    return d;
}

void read()
{
    for (int i = 1; i <= 5; i++)
        scanf("%lld", &tmp[i]);
    a = tmp[4] - tmp[3];
    b = tmp[5];
    c = tmp[1] - tmp[2];
}

int main()
{
    read();
    if (a < 0)
        c = -c, a = -a;
    d = exgcd(a, b, x, y);
    if (c % d)
    {
        puts("Impossible");
        return 0;
    }
    x = x * c / d,
    tx = b / d;
    printf("%lld", (x % tx + tx) % tx);
    return 0;
}