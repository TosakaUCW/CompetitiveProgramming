#include <stdio.h>
#include <algorithm>

const int N = 1e6 + 5;
const int INF = 1 << 30;

int n, ans;
int a[N], f[N], g[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    ans = f[0] = g[n + 1] = -INF;
    for (int i = 1; i <= n; i++)
        f[i] = std::max(f[i - 1] + a[i], a[i]);
    for (int i = 1; i <= n; i++)
        f[i] = std::max(f[i], f[i - 1]);
    for (int i = n; i >= 1; i--)
        g[i] = std::max(g[i + 1] + a[i], a[i]);
    for (int i = n; i >= 1; i--)
        g[i] = std::max(g[i], g[i + 1]);
    for (int i = 1; i <= n - 1; i++)
        ans = std::max(ans, f[i] + g[i + 1]);
    printf("%d", ans);
    return 0;
}