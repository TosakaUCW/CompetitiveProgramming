#include <stdio.h>
#include <algorithm>

typedef long long ll;

const int N = 1e5 + 5;

ll n, m, ans, f[N];

int main()
{
    scanf("%lld%lld", &n, &m);
    if (n > m)
        std::swap(n, m);
    for (ll i = n; i; i--)
    {
        f[i] = (n / i) * (m / i);
        for (ll j = i << 1; j <= n; j += i)
            f[i] -= f[j];
        ans += f[i] * ((i << 1) - 1);
    }
    printf("%lld", ans);
    return 0;
}