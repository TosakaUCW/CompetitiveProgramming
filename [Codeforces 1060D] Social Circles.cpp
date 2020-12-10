#include <stdio.h>
#include <algorithm>

const int N = 1e5 + 5;

int n, l[N], r[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &l[i], &r[i]);
    std::sort(l + 1, l + 1 + n);
    std::sort(r + 1, r + 1 + n);
    long long ans = n;
    for (int i = 1; i <= n; i++)
        ans += std::max(l[i], r[i]);
    printf("%lld", ans);
    return 0;
}