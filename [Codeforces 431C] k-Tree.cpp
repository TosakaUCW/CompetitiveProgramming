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

const int N = 1e2 + 5;
const int P = 1e9 + 7;

int n, k, d;
int f[N], g[N];

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif // !ONLINE_JUDGE
    n = read(), k = read(), d = read();
    f[0] = g[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = std::max(0LL, i - k); j < i; j++)
            (f[i] += f[j]) %= P;
        for (int j = std::max(0LL, i - d + 1); j < i; j++)
            (g[i] += g[j]) %= P;
    }
    return printf("%lld", (f[n] - g[n] + P) % P), 0;
}