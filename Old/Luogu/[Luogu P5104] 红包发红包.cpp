#include <stdio.h>

typedef long long ll;
#define Rep(i, x, y) for (register ll i = x; i <= y; i++)

const int P = 1e9 + 7;

ll w, n, k, ans;

ll pow(ll x, ll k)
{
    ll res = 1;
    while (k)
    {
        if (k & 1)
            res = res * x % P;
        x = x * x % P;
        k >>= 1;
    }
    return res;
}

void exgcd(ll a, ll b, ll &x, ll &y)
{
    if (!b)
        x = 1, y = 0;
    else
        exgcd(b, a % b, y, x), y -= a / b * x;
}

int main()
{
    scanf("%lld%lld%lld", &w, &n, &k);
    ll x, y;
    exgcd(pow(2, k), P, x, y);
    x = (x % P + P) % P;
    ans = (w % P) * (x % P) % P;
    printf("%lld", ans);
    return 0;
}