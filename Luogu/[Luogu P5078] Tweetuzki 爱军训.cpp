#include <stdio.h>
#include <algorithm>

#define int long long

const int N = 1e6 + 5;

int n, ans, a[N], sum[N];
bool b[N];

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
        a[i] = read(), ans += i * a[i];
    for (int i = n; i >= 1; i--)
        sum[i] = sum[i + 1] + a[i];
    for (int i = 1, k; i <= n; i++)
        if ((k = (n - i) * a[i] - sum[i + 1]) > 0)
            ans += k, b[i] = true;
    printf("%lld\n", ans);
    for (int i = 1; i <= n; i++)
        if (!b[i])
            printf("%lld ", a[i]);
    for (int i = n; i >= 1; i--)
        if (b[i])
            printf("%lld ", a[i]);
    return 0;
}