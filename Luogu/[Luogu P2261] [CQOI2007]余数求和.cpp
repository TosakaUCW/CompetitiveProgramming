#include <stdio.h>
#include <algorithm>

long long n, k, ans;

int main()
{
    scanf("%lld%lld", &n, &k);
    ans = n * k;
    for (long long l = 1, r; l <= n; l = r + 1)
    {
        long long t = k / l;
        if (t == 0)
            r = n;
        else
            r = std::min(k / t, n);
        ans -= t * (r - l + 1) * (l + r) / 2;
    }
    printf("%lld", ans);
    return 0;
}
