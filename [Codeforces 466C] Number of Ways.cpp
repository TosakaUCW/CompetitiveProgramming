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

const int N = 5e5 + 5;

int n, ans, a[N];

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif // !ONLINE_JUDGE
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = a[i - 1] + read();
    if (a[n] % 3)
        return puts("0"), 0;
    for (int i = 1, tot = 0; i <= n; i++)
    {
        if (i ^ 1 and i ^ n and a[i] == a[n] * 2 / 3)
            ans += tot;
        if (a[i] == a[n] / 3)
            tot++;
    }
    return printf("%lld", ans), 0;
}