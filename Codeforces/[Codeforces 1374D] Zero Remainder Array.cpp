#include <stdio.h>
#include <algorithm>
#include <map>

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        long long n, k, ans = 0;
        scanf("%lld%lld", &n, &k);
        std::map<long long, long long> a;
        for (int i = 1; i <= n; i++)
        {
            long long x;
            scanf("%lld", &x);
            x %= k;
            if (x == 0)
                continue;
            a[x]++;
            ans = std::max(ans, a[x] * k - x);
        }
        printf("%lld\n", ans ? ans + 1 : ans);
    }
    return 0;
}