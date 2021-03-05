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

signed main()
{
    freopen("uzastopni.in", "r", stdin), freopen("uzastopni.out", "w", stdout);
    int n = read() * 2;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
        {
            int tmp = n / i;
            if (i % 2 == tmp % 2)
                continue;
            int x = (tmp - i + 1) / 2;
            printf("%lld %lld\n", x, x + i - 1);
        }
    return 0;
}