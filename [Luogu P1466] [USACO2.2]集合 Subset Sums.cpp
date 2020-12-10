#include <stdio.h>
#include <algorithm>

typedef long long ll;

const ll N = 1e5 + 5;

ll n, m;
ll f[N];

int main()
{
    scanf("%lld", &n);
    m = (n * (n + 1)) / 2;
    if (m % 2)
    {
        puts("0");
        return 0;
    }
    m /= 2;
    f[0] = 1;
    for (ll i = 1; i <= n; i++)
        for (ll j = m; j >= i; j--)
            f[j] += f[j - i];
    printf("%lld", f[m] / 2);
    return 0;
}