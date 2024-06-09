#include <stdio.h>

typedef long long ll;

ll a, b, x, y;

void exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b)
        x = 1, y = 0;
    else
        exgcd(b, a % b, y, x), y -= x * (a / b);
}

int main()
{
    scanf("%lld%lld", &a, &b);
    exgcd(a, b, x, y);
    x = (x % b + b) % b;
    printf("%lld",x);
    return 0;
}