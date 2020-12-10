#include <ctype.h>
#include <math.h>
#include <stdio.h>

typedef long long ll;

ll a, b, m;

ll read(ll m)
{
    register ll x = 0, f = 0;
    char ch = getchar();
    while (!isdigit(ch))
        ch = getchar();
    while (isdigit(ch))
    {
        x = x * 10 + ch - '0';
        if (x >= m)
            f = 1;
        x %= m;
        ch = getchar();
    }
    return x + (f == 1 ? m : 0);
}

ll phi(ll n)
{
    ll res = n, m = sqrt(n);
    for (ll i = 2; i <= m; i++)
        if (n % i == 0)
        {
            res = res / i * (i - 1);
            while (n % i == 0)
                n /= i;
        }
    if (n > 1)
        res = res / n * (n - 1);
    return res;
}

ll pow(ll a, ll k, ll p)
{
    ll res = 1;
    a %= p;
    while (k)
    {
        if (k & 1)
            res = res * a % p;
        a = a * a % p;
        k >>= 1;
    }
    return res;
}

int main()
{
    scanf("%lld%lld", &a, &m);
    b = read(phi(m));
    printf("%lld", pow(a, b, m));
    return 0;
}