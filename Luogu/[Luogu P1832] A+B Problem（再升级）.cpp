#include <stdio.h>
#include <algorithm>

typedef long long ll;

const ll N = 1e3 + 5;

ll n;
ll pri[N], f[N], cnt;

bool isPrime(ll x)
{
    for (ll i = 2; i < x; i++)
        if (x % i == 0)
            return false;
    return true;
}

int main()
{
    scanf("%lld", &n);
    for (ll i = 2; i <= n; i++)
        if (isPrime(i))
            pri[++cnt] = i;
    f[0] = 1;
    for (ll i = 1; i <= cnt; i++)
        for (ll j = pri[i]; j <= n; j++)
            f[j] += f[j - pri[i]];
    printf("%lld", f[n]);
    return 0;
}