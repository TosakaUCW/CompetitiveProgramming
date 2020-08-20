#include <stdio.h>
#include <algorithm>

typedef long long ll;

const int N = 1e6 + 5;
const int P = 1e9 + 7;

ll T, n, m;
ll d[N], fac[N];

ll pow(ll x, ll k)
{
    ll res = 1;
    while (k)
    {
        if (k & 1)
            (res *= x) %= P;
        (x *= x) %= P;
        k >>= 1;
    }
    return res % P;
}

ll C(ll n, ll m)
{
    return fac[n] * pow(fac[m] * fac[n - m] % P, P - 2) % P;
}

int main()
{
    scanf("%lld", &T);
    d[1] = 0, d[2] = 1, fac[1] = 1, fac[2] = 2;
    for (int i = 3; i <= N - 5; i++)
        d[i] = (d[i - 1] + d[i - 2]) * (i - 1) % P, fac[i] = fac[i - 1] * i % P;
    while (T--)
    {
        scanf("%lld%lld", &n, &m);
        if (n - m == 1)
            puts("0");
        else if (m == n)
            puts("1");
        else if (m == 0)
            printf("%lld\n", d[n]);
        else
            printf("%lld\n", d[n - m] * C(n, m) % P);
    }
    return 0;
}