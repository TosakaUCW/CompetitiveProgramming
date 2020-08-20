#include <stdio.h>
#include <algorithm>

typedef long long ll;

ll k, n, a = 1;
ll ans;

int main()
{
    scanf("%lld%lld", &k, &n);
    while (n)
    {
        if (n & 1)
            ans += a;
        a *= k;
        n >>= 1;
    }
    printf("%lld", ans);
    return 0;
}