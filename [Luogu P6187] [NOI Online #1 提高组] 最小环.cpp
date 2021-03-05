#include <stdio.h>
#include <algorithm>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 2e5 + 5;

int n, m, a[N], f[N];

int solve(int k, int ans = 0)
{
    if (k == 0 or n == 1)
    {
        for (int i = 1; i <= n; i++)
            ans += a[i] * a[i];
        return ans;
    }
    int t = std::__gcd(n, k), p = n / t;
    if (f[p])
        return f[p];
    for (int i = 1; i <= n; i += p)
    {
        for (int j = 0; j <= p - 3; j++)
            ans += a[i + j] * a[i + j + 2];
        ans += a[i] * a[i + 1] + a[i + p - 1] * a[i + p - 2];
    }
    return f[p] = ans;
}

signed main()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    std::sort(a + 1, a + 1 + n);
    while (m--)
        printf("%lld\n", solve(read()));
    return 0;
}