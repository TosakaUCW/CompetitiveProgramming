#include <stdio.h>
#include <algorithm>

typedef long long ll;

const ll N = 1e7 + 5;
const ll P = 20100403;

ll n, m;
ll fac[N];

void GetFac()
{
    fac[0] = 1;
    for (ll i = 1; i <= n + m; i++)
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
    scanf("%lld%lld", &n, &m);
    GetFac();
    printf("%lld", (Lucas(n + m, m) - Lucas(n + m, m - 1) + P) % P);
    return 0;
} // C(n + m, m) - C(n + m, m - 1)