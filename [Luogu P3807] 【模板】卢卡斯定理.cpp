#include <stdio.h>
#include <algorithm>

typedef long long ll;

const int MAXP = 1e5 + 5;

ll n, m, P, ans;
ll fac[MAXP];

void GetFac()
{
    fac[0] = 1;
    for (ll i = 1; i <= P; i++)
        fac[i] = fac[i - 1] * i % P;
}

ll pow(ll x, ll k)
{
    ll res = 1;
    x %= P;
    while (k)
    {
        if (k & 1)
            res = res * x % P;
        x = x * x % P;
        k >>= 1;
    }
    return res;
}

ll C(ll n, ll m)
{
    if (m > n)
        return 0;
    return ((fac[n] * pow(fac[m], P - 2)) % P * pow(fac[n - m], P - 2) % P);
}

ll Lucas(ll n, ll m)
{
    if (!m)
        return 1;
    return C(n % P, m % P) * Lucas(n / P, m / P) % P;
}

int main()
{
    ll T;
    scanf("%lld", &T);
    while (T--)
    {
        scanf("%lld%lld%lld", &n, &m, &P);
        GetFac();
        ans = Lucas(n + m, std::min(n, m));
        printf("%lld\n", ans);
    }
    return 0;
}