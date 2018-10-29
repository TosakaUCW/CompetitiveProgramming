#include <stdio.h>
#include <algorithm>

long long n, k, ans;

int main()
{
    scanf("%lld%lld", &n, &k);
    ans = n * k;
    for (long long l = 1, r; l <= n; l = r + 1)
    {
        long long x = k / l;
        if (x == 0)
            r = n;
        else
            r = std::min(k / x, n);
        ans -= (r - l + 1) * x * (l + r) / 2;
    }
    printf("%lld", ans);
    return 0;
}