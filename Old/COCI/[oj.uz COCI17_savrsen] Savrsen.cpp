#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <math.h>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
    while ('0' > ch or ch > '9')
        f = ch == '-', ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + (ch ^ 48), ch = getchar();
    return f ? -x : x;
}

const int N = 1e7 + 5;

int L, R, ans, f[N];

signed main()
{
    freopen("savrsen.in", "r", stdin), freopen("savrsen.out", "w", stdout);
    L = read(), R = read();
    for (int d = 1; d <= R; d++)
        for (int x = 2LL * d; x <= R; x += d)
            f[x] -= d;
    for (int i = L; i <= R; i++)
        ans += abs(i + f[i]);
    return printf("%lld", ans), 0;
}