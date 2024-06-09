#include <stdio.h>
#include <algorithm>
#include <memory.h>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

int n, k, sum;

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif // !ONLINE_JUDGE
    for (int T = read(); T--; printf("%lld\n", sum / n + (sum % n != 0)))
        n = read(), k = read(), sum = k * (n / k + (n % k != 0));
    return 0;
}