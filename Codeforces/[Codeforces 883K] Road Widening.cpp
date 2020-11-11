#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

const int N = 2e5 + 5;

int n, ans;
int f[N], g[N], sum[N];

int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

signed main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        f[i] = read(), g[i] = read(), sum[i] = f[i] + g[i];
    for (int i = 2; i <= n; i++)
        sum[i] = std::min(sum[i], sum[i - 1] + 1);
    for (int i = n - 1; i >= 1; i--)
        sum[i] = std::min(sum[i + 1] + 1, sum[i]);
    for (int i = 1; i <= n; i++)
        if (f[i] > sum[i])
            return puts("-1"), 0;
        else
            ans += sum[i] - f[i];
    printf("%lld\n", ans);
    for (int i = 1; i <= n; i++)
        printf("%lld ", sum[i]);
    return 0;
}