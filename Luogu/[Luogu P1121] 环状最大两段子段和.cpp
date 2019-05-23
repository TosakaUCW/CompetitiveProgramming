#include <stdio.h>
#include <algorithm>

const int N = 2e5 + 5;
const int INF = 1 << 30;

long long n, ans, sum;
long long a[N], f[N], g[N];

int calc()
{
    long long res = -INF;
    f[0] = g[n + 1] = -INF;
    for (int i = 1; i <= n; i++)
        f[i] = std::max(f[i - 1] + a[i], a[i]);
    for (int i = 1; i <= n; i++)
        f[i] = std::max(f[i], f[i - 1]);
    for (int i = n; i >= 1; i--)
        g[i] = std::max(g[i + 1] + a[i], a[i]);
    for (int i = n; i >= 1; i--)
        g[i] = std::max(g[i], g[i + 1]);
    for (int i = 1; i <= n - 1; i++)
        res = std::max(res, f[i] + g[i + 1]);
    return res;
}

int main()
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]), sum += a[i];
    ans = calc();
    for (int i = 1; i <= n; i++)
        a[i] = -a[i];
    if (sum + calc())
        ans = std::max(ans, sum + calc());
    printf("%lld", ans);
    return 0;
}