#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

const int N = 5e5 + 5;

int n, k, ans, tot;
int a[N], b[N];

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
    n = read(), k = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    std::sort(a + 1, a + 1 + n);
    for (int i = n; i >= 1; i--)
    {
        ans += tot, tot += a[i];
        if (tot < 0)
        {
            a[i] = tot, n = i;
            break;
        }
    }
    if (a[n] < 0)
    {
        k++;
        for (int i = n; i >= 1; i--)
            ans += b[i % k], b[i % k] += a[i];
    }
    return printf("%lld", ans), 0;
}