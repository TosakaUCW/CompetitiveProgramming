#include <stdio.h>

typedef long long ll;

ll k, l, p, s, w;

ll pow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return res;
}

ll solve()
{
    k %= p;
    if (s == 0)
    {
        if (l == 1)
            return k;
        if (l == 2)
            return k * (k - 1) % p;
        return k * (k - 1) % p * pow(k - 2, l - 2) % p;
    }
    else
    {
        if (l == 1)
            return 1;
        if (l == 2)
            return k - 1;
        return (k - 1) * pow(k - 2, l - 2) % p;
    }
}

int main()
{
    scanf("%lld%lld%lld", &k, &l, &p);
    scanf("%lld%lld", &s, &w);
    printf("%lld", solve());
    return 0;
}