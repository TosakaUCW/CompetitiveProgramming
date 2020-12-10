#include <stdio.h>
#include <algorithm>

typedef long long ll;

const ll N = 1e7 + 5;

ll n, m, tot;
ll num[N], pri[N], f[N];

int main()
{
    scanf("%lld%lld", &n, &m);
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &num[i]);
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &pri[i]), tot += num[i] * pri[i];
    f[0] = 1;
    for (ll i = 1; i <= n; i++)
        for (ll j = tot; j; j--)
            for (ll k = 1; k <= num[i] and k * pri[i] <= j; k++)
                f[j] = std::max(f[j], f[j - k * pri[i]] * k);
    for (ll i = 0; i <= tot; i++)
        if (f[i] >= m)
        {
            printf("%lld", i);
            return 0;
        }
    return 0;
}