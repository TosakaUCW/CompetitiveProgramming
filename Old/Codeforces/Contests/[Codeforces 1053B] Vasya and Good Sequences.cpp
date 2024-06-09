#include <stdio.h>
#include <algorithm>

#define int long long
#define cnt(x) __builtin_popcountll(x)

const int N = 3e5 + 5;

int n, ans, a[N], sum[N], tot[2], c[N];

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

signed main()
{
    n = read(), tot[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        c[i] = read();
        a[i] = cnt(c[i]), sum[i] = sum[i - 1] + a[i], ans += tot[sum[i] % 2LL]++;
        for (int j = i, max = a[i]; j >= std::max(1LL, i - 64LL); max = std::max(max, a[--j]))
            ans -= max * 2LL > sum[i] - sum[j - 1] and sum[i] % 2LL == sum[j - 1] % 2LL;
    }
    for (int i = 1; i <= n; i++)
        printf("%lld ", c[i] * 2);
    puts("");
    for (int i = 1; i <= n; i++)
        printf("%lld ", a[i]);
    return printf("%lld", ans), 0;
}
/*
255 65535 65535 262143 4194303
*/